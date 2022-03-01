//
// Created by Dima on 01.03.2022.
//

#ifndef MAIN_C_REMOVEADJACENTEQUALLETTERS_H
#define MAIN_C_REMOVEADJACENTEQUALLETTERS_H

#include "../string_.h"

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

#endif //MAIN_C_REMOVEADJACENTEQUALLETTERS_H
