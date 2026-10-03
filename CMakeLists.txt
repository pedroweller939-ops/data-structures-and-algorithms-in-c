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

# Executable 3: Singly Linked List
add_executable(singly-linked-list
        singly-linked-list/singly-linked-list.h
        singly-linked-list/singly-linked-list.c
        singly-linked-list/main.c
)

# Executable 4: Singly Linked Ordered List
add_executable(singly-linked-ordered-list
        singly-linked-ordered-list/singly-linked-ordered-list.h
        singly-linked-ordered-list/singly-linked-ordered-list.c
        singly-linked-ordered-list/main.c
)

# Executable 5: Doubly Linked List
add_executable(doubly-linked-list
        doubly-linked-list/doubly-linked-list.h
        doubly-linked-list/doubly-linked-list.c
        doubly-linked-list/main.c
        linked-stack/linked-stack.c
        linked-stack/linked-stack.h
        linked-stack/main.c
        static-queue/static-queue.c
        static-queue/static-queue.h
        static-queue/main.c
        linked-queue/linked-queue.c
        linked-queue/linked-queue.h
        linked-queue/main.c
)

# Executable 6: Static Stack
add_executable(static-stack
        static-stack/static-stack.h
        static-stack/static-stack.c
        static-stack/main.c
)

# Executable 7: Linked Stack
add_executable(linked-stack
        linked-stack/linked-stack.h
        linked-stack/linked-stack.c
        linked-stack/main.c
)

# Executable 8: Doubly Linked Ordered List
add_executable(doubly-linked-ordered-list
        doubly-linked-ordered-list/doubly-linked-ordered-list.h
        doubly-linked-ordered-list/doubly-linked-ordered-list.c
        doubly-linked-ordered-list/main.c
)

# Executable 9: Static Queue
add_executable(static-queue
        static-queue/static-queue.c
        static-queue/static-queue.h
        static-queue/main.c

)

# Executable 10: Linked Queue
add_executable(linked-queue
        linked-queue/linked-queue.c
        linked-queue/linked-queue.h
        linked-queue/main.c


)