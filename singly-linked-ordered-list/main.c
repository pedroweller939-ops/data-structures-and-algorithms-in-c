#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-ordered-list.h"

int main(void) {

    printf("    SINGLY LINKED ORDERED LIST TEST PROGRAM\n");

    // 1. Initializing and verifying list creation
    printf("=== 1. Creating the List ===\n");
    LinkedList *list = create_list();

    if (list == NULL) {
        printf("Error: Failed to allocate memory for the list.\n");
        return 1;
    }
    printf("List successfully created!\n");
    printf("Initial Size : %d\n", get_size(list));
    printf("Is Empty?    : %s\n\n", is_empty(list) ? "Yes" : "No");

    // 2. Testing ordered insertion logic
    printf("=== 2. Testing Ordered Insertions ===\n");

    printf("Inserting 30...\n");
    insert(list, 30);

    printf("Inserting 10 (should become the new head)...\n");
    insert(list, 10);

    printf("Inserting 20 (should be inserted between 10 and 30)...\n");
    insert(list, 20);

    printf("Inserting 5  (should become the new head)...\n");
    insert(list, 5);

    printf("Inserting 40 (should be appended at the tail)...\n");
    insert(list, 40);

    printf("\nCurrent List : ");
    print_list(list);
    printf("Current Size : %d\n\n", get_size(list));

    // 3. Testing lookup and element retrieval
    printf("=== 3. Testing Search and Retrieval ===\n");
    int value = 0;

    int status = get_data(list, 2, &value);
    if (status == 0) {
        printf("Value at index 2 : %d (Expected: 20)\n", value);
    } else {
        printf("Failed to retrieve data at index 2. Error code: %d\n", status);
    }

    int index = get_index(list, 30);
    printf("Index of value 30 : %d (Expected: 3)\n", index);

    printf("Contains 20?     : %s\n", contains(list, 20) ? "Yes" : "No");
    printf("Contains 99?     : %s (Early exit optimization check)\n\n", contains(list, 99) ? "Yes" : "No");

    // 4. Testing boundary checks and invalid parameters
    printf("=== 4. Testing Invalid Operations ===\n");

    status = get_data(list, 10, &value);
    printf("Accessing index 10 result : %d (Expected error -3: Out of bounds)\n", status);

    index = get_index(list, 15);
    printf("Searching value 15 result : %d (Expected error -3: Element not found)\n\n", index);

    // 5. Testing node removal logic
    printf("=== 5. Testing Removals ===\n");

    printf("Removing element at index 2 (value 20)...\n");
    remove_at(list, 2);
    printf("Current List : ");
    print_list(list);

    printf("Removing head element (index 0)...\n");
    remove_at(list, 0);
    printf("Current List : ");
    print_list(list);

    printf("Removing tail element...\n");
    remove_last(list);
    printf("Current List : ");
    print_list(list);

    printf("Final Size   : %d\n\n", get_size(list));

    // 6. Testing list clearing and reset
    printf("=== 6. Clearing the List ===\n");
    clear_list(list);

    printf("Current List : ");
    print_list(list);
    printf("Size after clear : %d\n", get_size(list));
    printf("Is Empty?        : %s\n\n", is_empty(list) ? "Yes" : "No");

    // 7. Testing operations on an empty structure
    printf("=== 7. Testing Operations on Empty List ===\n");
    status = remove_last(list);
    printf("Removing from empty list result : %d (Expected error -2: Empty list)\n\n", status);

    free(list);


    printf("              TEST RUN COMPLETED\n");


    return 0;
}