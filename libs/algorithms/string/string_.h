//
// Created by Dima on 24.02.2022.
//

#ifndef MAIN_C_STRING__H
#define MAIN_C_STRING__H


#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>

# define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20
static char stringBuffer_[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

static BagOfWords _bag;
static BagOfWords _bag2;

size_t strlen_(const char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination);

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

bool getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

void getBagOfWords(BagOfWords *bag, char *s);

#endif //MAIN_C_STRING__H
