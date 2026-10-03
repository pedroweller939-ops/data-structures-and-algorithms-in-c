#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-ordered-list.h"

int main(void) {

    printf("    SINGLY LINKED ORDERED LIST TEST PROGRAM\n\n");

    // 1. Creating the list
    printf(" === Creating the list ===\n");
    LinkedList *list = create_list();

    if (list == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }
    printf("List created!\n");
    printf("Initial Size: %d\n", get_size(list));
    printf("Is Empty? %s\n\n", is_empty(list) ? "Yes" : "No");

    // 2. Inserting elements (Automatic Order Testing)
    printf("=== Testing Ordered Insertions ===\n");

    printf("Inserting 30...\n");
    insert(list, 30);

    printf("Inserting 10 (should be placed at head)...\n");
    insert(list, 10);

    printf("Inserting 20 (should be placed between 10 and 30)...\n");
    insert(list, 20);

    printf("Inserting 5 (should be placed at new head)...\n");
    insert(list, 5);

    printf("Inserting 40 (should be placed at tail)...\n");
    insert(list, 40);

    printf("\nCurrent list: ");
    print_list(list);
    printf("Current Size: %d\n\n", get_size(list));

    // 3. Testing Search and Retrieval
    printf("=== Testing Search and Retrieval ===\n");
    int value = 0;

    // Get data at index 2
    int status = get_data(list, 2, &value);
    if (status == 0) {
        printf("Value at index 2: %d (Expected 20)\n", value);
    } else {
        printf("Failed to get data at index 2. Error code: %d\n", status);
    }

    int index = get_index(list, 30);
    printf("Index of value 30: %d (Expected 3)\n", index);

    printf("Contains 20? %d\n", contains(list, 20));
    printf("Contains 99? %d (Order optimization test)\n\n", contains(list, 99));

    // 4. Testing Invalid / Edge Operations
    printf("=== Testing Invalid Operations ===\n");

    status = get_data(list, 10, &value);
    printf("Index 10 result: %d (Expected error -3: Out of bounds)\n", status);

    index = get_index(list, 15);
    printf("Search for 15 result: %d (Expected error -3: Early exit optimization)\n\n", index);

    // 5. Testing Removals
    printf("=== Testing Removals ===\n");

    printf("Removing element at index 2 (value 20)...\n");
    remove_at(list, 2);
    printf("Current list: ");
    print_list(list);

    printf("Removing first element (index 0)...\n");
    remove_at(list, 0);
    printf("Current list: ");
    print_list(list);

    printf("Removing last element...\n");
    remove_last(list);
    printf("Current list: ");
    print_list(list);

    printf("Final Size: %d\n\n", get_size(list));

    // 6. Clearing the List
    printf("=== Clearing the List ===\n");
    clear_list(list);

    printf("Current list: ");
    print_list(list);
    printf("Size after clearing: %d\n", get_size(list));
    printf("Is Empty? %s\n\n", is_empty(list) ? "Yes" : "No");

    // 7. Testing Operations on Empty List
    printf("=== Testing Operations on Empty List ===\n");
    status = remove_last(list);
    printf("Removing from empty list result: %d (Expected error -2)\n\n", status);

    free(list);

    printf("        TEST COMPLETED\n");

    return 0;
}