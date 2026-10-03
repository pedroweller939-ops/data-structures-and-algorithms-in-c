#include <stdio.h>
#include "static-ordered-list.h"


int main() {

    List list;

    // 1. Initialization
    init_list(&list);
    printf("=== Initialization Test ===\n");
    printf("Is list empty? %s\n\n", is_empty(&list) ? "Yes" : "No");

    // 2. Ordered Insertion (inserting out of order to verify automatic sorting)
    printf("=== Ordered Insertion Test ===\n");
    insert_ord(30, &list);
    insert_ord(10, &list);
    insert_ord(50, &list);
    insert_ord(20, &list);
    insert_ord(40, &list);

    print_list(&list);
    printf("\n");

    // 3. Binary Search (get_index)
    printf("=== Search Test (get_index) ===\n");
    int val_search = 30;
    int idx = get_index(val_search, &list);
    if (idx != -1) {
        printf("Value %d found at index: %d\n", val_search, idx);
    } else {
        printf("Value %d not found.\n", val_search);
    }

    val_search = 99; // Testing non-existent value
    idx = get_index(val_search, &list);
    if (idx != -1) {
        printf("Value %d found at index: %d\n", val_search, idx);
    } else {
        printf("Value %d not found.\n", val_search);
    }
    printf("\n");

    // 4. Removal
    printf("=== Removal Test ===\n");
    printf("Removing 30 (middle)...\n");
    remove_value(30, &list);
    print_list(&list);

    printf("Removing 10 (first)...\n");
    remove_value(10, &list);
    print_list(&list); //

    printf("Removing 50 (last)...\n");
    remove_value(50, &list);
    print_list(&list);
    printf("\n");

    // 5. Clear
    printf("=== Clear Test ===\n");
    clear(&list);
    printf("List after clear:\n");
    print_list(&list);
    printf("Is list empty? %s\n", is_empty(&list) ? "Yes" : "No");

    return 0;
}