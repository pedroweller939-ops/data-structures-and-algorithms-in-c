#ifndef STATIC_SEQUENTIAL_LIST_H
#define STATIC_SEQUENTIAL_LIST_H

#define MAX 100

typedef struct {
    int array[MAX];
    int count;
} List;

int init_list(List *list);
int insert_ord(int value, List *list);
int search(const List *list, int value);
int remove_value(int value, List *list);
int get_value(const List *list, int index, int *out_value);
int size(const List *list);
int print_list(const List *list);
int clear(List *list);

#endif