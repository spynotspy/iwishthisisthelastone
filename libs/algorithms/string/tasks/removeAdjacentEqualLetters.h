//
// Created by Dima on 01.03.2022.
//

#ifndef MAIN_C_REMOVEADJACENTEQUALLETTERS_H
#define MAIN_C_REMOVEADJACENTEQUALLETTERS_H

#include "../string_.h"

void removeAdjacentEqualLetters(char *s) {
    char symbol = *s;
    char *newStringEnd = s + 1;
    char *search = newStringEnd;
    while (*search != '\0') {
        if (symbol != *search) {
            *newStringEnd = *search;
            symbol = *search;
            newStringEnd++;
        }
        search++;
    }
    *newStringEnd = '\0';
}

#endif //MAIN_C_REMOVEADJACENTEQUALLETTERS_H
