//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_GETLASTWORDFROMROW1THATINROW2_H
#define MAIN_C_GETLASTWORDFROMROW1THATINROW2_H

#include "../string_.h"

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}

//Даны две строки. Определить последнее из слов первой строки, которое есть
//во второй строке.
WordDescriptor getLastWordFromRow1ThatInRow2(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    WordDescriptor word;
    for (int i = _bag.size - 1; i >= 0; --i) {
        for (int j = 0; j < _bag2.size; ++j) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                word = _bag.words[i];
                return word;
            }
        }
    }
    word = (WordDescriptor) {NULL, NULL};
    return word;
}

#endif //MAIN_C_GETLASTWORDFROMROW1THATINROW2_H
