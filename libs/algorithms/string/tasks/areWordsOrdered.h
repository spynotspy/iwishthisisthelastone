//
// Created by Dima on 07.03.2022.
//

#ifndef MAIN_C_AREWORDSORDERED_H
#define MAIN_C_AREWORDSORDERED_H

#include "../string_.h"

//int areWordsEqual(WordDescriptor w1,
//                  WordDescriptor w2) {
//    return strcmp(w1.begin, w2.begin);
//}

//Определить, упорядочены ли лексикографически слова данного предложения
bool areWordsOrdered(char *source) {
    char *beginSearch = source;
    WordDescriptor previous;
    WordDescriptor current;
    if (getWord(beginSearch, &previous) == 0)
        return true;

    while (getWord(beginSearch, &current)) {
        if (areWordsEqual(previous, current) > 0)
            return false;
        previous = current;
        beginSearch = current.end;
    }
    return true;
}

#endif //MAIN_C_AREWORDSORDERED_H
