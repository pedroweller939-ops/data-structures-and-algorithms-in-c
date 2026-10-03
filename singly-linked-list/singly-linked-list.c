/*
     RETURN CODES TABLE

       0 : Success;
      -1 : Invalid list pointer (NULL);
      -2 : List is empty / Memory allocation failure;
      -3 : Element or index not found / Out of bounds;
      -4 : Unexpected structure corruption;
*/

#include "singly-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* create_list(void) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    if (list != NULL) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

int get_data(LinkedList *List, int index, int *out_value) {
    if (List == NULL || out_value == NULL) {
        return -1;
    }
    if (List->head == NULL) {
        return -2;
    }
    if (index < 0 || index >= List->size) {
        return -3;
    }

    Node *current_node = List->head;

    for (int count = 0; count < index; count++) {
        current_node = current_node->next;

        if (current_node == NULL) {
            return -4;
        }
    }

    *out_value = current_node->data;
    return 0;
}

int get_index(LinkedList *List, int data) {
    if (List == NULL) {
        return -1;
    }
    if (List->head == NULL) {
        return -2;
    }

    Node *current_node = List->head;

    for (int count = 0; count < List->size; count++) {
        if (current_node == NULL) {
            return -4;
        }

        if (current_node->data == data) {
            return count;
        }

        current_node = current_node->next;
    }

    return -3;
}

int contains(LinkedList *List, int data) {
    int exists = get_index(List, data);

    if (exists >= 0) {
        return 1;
    }

    return 0;
}

int print_list(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }
    if (List->head == NULL) {
        printf("List is empty.\n");
        return -2;
    }

    Node *current_node = List->head;

    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }

    printf("NULL\n");
    return 0;
}

int is_empty(LinkedList *List) {
    if (List == NULL || List->head == NULL) {
        return 1;
    }
    return 0;
}

int get_size(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }
    if (List->head == NULL) {
        return 0;
    }

    return List->size;
}

int clear_list(LinkedList *List) {
    if (List == NULL) {
        return -1;
    }
    if (List->head == NULL) {
        return 0;
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

int insert_last(LinkedList *List, int data) {
    if (List == NULL) {
        return -1;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -2;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (List->head == NULL) {
        List->head = new_node;
    } else {
        Node *current_node = List->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    List->size++;
    return 0;
}

int insert_at(LinkedList *List, int data, int index) {
    if (List == NULL) {
        return -1;
    }

    if (index < 0 || index > List->size) {
        return -3;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -2;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = List->head;
        List->head = new_node;
    } else {
        Node *current_node = List->head;

        for (int count = 0; count < index - 1; count++) {
            current_node = current_node->next;
        }

        new_node->next = current_node->next;
        current_node->next = new_node;
    }

    List->size++;
    return 0;
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
    if (List->head == NULL) {
        return -2;
    }
    if (index < 0 || index >= List->size) {
        return -3;
    }

    Node *node_to_remove = NULL;

    if (index == 0) {
        node_to_remove = List->head;
        List->head = List->head->next;
    } else {
        Node *current_node = List->head;

        for (int count = 0; count < index - 1; count++) {
            current_node = current_node->next;
        }

        node_to_remove = current_node->next;
        current_node->next = node_to_remove->next;
    }

    free(node_to_remove);
    List->size--;
    return 0;
}