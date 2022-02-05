//
// Created by Dima on 06.02.2022.
//

#ifndef INC_5B_VECTOR_H
#define INC_5B_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор v из n значений.
vector createVector(size_t n);

//изменяет количество newCapacity памяти, выделенное под хранение элементов вектора v.
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера вектора v, но не освобождает выделенную память.
void clear(vector *v);

//освобождает память вектора v, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору v.
void deleteVector(vector*v);

#endif //INC_5B_VECTOR_H
