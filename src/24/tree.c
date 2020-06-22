#include "tree.h"
#include <string.h>
#include <stdlib.h>

Node* createTree(tree_data_type value)
{
    Node* out = (Node*)malloc(sizeof(Node));
    out->data = (char*)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(out->data, value);
    out->left = NULL;
    out->right = NULL;
    return out;
}

void addLeftTree(Node* tree, Node* in)
{
    tree->left = in;
}

void addRightTree(Node* tree, Node* in)
{
    tree->right = in;
}

void printTree(Node* tree, int deep)
{
    if (tree != NULL) {
        printTree(tree->right, deep + 5);
        printf("%*s\n", deep, tree->data);
        printTree(tree->left, deep + 5);
    }
}

void treeDestroy(Node** tree)
{
    if (*tree != NULL) {
        free((*tree)->data);
        treeDestroy(&((*tree)->right));
        treeDestroy(&((*tree)->left));
        free(*tree);
        *tree = NULL;
    }
}

Node* getRightSon(Node* tree)
{
    return tree->right;
}

Node* getLeftSon(Node* tree)
{
    return tree->left;
}

tree_data_type getTreeValue(Node* tree)
{
    return tree->data;
}

