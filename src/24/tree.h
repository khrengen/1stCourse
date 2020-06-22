#ifndef BINTREE_H_
#define BINTREE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* tree_data_type;

typedef struct Node {
    tree_data_type data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
    int size;
} Bintree;

Node* createTree(tree_data_type value);
void copyTree(Node** out, Node* tree);
void addLeftTree(Node* tree, Node* in);
void addRightTree(Node* tree, Node* in);
void printTree(Node* tree, int deep);
void treeDestroy(Node** tree);
Node* getRightSon(Node* tree);
Node* getLeftSon(Node* tree);
tree_data_type getTreeValue(Node* tree);

#endif