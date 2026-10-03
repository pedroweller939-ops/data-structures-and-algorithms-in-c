/*
     RETURN CODES TABLE

       0 : Success;
      -1 : Invalid list pointer (NULL);
      -2 : List is empty / Memory allocation failure;
      -3 : Element or index not found / Out of bounds;
      -4 : Unexpected structure corruption;
*/


#include "doubly-linked-ordered-list.h"
#include<stdio.h>
#include<stdlib.h>

DoublyLinkedList* create_list(void) {

    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list != NULL) {

        list -> head = NULL;
        list -> tail = NULL;
        list -> size = 0;

    }

    return list;

}

int insert(DoublyLinkedList *list, int data) {

    if (list == NULL) {

        return -1;

    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {

        return -2;

    }

    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    if (list -> head == NULL) {

        list -> head = list -> tail = new_node;
        list -> size++;
        return 0;
    }

    if (data <= list -> head -> data) {

        new_node -> next = list -> head;
        list-> head -> prev = new_node;
        list -> head = new_node;
        list -> size++;
        return 0;
    }

    if (data >= list -> tail -> data) {

        list -> tail -> next = new_node;
        new_node -> prev = list -> tail;
        list -> tail = new_node;
        list -> size++;
        return 0;
    }

    Node *current_node = list -> head;

    while (current_node != NULL && current_node -> data < data) {
        current_node = current_node -> next;
    }

    new_node -> prev = current_node -> prev;
    new_node -> next = current_node ;
    current_node -> prev -> next = new_node;
    current_node -> prev = new_node;

    list -> size++;
    return 0;


}

int remove_last(DoublyLinkedList *list) {

    if (list == NULL) {
        return  -1;

    }

    if (list -> head == NULL) {
        return -2;

    }

    Node *Node_to_remove = list -> tail;

    if (list -> head == list -> tail) {

        list -> head = NULL;
        list -> tail = NULL;

    } else {

        list -> tail = list -> tail -> prev;
        list -> tail -> next = NULL;

    }

    free(Node_to_remove);
    list -> size--;
    return 0;

}

int remove_first(DoublyLinkedList *list) {

    if (list == NULL) {
        return  -1;

    }

    if (list -> head == NULL) {
        return -2;

    }

    Node *Node_to_remove = list -> head;

    if (list -> head == list -> tail) {

        list -> head = NULL;
        list -> tail = NULL;

    } else {

        list -> head = list -> head -> next;
        list -> head -> prev = NULL;

    }

    free(Node_to_remove);
    list -> size--;
    return 0;

}

int remove_at(DoublyLinkedList *list, int index) {

    if (list == NULL) {
        return  -1;

    }

    if (list -> head == NULL) {
        return -2;

    }

    if (index < 0 || index >= list -> size) {
        return -3;

    }

    if (index == 0) {
        return remove_first(list);

    }

    if (index == list -> size - 1) {
        return remove_last(list);

    }

    Node *current_node = list -> head;

    for (int i = 0; i < index; i++) {

        current_node = current_node -> next;

    }

    current_node -> prev -> next = current_node -> next;
    current_node -> next -> prev = current_node -> prev;

    free(current_node);
    list -> size--;
    return 0;

}

int getdata(DoublyLinkedList *list, int index) {

    if (list == NULL) {
        return  -1;

    }

    if (list -> head == NULL) {
        return -2;

    }

    if (index < 0 || index >= list -> size) {
        return -3;

    }

    if (index == 0) {
        return list -> head -> data;

    }

    if (index == list -> size - 1 ) {
        return list -> tail -> data;

    }

    Node *current_node = list -> head;

    for (int i = 0; i < index; i++) {

        current_node = current_node -> next;

    }

    return current_node -> data;
}

int getsize(DoublyLinkedList *list) {

    if (list == NULL) {
        return -1;

    }

    return list -> size;

}

int is_empty(const DoublyLinkedList *list) {

    if (list == NULL) {
        return -1;
    }

    if (list -> head == NULL) {
        return 1;
    }

    return 0;
}

int print_forward(const DoublyLinkedList *list) {

    if (list == NULL) {
        return -1;
    }

    if (list -> head == NULL) {
        return -2;

    }

    Node *current_node = list -> head;
    while (current_node != NULL) {
        printf("%d ", current_node -> data);
        current_node = current_node -> next;

    }

    printf("\n");
    return 0;

}

int getindex(const DoublyLinkedList *list, int data) {

    if (list == NULL) {
        return  -1;

    }

    if (list -> head == NULL) {
        return -2;

    }

    Node *current_node = list -> head;

    for (int i = 0; i < list -> size; i++) {

        if (current_node -> data == data) {
            return i;

        }

        if (current_node -> data > data) {

            return -3;
        }

        current_node = current_node -> next;

    }
    return -3;
}

int clear_list(DoublyLinkedList *list) {
    if (list == NULL) {

        return -1;

    }

    Node *current_node = list -> head ;
    Node *previous_node = NULL;

    while (current_node != NULL) {

        previous_node = current_node;
        current_node = current_node -> next;
        free(previous_node);

    }

    list -> head = list -> tail = NULL;
    list -> size = 0;
    return 0;
}

int destroy_list(DoublyLinkedList **list) {

    if (list == NULL || *list == NULL) {
        return -1;
    }

    clear_list(*list);
    free(*list);
    *list = NULL;
    return 0;

}

int contains(const DoublyLinkedList *list, int data) {

    if (list == NULL) {

        return -1;

    }

    int index = getindex(list, data);

    if (index >= 0) {

        return 1;
    }
    return 0;
}






















