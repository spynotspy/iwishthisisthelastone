//
// Created by Dima on 27.02.2022.
//
#include "tasks.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;
    return s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void removeAdjacentEqualLetters(char *s) {
    char *beginSource = s;
    int mover = 0;
    while (*s != '\0') {
        if (*s != *(s + 1)) {
            *(beginSource + mover) = *s;
            mover++;
        }
        s++;
    }

    s = beginSource;
    *(s + mover) = '\0';
}