#include <assert.h>
#include "libs/algorithms/string/tasks/everyWordReversed.h"
#include "libs/algorithms/string/tasks/removeNonLetters.h"
#include "libs/algorithms/string/tasks/removeAdjacentEqualLetters.h"
#include "libs/algorithms/string/tasks/reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord.h"
#include "libs/algorithms/string/tasks/changeNumbersToSpaces.h"
#include "libs/algorithms/string/tasks/changeW1ToW2.h"
#include "libs/algorithms/string/tasks/areWordsOrdered.h"
#include "libs/algorithms/string/tasks/printWordsInReversedOrder.h"
#include "libs/algorithms/string/tasks/countPalindromes.h"
#include "libs/algorithms/string/tasks/mixStrings.h"


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
    char expected[] = "abc cba123   upupipip";

    everyWordReversed(source);

    ASSERT_STRING(expected, source);
}

void test_changeNumbersToSpaces() {
    char source[] = "1_00000ccc_1";
    char expected[MAX_STRING_SIZE] = " _ccc_ ";

    changeNumbersToSpaces(source);

    ASSERT_STRING(expected, source);
}

void test_changeW1toW2_oneChange() {
    char source[] = "55 42";
    char w1[] = "42";
    char w2[] = "10";
    char expected[] = "55 10";

    replace(source, w1, w2);

    ASSERT_STRING(expected, source);
}

void test_changeW1toW2_multiplyChange() {
    char source[] = "nasty nasty 1";
    char w1[] = "nasty";
    char w2[] = "lipton";
    char expected[] = "lipton lipton 1";

    replace(source, w1, w2);

    ASSERT_STRING(expected, source);
}


void test_changeW1toW2_equalWordsSize() {
    char source[] = "qwerty lang qwerty";
    char w1[] = "qwerty";
    char w2[] = "123456";
    char expected[] = "123456 lang 123456";

    replace(source, w1, w2);

    ASSERT_STRING(expected, source);
}


void test_changeW1toW2() {
    test_changeW1toW2_oneChange();
    test_changeW1toW2_multiplyChange();
    test_changeW1toW2_equalWordsSize();
}


void test_areWordsOrdered_true() {
    char source[] = "alpha aw beta centre six";

    assert(areWordsOrdered(source) == 1);
}

void test_areWordsOrdered_false() {
    char source[] = "sleep alpha beta centre six";

    assert(areWordsOrdered(source) == 0);
}

void test_areWordsOrdered() {
    test_areWordsOrdered_true();
    test_areWordsOrdered_false();
}

void test_printWordsInReversedOrder() {
    char s[] = "i want to start c++...";

    printWordsInReversedOrder(s);
}

void test_countPalindromes_notZeroPalindromes() {
    char s[] = "abba,abcba,qqww,w\t\t";

    assert(countPalindromes(s) == 3);
}

void test_countPalindromes_zeroPalindromes() {
    char s[] = "    aba, cd , efg ,     hi     ";
    assert(countPalindromes(s) == 1);
}

void test_countPalindromes_empty() {
    char s[] = "";
    assert(countPalindromes(s) == 0);
}

void test_countPalindromes() {


    test_countPalindromes_notZeroPalindromes();
    test_countPalindromes_zeroPalindromes();
    test_countPalindromes_empty();
}


void test_mixStrings_s1Longer() {
    char s[MAX_STRING_SIZE];
    char s1[] = "one three five";
    char s2[] = "two four";

    mixString(s, s1, s2);

    ASSERT_STRING("one two three four five", s);
}

void test_mixStrings_s2Longer() {
    char s[MAX_STRING_SIZE];
    char s1[] = "one three";
    char s2[] = "two four five";

    mixString(s, s1, s2);

    ASSERT_STRING("one two three four five", s);
}

void test_mixStrings_equalLength() {
    char s[MAX_STRING_SIZE];
    char s1[] = "one three five";
    char s2[] = "two four six";

    mixString(s, s1, s2);

    ASSERT_STRING("one two three four five six", s);
}

void test_mixStrings_s1Empty() {
    char s[MAX_STRING_SIZE];
    char s1[] = "";
    char s2[] = "two four";

    mixString(s, s1, s2);

    ASSERT_STRING("two four", s);
}

void test_mixStrings_s2Empty() {
    char s[MAX_STRING_SIZE];
    char s1[] = "one three five";
    char s2[] = "";

    mixString(s, s1, s2);

    ASSERT_STRING("one three five", s);
}

void test_mixStrings_bothEqual() {
    char s[MAX_STRING_SIZE];
    char s1[] = "hehe haha";
    char s2[] = "funny laugh";

    mixString(s, s1, s2);

    ASSERT_STRING("hehe funny haha laugh", s);
}


void test_mixStrings() {
    test_mixStrings_s1Longer();
    test_mixStrings_s2Longer();
    test_mixStrings_equalLength();
    test_mixStrings_s1Empty();
    test_mixStrings_s2Empty();
    test_mixStrings_bothEqual();
}


void test_tasks() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord();
    test_everyWordReversed();
    test_changeNumbersToSpaces();
    test_changeW1toW2();
    test_areWordsOrdered();
    //test_printWordsInReversedOrder();
    test_countPalindromes();
    test_mixStrings();

}

int main() {
    //test_string();
    test_tasks();

    return 0;
}