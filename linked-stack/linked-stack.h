#ifndef DATA_STRUCTURES_LINKED_STACK_H
#define DATA_STRUCTURES_LINKED_STACK_H
#include <stdbool.h>

typedef struct Node {

    int data;
    struct Node *next;

} Node;

typedef struct STACK {

    Node *top;
    int size;

} Stack;

Stack* createStack();
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
int printStack(Stack *stack);
int freeStack(Stack *stack);
int peek(const Stack *stack, int *data);
bool isEmpty(Stack *stack);

#endif //DATA_STRUCTURES_LINKED_STACK_H
