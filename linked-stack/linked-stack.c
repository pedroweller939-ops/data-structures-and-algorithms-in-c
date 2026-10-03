/*
RETURN CODES TABLE - LINKED STACK

       0 : Success;
      -1 : Invalid stack pointer or data pointer (NULL);
      -2 : Dynamic memory allocation failure (Stack Overflow / Out of Memory);
      -3 : Stack is empty (Stack Underflow);
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked-stack.h"

Stack* createStack() {

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack != NULL) {

        stack -> top = NULL;
        stack -> size = 0;
    }
    return stack;

}

int push(Stack *stack, int data) {

    if (stack == NULL) {

        return -1;

    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {

        return -2;

    }
    new_node -> data = data;
    new_node -> next = stack -> top;
    stack -> top = new_node;
    stack -> size++;
    return 0;

}
int pop(Stack *stack, int *data) {

    if (stack == NULL || data == NULL) {
        return -1;

    }

    if (stack -> top == NULL) {
        return -3;

    }

    Node *to_pop = stack -> top;
    *data = to_pop -> data;
    stack -> top = stack -> top -> next;
    free(to_pop);
    stack -> size--;
    return 0;
}

int printStack(Stack *stack) {

    if (stack == NULL) {
        return -1;

    }

    if (stack -> top == NULL) {
        return -3;
    }

    Node *to_print = stack -> top;
    while (to_print != NULL) {

        printf("%d ", to_print -> data);
        to_print = to_print -> next;

    }
    printf("\n");

    return 0;

}

int peek(const Stack *stack, int *data) {

    if (stack == NULL || data == NULL) {
        return -1;

    }

    if (stack -> top == NULL) {
        return -3;

    }
    *data = stack -> top -> data;
    return 0;
}

bool isEmpty(Stack *stack) {

    if (stack == NULL) {
        return false;

    }
    return (stack -> top == NULL);
}

int freeStack(Stack *stack) {

    if (stack == NULL) {
        return -1;

    }
    Node *to_free = stack -> top;
    Node *aux = NULL;

    while (to_free != NULL) {

        aux = to_free;
        to_free = to_free -> next;
        free(aux);

    }
    free(stack);
    return 0;
}





























