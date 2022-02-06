//
// Created by Dima on 06.02.2022.
//

#ifndef INC_5B_VECTORVOID_H
#define INC_5B_VECTORVOID_H

#include <stdlib.h>

typedef struct vectorVoid {
    void *data;               // указатель на нулевой элемент вектора
    size_t size;              // размер вектора
    size_t capacity;          // вместимость вектора
    size_t baseTypeSize;      // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

//возвращает структуру-дескриптор вектор v из n значений, для каждого из которых выделено baseTypeSize байт памяти.
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//изменяет количество newCapacity памяти, выделенное под хранение элементов вектора v.
void reserveV(vectorVoid *v, size_t newCapacity);

//удаляет элементы из контейнера вектора v, но не освобождает выделенную память.
void shrinkToFitV(vectorVoid *v);

//освобождает память вектора v, выделенную под неиспользуемые элементы.
void clearV(vectorVoid *v);

//освобождает память, выделенную вектору v.
void deleteVectorV(vectorVoid *v);


#endif //INC_5B_VECTORVOID_H
