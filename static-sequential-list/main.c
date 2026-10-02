#include "static_sequential_list.h"
#include <stdio.h>

int main(void) {

    // Demonstration with two independent lists

    List list_a, list_b;

    init_list(&list_a);
    init_list(&list_b);

    // Operações na Lista A
    insert_ord(10, &list_a);
    insert_ord(20, &list_a);
    insert_ord(30, &list_a);

    // Operações na Lista B
    insert_ord(100, &list_b);
    insert_ord(200, &list_b);

    printf("--- List A (Size: %d) ---\n", size(&list_a));
    print_list(&list_a);

    printf("\n--- List B (Size: %d) ---\n", size(&list_b));
    print_list(&list_b);

    remove_value(20, &list_a);
    printf("\n--- List A after removing 20 ---\n");
    print_list(&list_a);

    return 0;
}