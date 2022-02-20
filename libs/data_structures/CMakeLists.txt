add_library(data_structures matrix/matrix.c
        data_structures matrix/test_matrix.c)

target_link_libraries(data_structures algorithms)
