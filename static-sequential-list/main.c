#include <stdio.h>
#include "static_sequential_list.h"

int main(void) {


    printf("    STATIC SEQUENTIAL LIST TEST PROGRAM\n");


    // 1. Initializing lists
    printf("=== 1. Initializing Lists ===\n");
    List list_a, list_b;

    init_list(&list_a);
    init_list(&list_b);

    printf("List A initialized. Initial Size : %d\n", size(&list_a));
    printf("List B initialized. Initial Size : %d\n\n", size(&list_b));

    // 2. Testing Insertions
    printf("=== 2. Testing Insertions ===\n");

    printf("Inserting elements into List A...\n");
    insert_ord(10, &list_a);
    insert_ord(20, &list_a);
    insert_ord(30, &list_a);

    printf("Inserting elements into List B...\n");
    insert_ord(100, &list_b);
    insert_ord(200, &list_b);

    printf("\n--- List A (Size: %d) ---\n", size(&list_a));
    print_list(&list_a);

    printf("\n--- List B (Size: %d) ---\n", size(&list_b));
    print_list(&list_b);

    // 3. Testing Search and Retrieval
    printf("\n=== 3. Testing Search and Retrieval ===\n");
    int value = 0;

    int status = get_value(&list_a, 1, &value);
    if (status == 0) {
        printf("Value at index 1 of List A : %d (Expected: 20)\n", value);
    } else {
        printf("Failed to get value. Error code: %d\n", status);
    }

    int index = search(&list_a, 30);
    printf("Index of value 30 in List A: %d (Expected: 2)\n\n", index);

    // 4. Testing Removals
    printf("=== 4. Testing Removals ===\n");

    printf("Removing value 20 from List A...\n");
    status = remove_value(20, &list_a);
    printf("Removal result code        : %d (Expected: 0)\n", status);

    printf("\n--- List A after removing 20 (Size: %d) ---\n", size(&list_a));
    print_list(&list_a);

    // 5. Testing Error Codes / Edge Cases
    printf("\n=== 5. Testing Return Codes & Edge Cases ===\n");

    status = remove_value(999, &list_a);
    printf("Removing non-existent value result : %d (Expected error -3: Not found)\n", status);

    status = get_value(&list_a, 10, &value);
    printf("Accessing out-of-bounds index result : %d (Expected error -3: Out of bounds)\n", status);

    status = init_list(NULL);
    printf("Passing NULL pointer result          : %d (Expected error -1: Invalid pointer)\n\n", status);

    // 6. Clearing List
    printf("=== 6. Clearing List ===\n");
    clear(&list_a);
    printf("List A Size after clear : %d\n\n", size(&list_a));


    printf("              TEST RUN COMPLETED\n");


    return 0;
}