//
// Created by weller on 01/10/2026.
//

#ifndef STATIC_SEQUENTIAL_LIST_H
#define STATIC_SEQUENTIAL_LIST_H

#define MAX 10

typedef struct {
    int array[MAX];
    int count;
} List;

// Function Prototypes
void init_list(List *list);
void insert(int value, List *list);
int search(int value, const List *list);
void remove_value(int value, List *list);
int get_value(int index, const List *list);
int size(const List *list);
void print_list(const List *list);
void clear(List *list);

#endif // STATIC_SEQUENTIAL_LIST_H


