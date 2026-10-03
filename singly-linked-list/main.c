#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

int main(void) {

    printf("   SINGLY LINKED LIST TEST PROGRAM\n\n");

    printf(" === Creating the list ===\n");
    LinkedList *list = create_list();

    if (list == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }
    printf("List created!\n");
    printf("Initial Size: %d\n", get_size(list));
    printf("Is Empty? %s\n\n", is_empty(list) ? "Yes" : "No");

    // 2. Inserting elements
    printf("=== Testing Insertions ===\n");

    printf("Inserting 10 at the end...\n");
    insert_last(list, 10);

    printf("Inserting 30 at the end...\n");
    insert_last(list, 30);

    printf("Inserting 20 at index 1.\n");
    insert_at(list, 20, 1);

    printf("Inserting 5 at index 0.\n");
    insert_at(list, 5, 0);

    printf("Inserting 40 at index 4.\n");
    insert_at(list, 40, 4);

    printf("\nCurrent list: ");
    print_list(list);
    printf("Current Size: %d\n\n", get_size(list));

    printf("=== Testing Search and Retrieval ===\n");
    int value = 0;

    // Get data at index 2
    int status = get_data(list, 2, &value);
    if (status == 0) {
        printf("Value at index 2: %d\n", value);
    } else {
        printf("Failed to get data at index 2. Error code: %d\n", status);
    }


    int index = get_index(list, 30);
    printf("Index of value 30: %d\n", index);


    printf("Contains 20? %d\n", contains(list, 20));
    printf("Contains 99? %d\n\n", contains(list, 99));


    printf("=== Testing Invalid Operations ===\n");

    status = get_data(list, 10, &value);
    printf("Index 10 result: %d (Expected error -4)\n\n", status);

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


    printf("=== Clearing the List ===\n");
    clear_list(list);

    printf("Current list: ");
    print_list(list);
    printf("Size after clearing: %d\n", get_size(list));
    printf("Is Empty? %s\n\n", is_empty(list) ? "Yes" : "No");

    printf("=== Testing Operations on Empty List ===\n");
    status = remove_last(list);
    printf("Removing from empty list result: %d (Expected error -2)\n\n", status);

    free(list);

    printf("        TEST COMPLETED\n");


    return 0;
}