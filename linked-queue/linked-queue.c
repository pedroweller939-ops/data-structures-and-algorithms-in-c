/*
     RETURN CODES TABLE - LINKED QUEUE

       0 : Success;
      -1 : Invalid queue pointer or data pointer (NULL);
      -2 : Memory allocation failure (Heap full / Out of memory);
      -3 : Queue is empty (Queue Underflow);
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked-queue.h"

Queue *createQueue() {

    Queue  *queue = (Queue*)malloc(sizeof(Queue));
    if (queue != NULL) {

        queue -> front = NULL;
        queue -> rear = NULL;
        queue -> size = 0;

    }

    return queue;
}

int enqueue(Queue *queue, int data) {

    if (queue == NULL) {

        return -1;

    }

    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        return -2;

    }

    new_node -> data = data;
    new_node -> next = NULL;

    if (queue -> size == 0) {

        queue -> front = queue -> rear = new_node;

    } else {

        queue -> rear -> next = new_node;
        queue -> rear = new_node;

    }
    queue -> size++;
    return 0;
}

int dequeue(Queue *queue, int *data) {

    if (queue == NULL || data == NULL) {

        return -1;

    }

    if (queue -> size == 0) {
        return -3;

    }

    *data = queue -> front -> data;
    Node *to_remove = queue -> front;
    queue -> front = queue -> front -> next;

    if (queue -> front ==  NULL) {
        queue -> rear = NULL;
    }

    free(to_remove);
    queue -> size--;
    return 0;

}

int peek(Queue *queue, int *data) {

    if (queue == NULL || data == NULL) {

        return -1;

    }

    if (queue -> size == 0) {

        return -3;

    }

    *data = queue -> front -> data;
    return 0;

}
int printQueue(Queue *queue) {

    if (queue == NULL) {
        return -1;

    }

    if (queue -> size == 0) {
        return -3;

    }

    Node *temp = queue -> front;
    while (temp != NULL) {

        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    printf("\n");
    return 0;
}

bool isEmpty(const Queue *queue) {

    if (queue == NULL) {
        return true;
    }

    return (queue -> size == 0);
}

int freeQueue(Queue *queue) {

    if (queue == NULL) {
        return -1;

    }
    Node *temp = queue -> front;
    Node *aux = NULL;

    while (temp != NULL) {

        aux = temp;
        temp = temp -> next;
        free(aux);

    }

    free(queue);
    return 0;

}

