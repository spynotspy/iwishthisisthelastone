//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_HASEQUALWORDSINSTRING_H
#define MAIN_C_HASEQUALWORDSINSTRING_H

#include "../string_.h"

//Определить, есть ли в данной строке одинаковые слова
bool hasEqualWordsInString(char *s) {
    getBagOfWords(&_bag, s);

    WordDescriptor *endWord = _bag.words + _bag.size;
    for (WordDescriptor *curWord = _bag.words; curWord < endWord; curWord++)
        for (WordDescriptor *searchWord = curWord + 1; searchWord < endWord; searchWord++)
            if (areWordsEqual(*curWord, *searchWord) == 0)
                return true;

    return false;
}

#endif //MAIN_C_HASEQUALWORDSINSTRING_H
