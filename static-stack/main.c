#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "static-stack.h"

int main(void) {

    printf("            STATIC STACK TEST PROGRAM (DYNAMIC ALLOCATION)\n\n");

    // 1. Initializing Stacks using createStack()
    printf("=== 1. Initializing Stacks ===\n");
    Stack *stack_a = createStack();
    Stack *stack_b = createStack();

    if (stack_a == NULL || stack_b == NULL) {
        printf("Failed to allocate memory for stacks.\n");
        return -1;
    }

    printf("Stack A created. isEmpty: %s\n", isEmpty(stack_a) ? "true" : "false");
    printf("Stack B created. isEmpty: %s\n\n", isEmpty(stack_b) ? "true" : "false");

    // 2. Testing Push (Insertions)
    printf("=== 2. Testing Push (Insertions) ===\n");

    printf("Pushing elements into Stack A (10, 20, 30)...\n");
    push(stack_a, 10);
    push(stack_a, 20);
    push(stack_a, 30);

    printf("Pushing elements into Stack B (100, 200)...\n");
    push(stack_b, 100);
    push(stack_b, 200);

    printf("\n--- Stack A ---\n");
    printStack(stack_a);

    printf("\n--- Stack B ---\n");
    printStack(stack_b);

    // 3. Testing Peek / Querying Top
    printf("\n=== 3. Testing Peek / Top Element ===\n");
    int value = 0;

    int status = peek(stack_a, &value);
    if (status == 0) {
        printf("Top element of Stack A : %d (Expected: 30)\n", value);
    } else {
        printf("Failed to peek. Error code: %d\n", status);
    }

    printf("Is Stack A full?  : %s (Expected: false)\n", isFull(stack_a) ? "true" : "false");
    printf("Is Stack A empty? : %s (Expected: false)\n\n", isEmpty(stack_a) ? "true" : "false");

    // 4. Testing Pop (Removals)
    printf("=== 4. Testing Pop (Removals) ===\n");

    status = pop(stack_a, &value);
    printf("Popped element from Stack A : %d (Result code: %d, Expected: 0)\n", value, status);

    printf("\n--- Stack A after 1 Pop ---\n");
    printStack(stack_a);

    // 5. Testing Error Codes & Edge Cases
    printf("\n=== 5. Testing Return Codes & Edge Cases ===\n");

    // Esvaziando Stack B para testar Underflow
    pop(stack_b, &value);
    pop(stack_b, &value);

    printf("\n--- Stack B after removing all elements ---\n");
    printStack(stack_b);

    status = pop(stack_b, &value);
    printf("Popping from empty Stack B   : %d (Expected error -3: Underflow)\n", status);

    status = push(NULL, 50);
    printf("Pushing to NULL pointer     : %d (Expected error -1: Invalid pointer)\n", status);

    status = pop(NULL, &value);
    printf("Popping from NULL pointer    : %d (Expected error -1: Invalid pointer)\n\n", status);

    // 6. Testing Stack Overflow
    printf("=== 6. Testing Stack Overflow ===\n");
    printf("Filling Stack A to its maximum capacity...\n");

    while (!isFull(stack_a)) {
        push(stack_a, 99);
    }

    printf("Stack A is now full. Attempting one more push...\n");
    status = push(stack_a, 999);
    printf("Pushing to full Stack A      : %d (Expected error -2: Stack Overflow)\n\n", status);

    // 7. Freeing Memory
    printf("=== 7. Freeing Memory ===\n");
    free(stack_a);
    free(stack_b);
    printf("Memory freed successfully.\n\n");

    printf("               TEST RUN COMPLETED\n");

    return 0;
}