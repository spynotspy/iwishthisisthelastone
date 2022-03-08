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
    WordDescriptor *endOfArray1 = _bag.words + _bag.size;
    WordDescriptor *endOfArray2 = _bag2.words + _bag2.size;

    for (WordDescriptor *wordFromRow1 = endOfArray1; wordFromRow1 != _bag.words; wordFromRow1--) {
        for (WordDescriptor *wordFromRow2 = _bag2.words; wordFromRow2 != endOfArray2; ++wordFromRow2) {
            if (areWordsEqual(*wordFromRow1, *wordFromRow2) == 0) {
                word = *wordFromRow1;
                return word;
            }
        }
    }
    word = (WordDescriptor) {NULL, NULL};
    return word;
}

#endif //MAIN_C_GETLASTWORDFROMROW1THATINROW2_H
