#ifndef DATA_STRUCTURES_DOUBLY_LINKED_ORDERED_LIST_H
#define DATA_STRUCTURES_DOUBLY_LINKED_ORDERED_LIST_H


typedef struct NODE{

    struct NODE* next;
    struct NODE* prev;
    int data;

} Node;

typedef struct DOUBLY_LINKED_LIST {

    Node *head;
    Node *tail;
    int size;

} DoublyLinkedList;

DoublyLinkedList* create_list(void);
int clear_list(DoublyLinkedList *list);
int destroy_list(DoublyLinkedList **list);
int insert(DoublyLinkedList *list, int data);
int remove_first(DoublyLinkedList *list);
int remove_last(DoublyLinkedList *list);
int remove_at(DoublyLinkedList *list, int index);
int getdata(DoublyLinkedList *list, int index);
int getsize(DoublyLinkedList *list);
int getindex(const DoublyLinkedList *list, int data);
int is_empty(const DoublyLinkedList *list);
int print_forward(const DoublyLinkedList *list);
int contains(const DoublyLinkedList *list, int data);




#endif //DATA_STRUCTURES_DOUBLY_LINKED_ORDERED_LIST_H
