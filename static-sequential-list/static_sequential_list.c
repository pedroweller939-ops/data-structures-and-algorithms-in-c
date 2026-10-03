/*
RETURN CODES TABLE

       0 : Success;
      -1 : Invalid list pointer (NULL);
      -2 : List is full (capacity limit reached);
      -3 : Element or index not found / Out of bounds;
*/

#include <stdio.h>
#include "static_sequential_list.h"

int init_list(List *list) {
    if (list == NULL) {
        return -1;
    }

    list->count = 0;
    return 0;
}

int insert_ord( int value, List *list) {
    if (list == NULL) {
        return -1;
    }

    if (list->count >= MAX) {
        return -2;
    }

    list->array[list->count++] = value;
    return 0;
}

int search(const List *list, int value) {
    if (list == NULL) {
        return -1;
    }

    for (int i = 0; i < list->count; i++) {
        if (list->array[i] == value) {
            return i; // Retorna o índice encontrado (>= 0)
        }
    }

    return -3; // Elemento não encontrado
}

int remove_value(int value, List *list) {
    if (list == NULL) {
        return -1;
    }

    int index = search(list, value);
    if (index < 0) {
        return index; // Retorna -3 se não encontrou, ou -1 se a lista for NULL
    }

    for (int i = index; i < list->count - 1; i++) {
        list->array[i] = list->array[i + 1];
    }

    list->count--;
    return 0;
}

int get_value(const List *list, int index, int *out_value) {
    if (list == NULL || out_value == NULL) {
        return -1;
    }

    if (index < 0 || index >= list->count) {
        return -3;
    }

    *out_value = list->array[index];
    return 0;
}

int size(const List *list) {
    if (list == NULL) {
        return -1;
    }

    return list->count;
}

int print_list(const List *list) {
    if (list == NULL) {
        return -1;
    }

    for (int i = 0; i < list->count; i++) {
        printf("Index %d: %d.\n", i, list->array[i]);
    }

    return 0;
}

int clear(List *list) {
    if (list == NULL) {
        return -1;
    }

    list->count = 0;
    return 0;
}