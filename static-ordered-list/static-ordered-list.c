#include "static-ordered-list.h"
#include <stdio.h>

void init_list(List *list) {

    list -> count = 0;
}

void print_list(const List *list) {

    for (int i = 0; i < list -> count; i++) {

        printf("%d \n", list -> array[i]);

    }



}

int get_value(int index, const List *list) {

//Dá index e quer receber valor

    if (index < 0 || index >= list -> count) {

        return -1;

    }

    return list -> array[index];

}

int get_index(int value, const List *list) {  // Binary Search

    int high = list -> count - 1;
    int low = 0;

    while (low <= high) {


        const int mid = low +  (high - low) / 2;

        if (value == list -> array[mid]){

            return mid;

        }

        if (value < list -> array[mid]) {

            high = mid - 1;

        }

        if (value > list -> array[mid]) {

            low = mid + 1;

        }

    }

    return -1;

}

void clear(List *list) {

    list -> count = 0;

}

int is_empty(const List *list) {

    if (list -> count == 0) {

        return 1;

    }

    return 0;

}

int is_full(const List *list) {

    if (list -> count == MAX) {

        return 1;
    }

    return 0;

}

int size(const List *list) {

    return list -> count;

}

void insert_ord(int value, List *list) {

    if (list -> count == MAX) {

        printf("List is full.\n");
        return;

    }

    for (int i = 0; i < list -> count; i++) {

        if (value <= list -> array[i]) {

            for (int j = list -> count - 1; j >= i; j--) {

                list -> array[j + 1] = list -> array[j];

            }

            list -> array[i] = value;
            list -> count++;
            return;

        }

    }

    list -> array[list -> count] = value;
    list -> count++;

}

void remove_value(int value, List *list) {

    if (is_empty(list) == 1) {
        printf("List is empty.\n");
        return;

    }

    int index = get_index(value, list);

    if (index == -1) {
        printf("Could not find value in list.\n");
        return;
    }

    for (int j = index; j < list -> count - 1; j++) {
        list -> array[j] = list -> array[j+1];
    }

    list -> count--;

}





