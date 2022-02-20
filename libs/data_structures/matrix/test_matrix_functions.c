//
// Created by Dima on 20.02.2022.
//
#include "test_matrix_functions.h"


void test_getMemMatrix() {
    matrix m = getMemMatrix(2, 3);
    assert(m.values != NULL && m.nRows == 2 && m.nCols == 3);
    freeMemMatrix(m);
}

void test_getMemArrayOfMatrices() {
    matrix *m = getMemArrayOfMatrices(3, 2, 3);
    assert(m != NULL);
    for (int i = 0; i < 3; ++i) {
        assert(m[i].values != NULL && m[i].nRows == 2 && m[i].nCols == 3);
    }
    freeMemMatrices(m, 3);
}


void test_swapRows_twoRows() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1,
                     2, 2},
            2, 2);
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 2);
    freeMemMatrix(m);
}

void test_swapRows_multiplyRows() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1,
                     2, 2,
                     3, 3,
                     4, 4},
            4, 2);
    swapRows(m, 0, 3);
    assert(m.values[0][0] == 4);
    freeMemMatrix(m);
}


void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray((int[]) {1, 1,
                                              -1, -1,
                                              -1, 1,},
                                     3, 2);
    insertionSortRowsMatrixByRowCriteria(m, negativeElementsCount);
    assert(m.values[1][0] == -1 && m.values[1][1] == 1);
    freeMemMatrix(m);
}

void test_swapRows() {
    test_swapRows_twoRows();
    test_swapRows_multiplyRows();
}

void test_swapColumns_twoColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,
                     1, 2,
            },
            2, 2);
    swapColumns(m, 0, 1);
    assert(m.values[0][0] == 2);
    freeMemMatrix(m);
}

void test_swapColumns_multiplyColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     1, 2, 3
            },
            2, 3);
    swapColumns(m, 0, 2);
    assert(m.values[0][0] == 3);
    freeMemMatrix(m);
}

void test_swapColumns() {
    test_swapColumns_twoColumns();
    test_swapColumns_multiplyColumns();
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray((int[]) {1, -1, 1,
                                              -1, -1, 1,
                                     },
                                     2, 3);
    insertionSortColsMatrixByColCriteria(m, negativeElementsCount);
    assert(m.values[0][0] == 1 && m.values[1][0] == 1);
    freeMemMatrix(m);
}

void test_isSquareMatrix_squareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            }, 2, 2);
    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix_notSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, -1, 1,
                                              -1, -1, 1,
                                     },
                                     2, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_squareMatrix();
    test_isSquareMatrix_notSquareMatrix();
}

void test_areTwoMatricesEqual_equal() {
    matrix m1 = createMatrixFromArray((int[]) {1, -1, 1,
                                               -1, -1, 1,
                                      },
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, -1, 1,
                                               -1, -1, 1,
                                      },
                                      2, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_areTwoMatricesEqual_notEqual() {
    matrix m1 = createMatrixFromArray((int[]) {0, 0, 0,
                                               0, 0, 0,
                                      },
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 1, 1,
                                               1, 1, 1,
                                      },
                                      2, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_equal();
    test_areTwoMatricesEqual_notEqual();
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 0,
                     0, 1,
            },
            2, 2);
    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_notEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1,
                     1, 1,
            },
            2, 2);
    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix() {
    test_isEMatrix_EMatrix();
    test_isEMatrix_notEMatrix();
}

void test_isSymmetricMatrix_symmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1,
                     1, 1,
            },
            2, 2);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_notSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 50,
                     20, 1,
            },
            2, 2);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symmetricMatrix();
    test_isSymmetricMatrix_notSymmetricMatrix();
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,
                     3, 4,
            },
            2, 2);
    transposeSquareMatrix(m);
    assert(m.values[1][0] == 2);
    freeMemMatrix(m);
}

void test_getMinValuePos_oneMin() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,
                     3, 4,
            },
            2, 2);
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == 0 && minPos.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMinValuePos_manyMin() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,
                     0, 0,
            },
            2, 2);
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == 1 && minPos.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMinValuePos() {
    test_getMinValuePos_oneMin();
    test_getMinValuePos_manyMin();
}

void test_getMaxValuePos_oneMax() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,
                     3, 4,
            },
            2, 2);
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == 1 && maxPos.colIndex == 1);
    freeMemMatrix(m);
}

void test_getMaxValuePos_manyMax() {
    matrix m = createMatrixFromArray(
            (int[]) {2, 2,
                     0, 0,
            },
            2, 2);
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == 0 && maxPos.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_oneMax();
    test_getMaxValuePos_manyMax();
}

void test_matrix_functions() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}