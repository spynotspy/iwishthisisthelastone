//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_REVERSEWORDSORDER_H
#define MAIN_C_REVERSEWORDSORDER_H

#include "../string_.h"
#include "changeW1ToW2.h"

void reverseWordsOrder(char *s) {
    char *endS = getEndOfString(s);
    copy(s, endS, stringBuffer_);
    char *begin = stringBuffer_;
    char *recPtr = s;
    char *end = begin + (endS - s);
    *end = '\0';

    getBagOfWords(&_bag, stringBuffer_);

    int size = 1;
    while (size <= _bag.size) {
        WordDescriptor *wordInBag = _bag.words + _bag.size - size;
        copy(wordInBag->begin, wordInBag->end, recPtr);
        recPtr += wordInBag->end - wordInBag->begin;
        *recPtr++ = ' ';
        size++;
    }
    *--recPtr = '\0';
}

#endif //MAIN_C_REVERSEWORDSORDER_H
