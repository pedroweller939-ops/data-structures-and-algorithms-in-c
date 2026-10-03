#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

/* Public Interface */
LinkedList* create_list(void);
int print_list(LinkedList *List);
int is_empty(LinkedList *List);
int get_size(LinkedList *List);
int get_index(LinkedList *List, int data);
int contains(LinkedList *List, int data);
int clear_list(LinkedList *List);
int get_data(LinkedList *List, int index, int *out_value);
int insert_last(LinkedList *List, int data);
int insert_at(LinkedList *List, int data, int index);
int remove_last(LinkedList *List);
int remove_at(LinkedList *List, int index);

#endif