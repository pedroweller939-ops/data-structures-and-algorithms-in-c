cmake_minimum_required(VERSION 3.20)
project(Data_Structures C)

set(CMAKE_C_STANDARD 17)

# Executável 1: Lista Sequencial Estática
add_executable(test_static_list
        static-sequential-list/static_sequential_list.h
        static-sequential-list/static_sequential_list.c
        static-sequential-list/main.c
)

# Executável 2: Lista Sequencial Ordenada
add_executable(test_static_ordered_list
        static-ordered-list/static-ordered-list.h
        static-ordered-list/static-ordered-list.c
        static-ordered-list/main.c
)