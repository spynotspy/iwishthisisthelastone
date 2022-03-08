//
// Created by Dima on 02.03.2022.
//

#ifndef MAIN_C_CHANGENUMBERSTOSPACES_H
#define MAIN_C_CHANGENUMBERSTOSPACES_H

#include "../string_.h"

#define CHAR_ZERO 48

void makeSpaces(char **begin, int amountSpaces) {
    for (int i = 0; i < amountSpaces; ++i) {
        **begin = ' ';
        (*begin)++;
    }
}
//Преобразовать строку, заменяя каждую цифру соответствующим ей числом
//пробелов.
void changeNumbersToSpaces(char *s) {
    char *recPtr = s;
    char *readPtr = stringBuffer_;
    copy(s, getEndOfString(s) + 1, stringBuffer_);

    while (*readPtr != '\0') {
        if (isdigit(*readPtr)) {
            makeSpaces(&recPtr, *readPtr - CHAR_ZERO);
        } else {
            *recPtr = *readPtr;
            recPtr++;
        }
        readPtr++;
    }

    *recPtr = '\0';
}


#endif //MAIN_C_CHANGENUMBERSTOSPACES_H
