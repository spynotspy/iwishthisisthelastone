
cmake_minimum_required(VERSION 3.20.2)
project(5b C)

set(CMAKE_C_STANDARD 11)
add_executable(project main.c libs/algorithms/string/tasks/everyWordReversed.h libs/algorithms/string/tasks/changeNumbersToSpaces.h libs/algorithms/string/tasks/changeW1ToW2.h libs/algorithms/string/tasks/areWordsOrdered.h libs/algorithms/string/tasks/printWordsInReversedOrder.h libs/algorithms/string/tasks/countPalindromes.h libs/algorithms/string/tasks/mixStrings.h libs/algorithms/string/tasks/reverseWordsOrder.h libs/algorithms/string/tasks/printWordBeforeFirstWordWithA.h libs/algorithms/string/tasks/getLastWordFromRow1ThatInRow2.h)
# создаём библиотеку
add_library(str libs/algorithms/string/string_.h
libs/algorithms/string/string_.c
libs/algorithms/string/tasks/removeNonLetters.h
libs/algorithms/string/tasks/removeAdjacentEqualLetters.h
libs/algorithms/string/tasks/reversedNumbersInBeginOfWordAndNormalLettersInEndOfWord.h

)

# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(project str)