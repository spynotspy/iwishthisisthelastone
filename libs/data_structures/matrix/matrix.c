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
        for (int i = 0; i < m1.nRows; ++i) {
            for (int j = 0; j < m1.nCols; ++j) {
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
            }
        }
    return true;
}

bool isEMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (!(i == j && m.values[i][j] || m.values[i][j] == 0))
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
