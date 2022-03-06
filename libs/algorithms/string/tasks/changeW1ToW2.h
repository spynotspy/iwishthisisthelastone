//
// Created by Dima on 06.03.2022.
//

#ifndef MAIN_C_CHANGEW1TOW2_H
#define MAIN_C_CHANGEW1TOW2_H

#include "../string_.h"

//dima nasty  "dima dima didi" -> "nasty nasty didi"

int wordSize(WordDescriptor w) {
    return w.end - w.begin;
}

bool isEqualWords(WordDescriptor w1, size_t w1Size, WordDescriptor w2, size_t w2Size) {
    if (w1Size != w2Size) return false;
    char *beginW1 = w1.begin;
    char *beginW2 = w2.begin;

    while (*w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }
    int howMuchSymbolsLeft = w1.end - w1.begin;
    w1.begin = beginW1;
    w2.begin = beginW2;

    return howMuchSymbolsLeft == w1Size;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer_);
        readPtr = stringBuffer_;
        recPtr = source;
    }

    // продолжение функции
}

#endif //MAIN_C_CHANGEW1TOW2_H
