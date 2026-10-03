/*
RETURN CODES TABLE - STATIC STACK

       0 : Success;
      -1 : Invalid stack pointer (NULL);
      -2 : Stack is full (Stack Overflow);
      -3 : Stack is empty (Stack Underflow);
*/



#include "static-stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Stack* createStack() {

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack != NULL) {
        stack -> top = -1;
    }
    return stack;
}

int push(Stack *stack, int data) {

    if (stack == NULL) {
        return -1;

    }

    if (stack -> top >= STACK_SIZE - 1) {
        return -2;

    }

    stack -> top++;
    stack -> data[stack -> top] = data;
    return 0;

}

int pop(Stack *stack, int *data) {

    if (stack == NULL || data == NULL) {
        return -1;

    }

    if (stack -> top == -1) {
        return -3;

    }

    *data = stack -> data[stack -> top];
    stack -> top--;
    return 0;

}

int printStack(Stack *stack) {

    if (stack == NULL) {
        return -1;

    }

    if (stack -> top == -1) {
        return -3;

    }

    for (int i = stack -> top; i >=0; i--) {

        printf("%d ", stack -> data[i]);

    }
    printf("\n");
    return 0;

}

int peek(const Stack *stack, int *data) {

    if (stack == NULL || data == NULL) {
        return -1;

    }
    if (stack -> top == -1) {
        return -3;

    }

    *data = stack -> data[stack -> top];
    return 0;

}

bool isEmpty(Stack *stack) {

    if (stack == NULL) {
        return false;
    }
    return (stack -> top == -1);

}

bool isFull(Stack *stack) {

    if (stack == NULL) {
        return false;

    }
    return (stack -> top == STACK_SIZE - 1);

}




