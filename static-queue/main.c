#include <stdio.h>
#include <stdbool.h>
#include "static-queue.h"

int main(void) {

    printf("           STATIC QUEUE TEST PROGRAM\n\n");

    // 1. Initializing Queue
    printf("=== 1. Initializing Queue ===\n");
    Queue *queue = createQueue();

    if (queue == NULL) {
        printf("Failed to allocate memory for the queue.\n");
        return -1;
    }

    printf("Queue initialized successfully.\n");
    printf("Is queue empty? : %s (Expected: true)\n", isEmpty(queue) ? "true" : "false");
    printf("Is queue full?  : %s (Expected: false)\n\n", isFull(queue) ? "true" : "false");

    // 2. Testing Insertions (Enqueue)
    printf("=== 2. Testing Enqueue ===\n");
    printf("Enqueuing elements: 10, 20, 30...\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("\n--- Current Queue Content ---\n");
    printQueue(queue);

    // 3. Testing Peek
    printf("\n=== 3. Testing Peek ===\n");
    int front_value = 0;
    int status = peek(queue, &front_value);
    if (status == 0) {
        printf("Front element (peek): %d (Expected: 10)\n", front_value);
    } else {
        printf("Peek failed with status: %d\n", status);
    }

    // 4. Testing Removals (Dequeue)
    printf("\n=== 4. Testing Dequeue ===\n");
    int removed_value = 0;

    status = dequeue(queue, &removed_value);
    printf("Dequeued element: %d | Status code: %d (Expected: 0)\n", removed_value, status);

    status = dequeue(queue, &removed_value);
    printf("Dequeued element: %d | Status code: %d (Expected: 0)\n", removed_value, status);

    printf("\n--- Queue Content After Dequeues ---\n");
    printQueue(queue);

    // 5. Testing Circular Wrap-Around Behavior
    printf("\n=== 5. Testing Circular Wrap-Around ===\n");
    printf("Adding elements 40, 50, 60 to force index wrap-around...\n");
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    printf("\n--- Circular Queue Content ---\n");
    printQueue(queue);

    // 6. Testing Return Codes & Edge Cases
    printf("\n=== 6. Testing Return Codes & Edge Cases ===\n");

    // Test Null Pointer
    status = enqueue(NULL, 100);
    printf("Enqueueing to NULL queue          : %d (Expected error -1: Invalid pointer)\n", status);

    status = dequeue(queue, NULL);
    printf("Dequeuing with NULL data pointer   : %d (Expected error -1: Invalid pointer)\n", status);

    // Test Empty Queue Dequeue
    Queue *empty_queue = createQueue();
    status = dequeue(empty_queue, &removed_value);
    printf("Dequeuing from empty queue         : %d (Expected error -3: Underflow)\n", status);

    // 7. Freeing Memory
    printf("\n=== 7. Freeing Memory ===\n");
    status = freeQueue(queue);
    printf("Free main queue result            : %d (Expected: 0)\n", status);

    status = freeQueue(empty_queue);
    printf("Free empty queue result           : %d (Expected: 0)\n\n", status);

    printf("               TEST RUN COMPLETED\n");

    return 0;
}
