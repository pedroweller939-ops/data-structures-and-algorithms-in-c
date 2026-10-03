#ifndef DATA_STRUCTURES_STATIC_QUEUE_H
#define DATA_STRUCTURES_STATIC_QUEUE_H
#include <stdbool.h>
#define MAX 100

typedef struct QUEUE {

    int data[MAX];
    int front;
    int rear;
    int size;

} Queue;

Queue* createQueue();
int enqueue(Queue *queue, int data);
int dequeue(Queue *queue, int *data);
int peek(Queue *queue, int *data);
int printQueue(Queue *queue);
bool isEmpty(const Queue *queue);
bool isFull(const Queue *queue);
int freeQueue(Queue *queue);


#endif //DATA_STRUCTURES_STATIC_QUEUE_H
