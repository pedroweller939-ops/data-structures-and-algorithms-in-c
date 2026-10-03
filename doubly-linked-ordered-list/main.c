#include <stdio.h>
#include <stdlib.h>
#include "doubly-linked-ordered-list.h"

int main(void) {

    printf("        DOUBLY LINKED ORDERED LIST TEST PROGRAM\n\n");

    // 1. Initializing and verifying list creation
    printf("=== 1. Creating the List ===\n");
    DoublyLinkedList *list = create_list();

    if (list == NULL) {
        printf("Error: Failed to allocate memory for the list.\n");
        return 1;
    }
    printf("List created!\n");
    printf("Initial Size : %d\n", getsize(list));
    printf("Is Empty?    : %s\n\n", is_empty(list) ? "Yes" : "No");

    // 2. Testing ordered insertions (out of order input)
    printf("=== 2. Testing Ordered Insertions ===\n");

    printf("Inserting 30...\n");
    insert(list, 30);

    printf("Inserting 10 (head position)...\n");
    insert(list, 10);

    printf("Inserting 50 (tail position)...\n");
    insert(list, 50);

    printf("Inserting 20 (middle position)...\n");
    insert(list, 20);

    printf("Inserting 40 (middle position)...\n");
    insert(list, 40);

    printf("\nForward List  : ");
    print_forward(list);
    printf("Current Size  : %d\n\n", getsize(list));

    // 3. Testing lookup and early-exit search retrieval
    printf("=== 3. Testing Search and Early-Exit Retrieval ===\n");

    int value = getdata(list, 2);
    if (value >= 0) {
        printf("Value at index 2 : %d (Expected: 30)\n", value);
    } else {
        printf("Failed to retrieve data at index 2. Error code: %d\n", value);
    }

    int index = getindex(list, 40);
    printf("Index of value 40 : %d (Expected: 3)\n", index);

    printf("Contains 20?     : %s\n", contains(list, 20) ? "Yes" : "No");
    printf("Contains 25? (Early Exit Test) : %s\n\n", contains(list, 25) ? "Yes" : "No");

    // 4. Testing boundary checks and invalid parameters
    printf("=== 4. Testing Invalid Operations ===\n");

    int status = getdata(list, 10);
    printf("Accessing index 10 result : %d (Expected error -3: Out of bounds)\n", status);

    status = getindex(list, 99);
    printf("Searching non-existing value 99 : %d (Expected error -3: Not found)\n\n", status);

    // 5. Testing node removal logic
    printf("=== 5. Testing Removals ===\n");

    printf("Removing element at index 2 (value 30)...\n");
    remove_at(list, 2);
    printf("Forward List  : ");
    print_forward(list);

    printf("Removing head element (index 0)...\n");
    remove_first(list);
    printf("Forward List  : ");
    print_forward(list);

    printf("Removing tail element...\n");
    remove_last(list);
    printf("Forward List  : ");
    print_forward(list);

    printf("Final Size    : %d\n\n", getsize(list));

    // 6. Testing list clearing and reset
    printf("=== 6. Clearing the List ===\n");
    clear_list(list);

    printf("Forward List  : ");
    print_forward(list);
    printf("Size after clear : %d\n", getsize(list));
    printf("Is Empty?        : %s\n\n", is_empty(list) ? "Yes" : "No");

    // 7. Testing operations on an empty structure
    printf("=== 7. Testing Operations on Empty List ===\n");
    status = remove_last(list);
    printf("Removing from empty list result : %d (Expected error -2: Empty list)\n", status);

    status = remove_first(list);
    printf("Removing first from empty list result : %d (Expected error -2: Empty list)\n\n", status);

    // 8. Testing safety checks with NULL pointers
    printf("=== 8. Testing NULL Pointer Operations ===\n");
    printf("getsize(NULL)      : %d (Expected error -1: Invalid pointer)\n", getsize(NULL));
    printf("is_empty(NULL)     : %d (Expected error -1: Invalid pointer)\n", is_empty(NULL));
    printf("contains(NULL, 10) : %d (Expected error -1: Invalid pointer)\n\n", contains(NULL, 10));

    // 9. Safely destroying the list structure
    printf("=== 9. Destroying the List ===\n");
    destroy_list(&list);

    if (list == NULL) {
        printf("List destroyed and pointer set to NULL!\n\n");
    } else {
        printf("Error: List pointer was not set to NULL.\n\n");
    }

    printf("              TEST RUN COMPLETED\n");

    return 0;
}