//
// Created by Dima on 02.03.2022.
//

#ifndef MAIN_C_EVERYWORDREVERSED_H
#define MAIN_C_EVERYWORDREVERSED_H

#include "../string_.h"


void reverseWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 stringBuffer_);
    copyReverse(endStringBuffer - 1, stringBuffer_ - 1, word.begin);
}

void everyWordReversed(char *begin) {
    char *beginSearch = begin;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        reverseWord(word);
        beginSearch = word.end;
    }
}

#endif //MAIN_C_EVERYWORDREVERSED_H
