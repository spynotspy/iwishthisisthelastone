//
// Created by Dima on 06.02.2022.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#include "vector.h"

vector createVector(size_t n) {
    vector v = {(int *) (malloc(sizeof(int) * n)), 0, n};
    if (n == 0)
        v.data = NULL;
    else if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, v->capacity + 1);
        v->data[v->size] = x;
        v->size++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
        v->data[v->size] = x;
        v->size++;
    } else {
        v->data[v->size] = x;
        v->size++;
    }
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "nothing to delete");
        exit(1);
    } else
        v->size--;
}

int *atVector(vector *v, size_t index) {
    if (isEmpty(v) || index < 0 || index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exist", index);
        exit(1);
    }

    return v->data + index;
}

int *back(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "IndexError: empty vector");
        exit(1);
    }
    size_t indexLast = v->size - 1;

    return atVector(v, indexLast);
}

int *front(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "IndexError: empty vector");
        exit(1);
    }
    return atVector(v, 0);
}
