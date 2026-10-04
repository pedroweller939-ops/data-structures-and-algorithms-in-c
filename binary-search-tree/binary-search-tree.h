#include <stdbool.h>

#ifndef DATA_STRUCTURES_BINARY_SEARCH_TREE_H
#define DATA_STRUCTURES_BINARY_SEARCH_TREE_H


typedef struct Node {

    int data;
    struct Node *left;
    struct Node *right;

} Node;


typedef struct BST {

    Node *root;
} BST;


BST*  bst_criar(void); //
int freeBST(BST *tree);
int insertBST(BST *tree, int data);
int removeBST(BST *tree, int data);
bool searchBST(const BST *tree, int data); //
bool isEmptyBST(const BST *tree); //
int getSizeBST(const BST *tree); //
int getHeightBST(const BST *tree); //
int getMinBST(const BST *tree, int *min_value); //
int getMaxBST(const BST *tree, int *max_value); //
int printInOrder(const BST *tree); //
int printPreOrder(const BST *tree); //
int printPostOrder(const BST *tree); //


#endif //DATA_STRUCTURES_BINARY_SEARCH_TREE_H
