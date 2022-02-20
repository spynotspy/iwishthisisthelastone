cmake_minimum_required(VERSION 3.21)
project(5b C)

set(CMAKE_C_STANDARD 11)

add_executable(5b main.c libs/algorithms/array/array.h libs/algorithms/array/array.c
        libs/algorithms/algorithm.c libs/algorithms/algorithm.h
        libs/data_structures/vector/vector.h libs/data_structures/vector/vector.c
        libs/data_structures/vector/vectorVoid.h libs/data_structures/vector/vectorVoid.c
        libs/data_structures/matrix/matrix.h libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/test_matrix.h libs/data_structures/matrix/test_matrix.c
        libs/data_structures/matrix/test_matrix_functions.h libs/data_structures/matrix/test_matrix_functions.c)
