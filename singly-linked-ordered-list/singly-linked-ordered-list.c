/*
     RETURN CODES TABLE

       0 : Success;
      -1 : Invalid list pointer (NULL);
      -2 : Memory allocation error;
      -3 : Element or index not found;
      -4 : Corrupted list structure;
*/


#include "singly-linked-ordered-list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* create_list() {
    LinkedList *List = (LinkedList *)malloc(sizeof(LinkedList));
    if (List != NULL) {
        List->head = NULL;
        List->size = 0;
    }
    return List;
}

int print_list(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }

    if (List->head == NULL) {
        return -2;
    }

    Node *current_node = List->head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
    return 0;
}

int is_empty(LinkedList *List) {
    if (List -> size == 0 || List -> head == NULL) {
        return 1;
    }
    return 0;
}

int get_size(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }

    if (List->head == NULL) {
        return -2;
    }

    return List->size;
}

int get_index(LinkedList *List, int data) {
    if (List == NULL) {
        return -1;
    }

    if (List->head == NULL) {
        return -2;
    }

    Node *current_node = List->head;
    int index = 0;

    while (current_node != NULL) {
        if (current_node->data > data) {
            return -3;
        }

        if (current_node->data == data) {
            return index;
        }

        current_node = current_node->next;
        index++;
    }

    return -3;
}

int contains(LinkedList *List, int data) {
    int index = get_index(List, data);

    if (index >= 0) {
        return 1;
    }

    return 0;
}

int clear_list(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }

    if (List->head == NULL) {
        return -2;
    }

    Node *current_node = List->head;
    Node *previous_node = NULL;

    while (current_node != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
    }

    List->head = NULL;
    List->size = 0;
    return 0;
}

int get_data(LinkedList *List, int index, int *out_value) {
    if (List == NULL) {
        return -1;
    }

    if (List->head == NULL) {
        return -2;
    }

    if (index < 0 || index >= List->size) {
        return -3;
    } else {
        Node *current_node = List->head;
        for (int i = 0; i < index; i++) {
            current_node = current_node->next;

            if (current_node == NULL) {
                return -4;
            }
        }

        *out_value = current_node->data;
        return 0;
    }
}

int insert(LinkedList *List, int data) {
    if (List == NULL) {
        return -1;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        return -2;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (List->head == NULL || new_node->data <= List->head->data) {
        new_node->next = List->head;
        List->head = new_node;
        List->size++;
        return 0;
    } else {
        Node *current_node = List->head;

        while (current_node->next != NULL && current_node->next->data < data) {
            current_node = current_node->next;
        }

        new_node->next = current_node->next;
        current_node->next = new_node;
        List->size++;
        return 0;
    }
}

int remove_last(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }

    if (List->head == NULL) {
        return -2;
    }

    if (List->head->next == NULL) {
        free(List->head);
        List->head = NULL;
    } else {
        Node *current_node = List->head;
        Node *previous_node = NULL;

        while (current_node->next != NULL) {
            previous_node = current_node;
            current_node = current_node->next;
        }

        free(current_node);
        previous_node->next = NULL;
    }

    List->size--;
    return 0;
}

int remove_at(LinkedList *List, int index) {
    if (List == NULL) {
        return -1;
    }

    if (index < 0 || index >= List->size) {
        return -2;
    }

    if (List->head == NULL) {
        return -3;
    }

    if (List->head->next == NULL || index == 0) {
        Node *node_to_remove = List->head;
        List->head = List->head->next;
        free(node_to_remove);
        List->size--;
        return 0;
    } else {
        Node *current_node = List->head;
        Node *previous_node = NULL;

        for (int i = 0; i < index; i++) {
            previous_node = current_node;
            current_node = current_node->next;
        }

        previous_node->next = current_node->next;
        current_node->next = NULL;
        free(current_node);
        List->size--;
        return 0;
    }
}