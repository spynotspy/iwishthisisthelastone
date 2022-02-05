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
void deleteVector(vector *v);

//возвращает 1, если вектор пуст
bool isEmpty(vector *v);

//возвращает 1, если вектор полон
bool isFull(vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент х в конец вектора v
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора
int *atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора v
int *back(vector *v);

//возвращает указатель на нулевой элемент вектора v
int *front(vector *v);


#endif //INC_5B_VECTOR_H
