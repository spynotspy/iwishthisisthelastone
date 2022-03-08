//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

bool checkInWordA(WordDescriptor word) {
    char *begin = word.begin;
    while (begin != word.end) {
        if (*begin == 'a' || *begin == 'A')
            return true;
        begin++;
    }
    return false;
}

// заголовок функции
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, char **beginWordBefore, char **endWordBefore) {

    char *begin = s;
    WordDescriptor previousWord;
    if (getWord(begin, &previousWord) == 0)
        return EMPTY_STRING;

    if (checkInWordA(previousWord))
        return FIRST_WORD_WITH_A;

    WordDescriptor currentWord;
    while (getWord(begin, &currentWord)) {
        if (checkInWordA(currentWord)) {
            *beginWordBefore = previousWord.begin;
            *endWordBefore = previousWord.end;
            return WORD_FOUND;
        }
        previousWord = currentWord;
        begin = currentWord.end;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}


void printWordBeforeFirstWordWithA
        (char *s) {
    char *beginWordBegoreA, *endWordBeforeA;
    if (getWordBeforeFirstWordWithA(s, &beginWordBegoreA, &endWordBeforeA)) {
        *endWordBeforeA = '\0';
        printf("%s\n", beginWordBegoreA);
    }
}

#endif //MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H
