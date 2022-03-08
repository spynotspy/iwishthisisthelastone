//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_ISTWOWORDSWITHSAMELETTERSINSTRING_H
#define MAIN_C_ISTWOWORDSWITHSAMELETTERSINSTRING_H

#include "../string_.h"
#include "hasEqualWordsInString.h"

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}


bool isTwoWordsWithSameLettersInString(char *s) {
    *copy(s, getEndOfString(s), stringBuffer_) = '\0';

    getBagOfWords(&_bag, stringBuffer_);

    WordDescriptor *end = _bag.words + _bag.size;

    for (WordDescriptor *word = _bag.words; word < end; ++word) {
        qsort(word->begin, word->end - word->begin, sizeof(char), cmp);
    }

    return hasEqualWordsInString(stringBuffer_);

}

#endif //MAIN_C_ISTWOWORDSWITHSAMELETTERSINSTRING_H
