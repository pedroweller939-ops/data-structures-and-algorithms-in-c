#ifndef DATA_STRUCTURES_STATIC_STACK_H
#define DATA_STRUCTURES_STATIC_STACK_H
#define STACK_SIZE 100
#include <stdbool.h>

typedef struct Stack {

    int data[STACK_SIZE];
    int top;

} Stack;

Stack* createStack();
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
int printStack(Stack *stack);
int peek(const Stack *stack, int *data);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);



#endif //DATA_STRUCTURES_STATIC_STACK_H
