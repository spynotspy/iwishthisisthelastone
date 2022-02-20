#include "test_matrix.h"

void test_swapRowsWithMaxAndMinValues_oneMinAndMax() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    swapRowsWithMaxAndMinValues(m);

    assert(m.values[0][0] == 7);

    freeMemMatrix(m);
}

void test_swapRowsWithMaxAndMinValues_multiMinAndMax() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              4, 5, 6,
                                              9, 9, 9}, 3, 3);

    swapRowsWithMaxAndMinValues(m);

    assert(m.values[0][0] == 9);

    freeMemMatrix(m);
}

void test_swapRowsWithMaxAndMinValues() {
    test_swapRowsWithMaxAndMinValues_oneMinAndMax();
    test_swapRowsWithMaxAndMinValues_multiMinAndMax();
}

void test_sortRowsByMaxElement() {
    matrix m = createMatrixFromArray((int[]) {10, 10, 10,
                                              4, 5, 6,
                                              9, 9, 9}, 3, 3);

    sortRowsByMaxElement(m);

    assert(m.values[0][0] == 4);

    freeMemMatrix(m);
}

void test_sortColsByMinElement() {
    matrix m = createMatrixFromArray((int[]) {10, 9, 1,
                                              4, 5, 6,
                                              9, 9, 9}, 3, 3);

    sortColsByMinElement(m);

    assert(m.values[0][0] == 1);

    freeMemMatrix(m);
}

void test_getSquareOfMatrixIfSymmetric_symmetric() {
    matrix m = createMatrixFromArray((int[]) {10, 0, 0,
                                              0, 5, 0,
                                              0, 0, 9}, 3, 3);


    getSquareOfMatrixIfSymmetric(&m);

    assert(m.values[0][0] == 100);

    freeMemMatrix(m);
}

void test_getSquareOfMatrixIfSymmetric_notSymmetric() {
    matrix m = createMatrixFromArray((int[]) {42, 42, 0,
                                              0, 42, 0,
                                              0, 1, 42}, 3, 3);


    getSquareOfMatrixIfSymmetric(&m);

    assert(m.values[0][0] == 42);

    freeMemMatrix(m);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_symmetric();
    test_getSquareOfMatrixIfSymmetric_notSymmetric();
}

void test_transposeIfMatrixHasNotEqualSumOfRows_equalSumOfRows() {
    matrix m = createMatrixFromArray((int[]) {42, 42, 0,
                                              0, 42, 0,
                                              0, 1, 42}, 3, 3);


    transposeIfMatrixHasNotEqualSumOfRows(m);

    assert(m.values[1][0] == 42);

    freeMemMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_notEqualSumOfRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              6, 0, 0,
                                              2, 2, 2}, 3, 3);


    transposeIfMatrixHasNotEqualSumOfRows(m);

    assert(m.values[0][0] == 1);

    freeMemMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_equalSumOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows_notEqualSumOfRows();
}

void test_isMutuallyInverseMatrices_mutuallyInverse() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3}, 2, 2);


    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_notMutuallyInverse() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {212, -212, 4242,
                                               425, 212, 19,
                                               20, 2, 2022}, 3, 3);


    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_mutuallyInverse();
    test_isMutuallyInverseMatrices_notMutuallyInverse();
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);

    freeMemMatrix(m);
}

void test_getMinInArea() {
    matrix m = createMatrixFromArray((int[]) {
            10, 7, 5, 6,
            3, 11, 8, 9,
            4, 1, 12, 2
    }, 3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_sortByDistances_2D() {
    matrix m = createMatrixFromArray((int[]) {10, 20,
                                              3, 4,
                                              5, 6,
                                              0, 0,}, 4, 2);

    sortByDistances(m);

    assert(m.values[0][0] == 0);

    freeMemMatrix(m);
}

void test_sortByDistances_3D() {
    matrix m = createMatrixFromArray((int[]) {10, 20, 30,
                                              1, 1, 1,
                                              10, 20, 30,
                                              0, 0, 0}, 4, 3);

    sortByDistances(m);

    assert(m.values[0][0] == 0);

    freeMemMatrix(m);
}

void test_sortByDistances() {
    test_sortByDistances_2D();
    test_sortByDistances_3D();
}

void test_countEqClassesByRowsSum() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              20, 0,
                                              0, 0,
                                              4, 4,
                                              10, 10}, 5, 2);

    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}

void test_getNSpecialElement() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              20, 0,
                                              0, 0,
                                              4, 4,
                                              10, 10}, 5, 2);
    assert(getNSpecialElement(m) == 1);

    freeMemMatrix(m);
}

void test_swapPenultimateRow() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1}, 3, 3);
    swapPenultimateRow(m);

    assert(m.values[m.nRows - 2][0] == 1 && m.values[m.nRows - 2][1] == 4 && m.values[m.nRows - 2][2] == 7);

    freeMemMatrix(m);
}

void test_matrix() {
    test_swapRowsWithMaxAndMinValues();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_getSquareOfMatrixIfSymmetric();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();

}