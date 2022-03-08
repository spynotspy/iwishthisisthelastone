//
// Created by Dima on 06.03.2022.
//

#ifndef MAIN_C_CHANGEW1TOW2_H
#define MAIN_C_CHANGEW1TOW2_H

#include "../string_.h"
#include "areWordsOrdered.h"


//Заменить все вхождения слова 𝑤1 на слово 𝑤2.
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

    WordDescriptor searchingWord;

    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            getWord(readPtr, &searchingWord);
            if (getWord(readPtr, &searchingWord)
                && areWordsEqual(word1, searchingWord) <= 0) {

                copy(word2.begin, word2.end, recPtr);
                recPtr += w2Size;
                readPtr += w1Size;
            }

        }
        *recPtr++ = *readPtr++;
    }
    *recPtr = '\0';
}

#endif //MAIN_C_CHANGEW1TOW2_H
