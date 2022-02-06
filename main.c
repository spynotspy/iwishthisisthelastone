#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.data[0] == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(3);
    v.size = 3;
    v.data[0] = 1;
    v.data[1] = 2;
    v.data[2] = 3;
    pushBack(&v, 4);
    assert(v.data[3] == 4);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    int *p = atVector(&v, 2);
    assert(p == v.data + 2);
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    size_t indexLast = v.size - 1;
    int *p = atVector(&v, indexLast);
    assert(p == v.data + indexLast);
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    int *p = back(&v);
    assert(p == v.data + v.size - 1);
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    int *p = front(&v);
    assert(p == v.data);
    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    //test();
    size_t n = 5;
    vectorVoid v = {(void *) malloc(sizeof(float) * n), 0, n, sizeof(float)};


    int q = sizeof(int);
    int w = sizeof(float);
    printf("%d %d", q, w);

    return 0;
}
