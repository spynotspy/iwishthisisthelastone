//
// Created by Dima on 01.03.2022.
//

#ifndef MAIN_C_REVERSEDNUMBERSINBEGINOFWORDANDNORMALLETTERSINENDOFWORD_H
#define MAIN_C_REVERSEDNUMBERSINBEGINOFWORDANDNORMALLETTERSINENDOFWORD_H

#include "../string_.h"
#include "removeNonLetters.h"


void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 stringBuffer_);
    char *recPosition = copyIfReverse(endStringBuffer - 1, stringBuffer_ - 1, word.begin, isdigit);
    copyIf(stringBuffer_, endStringBuffer, recPosition, isalpha);
}

//преобразовать строку таким образом, чтобы цифры
//каждого слова были перенесены в начало слова и изменить порядок следования
//цифр в слове на обратный, а буквы – в конец слова, без изменения порядка
//следования.
void reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord(char *beginString) {
    char *beginSearch = beginString;

    WordDescriptor word; // считываемое слово
    while (getWord(beginSearch,
                   &word)) {

        digitToStart(word);

        beginSearch = word.end;
    }
}


#endif //MAIN_C_REVERSEDNUMBERSINBEGINOFWORDANDNORMALLETTERSINENDOFWORD_H
