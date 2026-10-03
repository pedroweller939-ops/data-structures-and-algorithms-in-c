#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_H

typedef struct NODE{

    int data;
    struct NODE *next;

} Node;

typedef struct{

     Node *head;
     int size;

} LinkedList;

master
LinkedList* create_list(void);
int insert_at(LinkedList *List,int data, int index);
int insert_last(LinkedList *List, int data);
int remove_at(LinkedList *List, int index);
int remove_last(LinkedList *List);
int get_data(LinkedList *List, int index,int *out_value);
int get_index(LinkedList *List, int data);
int contains(LinkedList *List, int data);
int print_list(LinkedList *List);
int clear_list(LinkedList *List);
int is_empty(LinkedList *List);
int get_size(LinkedList *List);
=======
LinkedList* create_list(void); 
int insert_at(LinkedList *List,int data, int index); 
int insert_last(LinkedList *List, int data); 
int remove_at(LinkedList *List, int index);
int remove_last(LinkedList *List); 
int get_data(LinkedList *List, int index,int *out_value); 
int get_index(LinkedList *List, int data); 
int contains(LinkedList *List, int data); 
int print_list(LinkedList *List); 
int clear_list(LinkedList *List);
int is_empty(LinkedList *List); 
int get_size(LinkedList *List); 






#endif //DATA_STRUCTURES_SINGLY_LINKED_LIST_H
