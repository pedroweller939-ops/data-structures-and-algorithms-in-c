#include <stdio.h>
#include "static_sequential_list.h"

void init_list(List *list) {
    list->count = 0;
}

void insert_ord(int value, List *list) {
    if (list->count >= MAX) {
        printf("Too many elements\n");
        return;
    }
    list->array[list->count++] = value;
}

int search(int value, const List *list) {
    for (int i = 0; i < list->count; i++) {
        if (list->array[i] == value) {
            return i;
        }
    }
    return -1;
}

void remove_value(int value, List *list) {
    int index = search(value, list);
    if (index == -1) {
        printf("Element not found\n");
        return;
    }
    for (int i = index; i < list->count - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->count--;
}

int get_value(int index, const List *list) {
    if (index >= 0 && index < list->count) {
        return list->array[index];
    }
    printf("Index %d is out of range\n", index);
    return -1;
}

int size(const List *list) {
    return list->count;
}

void print_list(const List *list) {
    for (int i = 0; i < list->count; i++) {
        printf("Index %d: %d.\n", i, list->array[i]);
    }
}

void clear(List *list) {
    list->count = 0;
}