//
// Created by Dima on 09.02.2022.
//
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
    m.nRows = 0;
    m.nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}


void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {

    int resCriteria[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        resCriteria[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int t = resCriteria[i];
        int j = i;
        while (j > 0 && resCriteria[j - 1] > t) {
            resCriteria[j] = resCriteria[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resCriteria[j] = t;
    }
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                          float (*criteria)(int *, int)) {

    float resCriteria[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        resCriteria[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        float t = resCriteria[i];
        int j = i;
        while (j > 0 && resCriteria[j - 1] > t) {
            resCriteria[j] = resCriteria[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resCriteria[j] = t;
    }
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int resCriteria[m.nCols];
    int copyColumn[m.nRows];
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j) {
            copyColumn[j] = m.values[j][i];
        }
        resCriteria[i] = criteria(copyColumn, m.nRows);
    }
    for (int i = 1; i < m.nCols; i++) {
        int t = resCriteria[i];
        int j = i;
        while (j > 0 && resCriteria[j - 1] > t) {
            resCriteria[j] = resCriteria[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        resCriteria[j] = t;
    }
}


bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    else
        for (size_t i = 0; i < m1.nRows; i++) {
            if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
                return false;
        }

    return true;
}

bool isEMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (!(i == j && m.values[i][j] == 1 || m.values[i][j] == 0))
                return false;
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i != j && m.values[i][j] != m.values[j][i])
                return false;
        }
    }
    return true;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(&m.values[i][j], &m.values[j][i]);
        }
    }
}

position getMinValuePos(matrix m) {
    position curMinPos = {0, 0};
    int curMin = m.values[0][0];
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] < curMin) {
                curMin = m.values[i][j];
                curMinPos.rowIndex = i;
                curMinPos.colIndex = j;
            }
        }
    }
    return curMinPos;
}

position getMaxValuePos(matrix m) {
    position curMaxPos = {0, 0};
    int curMax = m.values[0][0];
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] > curMax) {
                curMax = m.values[i][j];
                curMaxPos.rowIndex = i;
                curMaxPos.colIndex = j;
            }
        }
    }
    return curMaxPos;
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices, size_t nRows, size_t nCols) {

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void swapRowsWithMaxAndMinValues(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

int getMax(int *a, int n) {
    int firstIndexMax = 0;
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max) {
            firstIndexMax = i;
            max = a[i];
        }
    }
    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, int n) {
    int firstIndexMin = 0;
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min) {
            firstIndexMin = i;
            min = a[i];
        }
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; ++j) {
            m3.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; ++k) {
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumRows[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        sumRows[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(sumRows, m.nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    return isEMatrix(m3);
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int size = m.nRows + m.nCols - 1;
    int pseudoDiagonalElements[size];
    for (int i = 0; i < size; ++i) {
        pseudoDiagonalElements[i] = INT_MIN;
    }
    pseudoDiagonalElements[m.nCols - m.nRows + 1] = 0; // элемент главной диагонали 0, чтобы не влиять на сумму
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i != j) {
                int k = j - i + m.nCols - m.nRows + 1;
                pseudoDiagonalElements[k] = max(pseudoDiagonalElements[k], m.values[i][j]);
            }
        }
    }
    return getSum(pseudoDiagonalElements, size);
}

int getMinInArea(matrix m) {
    int min;
    position maxPos = getMaxValuePos(m);
    int leftBorder = maxPos.colIndex;
    int rightBorder = maxPos.colIndex;
    for (int i = maxPos.rowIndex; i >= 0; --i) {
        if (leftBorder != 0)
            leftBorder--;
        if (rightBorder != m.nCols - 1)
            rightBorder++;
        min = getMin(m.values[i], rightBorder - leftBorder);
    }
    return min;
}

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; ++i) {
        distance += a[i] * a[i];
    }
    return sqrt(distance);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            count++;
    }
    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumOfRows[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        sumOfRows[i] = getSum(m.values[i], m.nCols);
    }
    return countNUnique(sumOfRows, m.nRows);
}

int getNSpecialElement(matrix m) {
    int countSpecial = 0;
    for (int i = 0; i < m.nCols; ++i) {
        int sumOfCols = 0;
        int maxElemInColumn = INT_MIN;
        for (int j = 0; j < m.nRows; ++j) {
            sumOfCols += m.values[j][i];
            maxElemInColumn = max(maxElemInColumn, m.values[j][i]);
        }
        if (sumOfCols - maxElemInColumn < maxElemInColumn)
            countSpecial++;
    }
    return countSpecial;
}

position getLeftMin(matrix m) {
    position curMinPos = {0, 0};
    int curMin = m.values[0][0];
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j) {
            if (m.values[j][i] < curMin) {
                curMin = m.values[j][i];
                curMinPos.rowIndex = j;
                curMinPos.colIndex = i;
            }
        }
    }
    return curMinPos;
}

void swapPenultimateRow(matrix m) {
    position minElemPos = getLeftMin(m);

    int minColElems[m.nRows];
    for (int i = 0; i < m.nRows; ++i)
        minColElems[i] = m.values[i][minElemPos.colIndex];

    for (int i = 0; i < m.nRows; ++i)
        m.values[m.nRows - 2][i] = minColElems[i];

}

bool isNonDescendingSorted(int *a, int n){
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m){
    for (int i = 0; i < m.nRows; ++i) {
        if (isNonDescendingSorted(m.values[i],m.nCols) == false)
            return false;
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){
    int count = 0;
    for (int i = 0; i < nMatrix; ++i) {
        if (hasAllNonDescendingRows(ms[i]) == true)
            count++;
    }
    return count;
}