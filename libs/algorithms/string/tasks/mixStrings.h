//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_MIXSTRINGS_H
#define MAIN_C_MIXSTRINGS_H

#include "../string_.h"

//Даны две строки. Получить строку, в которой чередуются слова первой и второй строки. Если в одной из строк число слов больше, чем в другой, то оставшиеся слова этой строки должны быть дописаны в строку-результат. В качестве
//разделителя между словами используйте пробел.
void mixString(char *s, char *s1, char *s2) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *begin = s, *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            begin = copy(word1.begin, word1.end, begin);
            *begin++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            begin = copy(word2.begin, word2.end, begin);
            *begin++ = ' ';
            beginSearch2 = word2.end;
        }

    }
    *--begin = '\0';
}


#endif //MAIN_C_MIXSTRINGS_H
