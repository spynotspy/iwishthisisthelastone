#include <assert.h>
#include "libs/algorithms/string/tasks/everyWordReversed.h"
#include "libs/algorithms/string/tasks/removeNonLetters.h"
#include "libs/algorithms/string/tasks/removeAdjacentEqualLetters.h"
#include "libs/algorithms/string/tasks/reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord.h"
#include "libs/algorithms/string/tasks/changeNumbersToSpaces.h"

# define ASSERT_STRING(expected, got) assertString ( expected , got , \
 __FILE__ , __FUNCTION__ , __LINE__ )

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}


void test_findNonSpace() {
    char c[] = "  w a r";
    char *res = findNonSpace(c);
    assert(*res == 'w');
    assert(res == &c[2]);
}

void test_findSpace() {
    char c[] = "beep boop";
    char *res = findSpace(c);
    assert(*res == ' ');
    assert(res == &c[4]);
}

void test_findNonSpaceReverse() {
    char c[] = " abba ";
    char *res = findNonSpaceReverse(&c[5], &c[-1]);
    assert(*res == 'a');
}

void test_findSpaceReverse() {
    char c[] = " the smiths - well i wonder";
    char *res = findSpaceReverse(&c[26], &c[-1]);
    assert(*res == ' ');
    assert(res == &c[20]);
}

void test_strcmp_equal() {
    char c1[] = "qwerty";
    char c2[] = "qwerty";
    assert(strcmp(c1, c2) == 0);
}

void test_strcmp_lesser() {
    char c1[] = "abc";
    char c2[] = "bcd";
    assert(strcmp(c1, c2) == -1);
}

void test_strcmp_bigger() {
    char c1[] = "qwerty";
    char c2[] = "abcd";
    assert(strcmp(c1, c2) == 1);
}


void test_strcmp() {
    test_strcmp_equal();
    test_strcmp_lesser();
    test_strcmp_bigger();
}

void test_copy() {
    char c1[] = "nasty";
    char c2[6];
    char *cc = copy(c1, &c1[5], c2);
    assert(c2[0] == 'n');
    assert(c2[1] == 'a');
    assert(c2[2] == 's');
    assert(c2[3] == 't');
    assert(c2[4] == 'y');
    assert(cc == &c2[5] && c2[5] != '\0');
}

bool isNumber(char letter) {
    return letter >= '0' && letter <= '9';
}

void test_copyIf() {
    char c1[] = "";
    char c2[10] = "";
    char *cc = copyIf(c1, &c1[9], c2 + 4, isspace);
    ASSERT_STRING(c1, c2);
}

void test_copyIfReverse() {
    char c1[] = "1a2b3c";
    char c2[10];
    char *cc = copyIfReverse(&c1[6], c1, c2, isNumber);
    assert(c2[0] == '3');
    assert(cc = &c2[3]);
}

void test_string() {
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

void test_removeNonLetters() {
    char source[] = "";
    char expected[] = "";
    removeNonLetters(source);

    ASSERT_STRING(expected, source);
}

void test_removeAdjacentEqualLetters() {
    char source[] = "aaabbbccc";
    char expected[] = "abc";
    removeAdjacentEqualLetters(source);

    ASSERT_STRING(expected, source);
}

void test_reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord() {
    char source[] = "3a2bc1 hhh123";
    char expected[] = "123abc 321hhh";

    reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord(source);

    ASSERT_STRING(expected, source);
}

void test_everyWordReversed() {
    char source[] = "cba 321abc   pipipupu";
    char expected[] ="abc cba123   upupipip";

    everyWordReversed(source);

    ASSERT_STRING(expected, source);
}

void test_changeNumbersToSpaces() {
    char source[] = "a1b2c3";
    char expected[MAX_STRING_SIZE] = "a b  c   ";

    changeNumbersToSpaces(source);

    ASSERT_STRING(expected, source);
}

void test_tasks() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord();
    test_everyWordReversed();
    //test_changeNumbersToSpaces();
}

int main() {
    //test_string();
    test_tasks();


    return 0;
}