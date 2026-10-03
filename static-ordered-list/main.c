#include <stdio.h>
#include "static-ordered-list.h"

int main(void) {


    printf("     STATIC ORDERED LIST TEST PROGRAM\n");


    // 1. Initializing the list
    printf("=== 1. Initializing List ===\n");
    List list;
    init_list(&list);

    printf("List initialized. Initial Size : %d\n", size(&list));
    printf("Is Empty?                     : %s\n\n", is_empty(&list) ? "Yes" : "No");

    // 2. Testing Ordered Insertions
    printf("=== 2. Testing Ordered Insertions ===\n");

    printf("Inserting 30, 10, 20, 5, 40...\n");
    insert_ord(30, &list);
    insert_ord(10, &list);
    insert_ord(20, &list);
    insert_ord(5, &list);
    insert_ord(40, &list);

    printf("\nCurrent List (Size %d) : ", size(&list));
    print_list(&list);
    printf("\n");

    // 3. Testing Binary Search (get_index)
    printf("=== 3. Testing Binary Search ===\n");
    int val_search = 30;

    // Corrigido: passagem correta (&list, val_search)
    int idx = get_index(&list, val_search);
    if (idx >= 0) {
        printf("Value %d found at index : %d (Expected: 3)\n", val_search, idx);
    } else {
        printf("Value %d not found. Error code : %d\n", val_search, idx);
    }

    val_search = 99; // Testing non-existent value
    idx = get_index(&list, val_search);
    if (idx >= 0) {
        printf("Value %d found at index : %d\n", val_search, idx);
    } else {
        printf("Value %d search result  : %d (Expected error -3: Not found)\n\n", val_search, idx);
    }

    // 4. Testing Removals
    printf("=== 4. Testing Removals ===\n");

    printf("Removing value 20...\n");
    int status = remove_value(20, &list);
    printf("Removal result code : %d (Expected: 0)\n", status);

    printf("\nCurrent List (Size %d) : ", size(&list));
    print_list(&list);
    printf("\n");

    // 5. Testing Operations on Empty List / Reset
    printf("=== 5. Clearing List & Edge Cases ===\n");
    clear(&list);
    printf("Size after clear : %d\n", size(&list));

    status = remove_value(10, &list);
    printf("Removing from empty list result : %d (Expected error -2: Empty list)\n\n", status);


    printf("              TEST RUN COMPLETED\n");

    return 0;
}