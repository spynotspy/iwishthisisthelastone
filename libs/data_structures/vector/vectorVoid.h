//
// Created by Dima on 06.02.2022.
//

#ifndef INC_5B_VECTORVOID_H
#define INC_5B_VECTORVOID_H

#include <stdbool.h>
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

//возвращает 1, если вектор пуст
bool isEmptyV(vectorVoid *v);

//возвращает 1, если вектор полон
bool isFullV(vectorVoid *v);

//записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

//удаляет последний элемент из вектора v
void popBackV(vectorVoid *v);

//добавляет элемент х в конец вектора v
void pushBackV(vectorVoid *v, int x);

#endif //INC_5B_VECTORVOID_H
