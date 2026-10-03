#ifndef DATA_STRUCTURES_LINKED_QUEUE_H
#define DATA_STRUCTURES_LINKED_QUEUE_H
#include <stdbool.h>

typedef struct NODE {
    int data;
    struct NODE *next;

} Node;

typedef struct QUEUE {

    Node *front;
    Node *rear;
    int size;


} Queue;

Queue *createQueue();
int enqueue(Queue *queue, int data);
int dequeue(Queue *queue, int *data);
int peek(Queue *queue, int *data);
int printQueue(Queue *queue);
bool isEmpty(const Queue *queue);
int freeQueue(Queue *queue);













#endif //DATA_STRUCTURES_LINKED_QUEUE_H
