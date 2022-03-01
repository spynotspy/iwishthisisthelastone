//
// Created by Dima on 01.03.2022.
//

#ifndef MAIN_C_REMOVENONLETTERS_H
#define MAIN_C_REMOVENONLETTERS_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

#endif //MAIN_C_REMOVENONLETTERS_H
