//
// Created by Dima on 02.03.2022.
//

#ifndef MAIN_C_EVERYWORDREVERSED_H
#define MAIN_C_EVERYWORDREVERSED_H

#include "../string_.h"


//void reverseWord(WordDescriptor word) {
//    char *endStringBuffer = copy(word.begin, word.end,
//                                 stringBuffer_);
//    copyReverse(endStringBuffer - 1, stringBuffer_ - 1, word.begin);
//}


void swapChar(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}


void reverseWord_v2(WordDescriptor word) {
    char *beginReversedWord = word.begin;
    char *endReversedWord = word.end;
    word.end--;

    while (word.end - word.begin >= 1) {
        swapChar(word.begin, word.end);
        word.begin++;
        word.end--;
    }
    word.begin = beginReversedWord;
    word.end = endReversedWord;
}

void everyWordReversed(char *begin) {
    char *beginSearch = begin;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        reverseWord_v2(word);
        beginSearch = word.end;
    }
}

#endif //MAIN_C_EVERYWORDREVERSED_H
