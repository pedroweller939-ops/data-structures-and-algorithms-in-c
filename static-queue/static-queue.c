/*
RETURN CODES TABLE - STATIC QUEUE

       0 : Success;
      -1 : Invalid queue pointer or data pointer (NULL);
      -2 : Queue is full (Queue Overflow / Capacity limit reached);
      -3 : Queue is empty (Queue Underflow);
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "static-queue.h"

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->front = 0;
        queue->rear = 0;
        queue->size = 0;
    }
    return queue;
}

int enqueue(Queue *queue, int data) {
    if (queue == NULL) {
        return -1;
    }

    if (queue->size >= MAX) {
        return -2;
    }

    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAX;
    queue->size++;

    return 0;
}

int dequeue(Queue *queue, int *data) {
    if (queue == NULL || data == NULL) {
        return -1;
    }

    if (queue->size == 0) {
        return -3;
    }

    *data = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;

    return 0;
}

int peek(Queue *queue, int *data) {
    if (queue == NULL || data == NULL) {
        return -1;
    }

    if (queue->size == 0) {
        return -3;
    }

    *data = queue->data[queue->front];
    return 0;
}

int printQueue(Queue *queue) {
    if (queue == NULL) {
        return -1;
    }

    if (queue->size == 0) {
        return -3;
    }

    int index = queue->front;

    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % MAX;
    }

    printf("\n");
    return 0;
}

bool isEmpty(const Queue *queue) {
    if (queue == NULL) {
        return true;
    }

    return (queue->size == 0);
}

bool isFull(const Queue *queue) {
    if (queue == NULL) {
        return false;
    }

    return (queue->size == MAX);
}

int freeQueue(Queue *queue) {
    if (queue == NULL) {
        return -1;
    }

    free(queue);
    return 0;
}