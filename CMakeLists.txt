cmake_minimum_required(VERSION 3.20)
project(Data_Structures C)

set(CMAKE_C_STANDARD 17)

# Executable 1: Static Sequential List
add_executable(test_static_list
        static-sequential-list/static_sequential_list.h
        static-sequential-list/static_sequential_list.c
        static-sequential-list/main.c
)

# Executable 2: Static Ordered List
add_executable(test_static_ordered_list
        static-ordered-list/static-ordered-list.h
        static-ordered-list/static-ordered-list.c
        static-ordered-list/main.c
)

# Executable 3: singly-linked-list
add_executable(singly-linked-list
        singly-linked-list/singly-linked-list.c
        singly-linked-list/singly-linked-list.h
        singly-linked-list/main.c


)