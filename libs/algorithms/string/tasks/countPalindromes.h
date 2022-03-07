//
// Created by Dima on 08.03.2022.
//

#ifndef MAIN_C_COUNTPALINDROMES_H
#define MAIN_C_COUNTPALINDROMES_H

#include "../string_.h"

bool isPalindrome(WordDescriptor word) {
    word.end--;

    if (word.end - word.begin == 0 && *word.begin == *word.end)
        return true;
    else if (word.end - word.begin == 0 && *word.begin != *word.end)
        return false;

    while (word.end - word.begin > 0) {
        if (*word.end != *word.begin)
            return false;
        word.begin++;
        word.end--;
    }
    return true;
}

int countPalindromes(char *s) {
    char *begin = findNonSpace(s);
    char *end = getEndOfString(s);
    char *commaPos = find(begin, end, ',');
    int count = 0;
    WordDescriptor word;

    while (*commaPos != '\0') {
        word.begin = findNonSpace(begin);
        word.end = commaPos;

        count += isPalindrome(word);

        begin = commaPos + 1;
        commaPos = find(begin, end, ',');

        if (*commaPos == '\0') {
            getWord(begin, &word);
            count += isPalindrome(word);
        }
    }

    return count;
}

#endif //MAIN_C_COUNTPALINDROMES_H
