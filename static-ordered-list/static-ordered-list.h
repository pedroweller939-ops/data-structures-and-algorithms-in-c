#ifndef STATIC_ORDERED_LIST_H
#define STATIC_ORDERED_LIST_H

#define MAX 100

typedef struct {
    int array[MAX];
    int count;
} List;

int init_list(List *list);
int print_list(const List *list);
int get_value(const List *list, int index, int *out_value);
int get_index(const List *list, int value);
int clear(List *list);
int is_empty(const List *list);
int is_full(const List *list);
int size(const List *list);
int insert_ord(int value, List *list);
int remove_value(int value, List *list);

#endif