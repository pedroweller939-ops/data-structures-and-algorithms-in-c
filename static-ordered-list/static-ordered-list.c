/*
     RETURN CODES TABLE

       0 : Success;
      -1 : Invalid list pointer (NULL);
      -2 : List is full or empty (capacity/limit condition);
      -3 : Element or index not found / Out of bounds;
*/

#include <stdio.h>
#include "static-ordered-list.h"

int init_list(List *list) {
    if (list == NULL) {
        return -1;
    }

    list->count = 0;
    return 0;
}

int print_list(const List *list) {
    if (list == NULL) {
        return -1;
    }

    for (int i = 0; i < list->count; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");

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

int get_index(const List *list, int value) { // Binary Search
    if (list == NULL) {
        return -1;
    }

    int low = 0;
    int high = list->count - 1;

    while (low <= high) {
        const int mid = low + (high - low) / 2;

        if (value == list->array[mid]) {
            return mid; // Retorna o índice encontrado (>= 0)
        }

        if (value < list->array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -3; // Elemento não encontrado
}

int clear(List *list) {
    if (list == NULL) {
        return -1;
    }

    list->count = 0;
    return 0;
}

int is_empty(const List *list) {
    if (list == NULL) {
        return -1;
    }

    return list->count == 0;
}

int is_full(const List *list) {
    if (list == NULL) {
        return -1;
    }

    return list->count == MAX;
}

int size(const List *list) {
    if (list == NULL) {
        return -1;
    }

    return list->count;
}

int insert_ord(int value, List *list) {
    if (list == NULL) {
        return -1;
    }

    if (list->count == MAX) {
        return -2; // Lista cheia
    }

    for (int i = 0; i < list->count; i++) {
        if (value <= list->array[i]) {
            for (int j = list->count - 1; j >= i; j--) {
                list->array[j + 1] = list->array[j];
            }

            list->array[i] = value;
            list->count++;
            return 0;
        }
    }

    list->array[list->count] = value;
    list->count++;
    return 0;
}

int remove_value(int value, List *list) {
    if (list == NULL) {
        return -1;
    }

    if (is_empty(list) == 1) {
        return -2; // Lista vazia
    }

    int index = get_index(list, value);
    if (index < 0) {
        return index; // Retorna -3 (não encontrado) ou -1 (ponteiro inválido)
    }

    for (int j = index; j < list->count - 1; j++) {
        list->array[j] = list->array[j + 1];
    }

    list->count--;
    return 0;
}