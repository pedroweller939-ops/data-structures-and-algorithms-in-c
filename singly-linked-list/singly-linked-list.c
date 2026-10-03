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
    if (out_value == NULL) {
        return -1; // out_value pointer is NULL
    }
    if (List == NULL) {
        return -2; // Invalid list pointer
    }
    if (List->head == NULL) {
        return -3; // List is empty
    }
    if (index < 0 || index >= List->size) {
        return -4; // Index out of bounds
    }

    Node *current_node = List->head;

    for (int count = 0; count < index; count++) {
        current_node = current_node->next;

        if (current_node == NULL) {
            return -5; // Corrupted list (unexpected NULL node)
        }
    }

    *out_value = current_node->data; // Success
    return 0;
}

int get_index(LinkedList *List, int data) {
    if (List == NULL) {
        return -1; // List pointer is NULL
    }
    if (List->head == NULL) {
        return -2; // List is empty
    }

    Node *current_node = List->head;

    for (int count = 0; count < List->size; count++) {
        if (current_node == NULL) {
            return -3; // Corrupted list (unexpected NULL node)
        }

        if (current_node->data == data) {
            return count; // Success: returns matching index
        }

        current_node = current_node->next;
    }

    return -4; // Data not found in list
}

int contains(LinkedList *List, int data) {
    int exists = get_index(List, data);

    if (exists >= 0) {
        return 1; // Found
    }

    return 0; // Not found or error
}

int print_list(LinkedList *List) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }
    if (List->head == NULL) {
        printf("List is empty.\n");
        return -2; // List is empty
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
        return 1; // True: List is empty or NULL
    }
    return 0; // False: List contains elements
}

int get_size(LinkedList *List) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }
    if (List->head == NULL) {
        return 0; // Empty list has size 0
    }

    return List->size;
}

int clear_list(LinkedList *List) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }
    if (List->head == NULL) {
        return 0; // List is already empty
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
    return 0; // Success
}

int insert_last(LinkedList *List, int data) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -2; // Memory allocation failed
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
    return 0; // Success
}

int insert_at(LinkedList *List, int data, int index) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }

    if (index < 0 || index > List->size) {
        return -2; // Invalid index position
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -3; // Memory allocation failed
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
    return 0; // Success
}

int remove_last(LinkedList *List) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }
    if (List->head == NULL) {
        return -2; // List is empty, nothing to remove
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
    return 0; // Success
}

int remove_at(LinkedList *List, int index) {
    if (List == NULL) {
        return -1; // Invalid list pointer
    }
    if (List->head == NULL) {
        return -2; // List is empty, nothing to remove
    }
    if (index < 0 || index >= List->size) {
        return -3; // Invalid index position
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
    return 0; // Success
}
