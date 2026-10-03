#include <stdio.h>
#include <stdbool.h>
#include "linked-queue.h"

int main(void) {

    printf("           LINKED QUEUE TEST PROGRAM\n\n");

    // 1. Initializing Queue
    printf("=== 1. Initializing Queue ===\n");
    Queue *queue = createQueue();

    if (queue == NULL) {
        printf("Failed to allocate memory for the queue.\n");
        return -1;
    }

    printf("Queue initialized successfully.\n");
    printf("Is queue empty? : %s (Expected: true)\n\n", isEmpty(queue) ? "true" : "false");

    // 2. Testing Insertions (Enqueue)
    printf("=== 2. Testing Enqueue ===\n");
    printf("Enqueuing elements: 10, 20, 30...\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Current Queue Content: ");
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

    printf("Queue Content After Dequeues: ");
    printQueue(queue);

    // 5. Testing Return Codes & Edge Cases
    printf("\n=== 5. Testing Return Codes & Edge Cases ===\n");

    // Test Null Pointer
    status = enqueue(NULL, 100);
    printf("Enqueueing to NULL queue          : %d (Expected error -1: Invalid pointer)\n", status);

    status = dequeue(queue, NULL);
    printf("Dequeuing with NULL data pointer   : %d (Expected error -1: Invalid pointer)\n", status);

    // Test Empty Queue Dequeue
    Queue *empty_queue = createQueue();
    status = dequeue(empty_queue, &removed_value);
    printf("Dequeuing from empty queue         : %d (Expected error -3: Underflow)\n", status);

    // 6. Freeing Memory
    printf("\n=== 6. Freeing Memory ===\n");
    status = freeQueue(queue);
    printf("Free main queue result            : %d (Expected: 0)\n", status);

    status = freeQueue(empty_queue);
    printf("Free empty queue result           : %d (Expected: 0)\n\n", status);

    printf("               TEST RUN COMPLETED\n");

    return 0;
}