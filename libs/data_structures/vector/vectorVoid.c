//
// Created by Dima on 06.02.2022.
//
#include <stdio.h>
#include <string.h>
#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v = {(void *) (malloc(baseTypeSize * n)), 0, n};
    if (n == 0)
        v.data = NULL;
    else if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = (void *) realloc(v->data, v->baseTypeSize * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "wrong index");
        exit(1);
    }
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "wrong index");
        exit(1);
    }
    char *pElement = (char *) v->data + index * v->baseTypeSize;
    memcpy(pElement, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "nothing to delete");
        exit(1);
    } else
        v->size--;
}

void pushBackV(vectorVoid *v, int x) {
    if (v->capacity == 0) {
        reserveV(v, v->capacity + 1);
        char *source = (char *) v->data + v->size * v->baseTypeSize;
        memcpy(source, &x, v->baseTypeSize);
        v->size++;
    } else if (isFullV(v)) {
        reserveV(v, v->capacity * 2);
        char *source = (char *) v->data + v->size * v->baseTypeSize;
        memcpy(source, &x, v->baseTypeSize);
        v->size++;
    } else {
        char *source = (char *) v->data + v->size * v->baseTypeSize;
        memcpy(source, &x, v->baseTypeSize);
        v->size++;
    }
}