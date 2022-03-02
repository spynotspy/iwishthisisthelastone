//
// Created by Dima on 02.03.2022.
//

#ifndef MAIN_C_CHANGENUMBERSTOSPACES_H
#define MAIN_C_CHANGENUMBERSTOSPACES_H

#include "../string_.h"

char *makeSpaces(char *begin, int amountSpaces) {
    for (int i = 0; i < amountSpaces; ++i) {
        *begin = ' ';
        begin++;
    }
    return begin;
}

void changeNumbersToSpaces(char *s) {
    char *endString = getEndOfString(s);
    char *readPtr = copy(s, endString, stringBuffer_);


}

#endif //MAIN_C_CHANGENUMBERSTOSPACES_H
