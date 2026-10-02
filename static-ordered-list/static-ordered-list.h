//
// Created by weller on 02/10/2026.
//

#ifndef DATA_STRUCTURES_STATIC_ORDERED_LIST_H
#define DATA_STRUCTURES_STATIC_ORDERED_LIST_H

#define MAX 10

typedef struct {

    int array[MAX];
    int count;

} List;

void init_list(List *list);
void insert_ord(int value, List *list);
void remove_value(int value, List *list);
int get_value(int index, const List *list);
int get_index(int value, const List *list);
int size(const List *list);
void print_list(const List *list);
void clear(List *list);
int is_empty(const List *list);
int is_full(const List *list);



#endif //DATA_STRUCTURES_STATIC_ORDERED_LIST_H
