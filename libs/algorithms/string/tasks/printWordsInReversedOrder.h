//
// Created by Dima on 07.03.2022.
//

#ifndef MAIN_C_PRINTWORDSINREVERSEDORDER_H
#define MAIN_C_PRINTWORDSINREVERSEDORDER_H

#include "../string_.h"

void outputWord(WordDescriptor word) {
    while (word.begin != word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }
    printf("\n");
}
//Вывести слова данной строки в обратном порядке по одному в строке экрана.
void printWordsInReversedOrder(char *s) {
    getBagOfWords(&_bag, s);
    int size = 1;

    if (_bag.size) {
        while (size != _bag.size) {
            WordDescriptor *endOfArray = _bag.words + _bag.size - size;
            size++;
            *endOfArray->end = '\0';
            outputWord(*endOfArray);
        }
        outputWord(*_bag.words);
    }
}

#endif //MAIN_C_PRINTWORDSINREVERSEDORDER_H
