/*
     RETURN CODES TABLE

    0 : Success;
   -1 : Invalid tree pointer or data pointer (NULL);
   -2 : Memory allocation failure (Heap full / Out of memory);
   -3 : Tree is empty / Element not found;
   -4 : Duplicate element insertion attempt;
*/


#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h"

BST*  bst_criar(void) {

    BST *tree = (BST *) malloc(sizeof(BST));

    if (tree != NULL) {
        tree -> root = NULL;

    }
    return tree;


}

bool isEmptyBST(const BST *tree) {

    if (tree == NULL) {
        return true;

    }

    return (tree -> root == NULL);

}

int getMinBST(const BST *tree, int *min_value) {

    if (tree == NULL || min_value == NULL) {
        return -1;

    }
    if (tree -> root == NULL) {
        return -3;

    }

    Node *aux = tree -> root;
    while (aux -> left != NULL) {

        aux = aux -> left;

    }

    *min_value = aux -> data;
    return 0;


}

int getMaxBST(const BST *tree, int *max_value) {

    if (tree == NULL || max_value == NULL) {
        return -1;

    }
    if (tree -> root == NULL) {
        return -3;

    }

    Node *aux = tree -> root;
    while (aux -> right != NULL) {

        aux = aux -> right;

    }

    *max_value = aux -> data;
    return 0;

}

bool searchBST(const BST *tree, int data) {

    if (tree == NULL) {
        return false;

    }
    if (tree -> root == NULL) {
        return false;

    }

    Node *aux = tree -> root;

    while (aux != NULL) {

        if (aux -> data == data) {
            return true;

        }

        if (aux -> data > data) {
            aux = aux -> left;

        } else {
            aux = aux -> right;

        }
    }

    return false;
}



