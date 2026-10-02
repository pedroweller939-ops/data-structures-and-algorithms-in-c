cmake_minimum_required(VERSION 3.20)
project(Data_Structures C)

set(CMAKE_C_STANDARD 17)

add_executable(test_static_list
        static-sequential-list/static_sequential_list.h
        static-sequential-list/static_sequential_list.c
        static-sequential-list/main.c
)