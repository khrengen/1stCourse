#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sortstation.h"
#include "tree.h"
#include "Stack.h"


Node* RPNtoTree(List* list)
{
    if (list != NULL) {
        Stack *stack = stack_create();
        Node* node;
        char* tmp;
        Iterator it = list_first(list);
        while(list_size(list) != 0) {
            
            tmp = it_fetch(&it);

            list_delete_front(list);
            it = list_first(list);
            if(is_op(tmp[0])) {
                node = createTree(tmp);
                addRightTree(node, stack_pop(stack));

                addLeftTree(node,stack_pop(stack));
                stack_push(stack, node);

        
            
            } else {
                stack_push(stack, createTree(tmp));
            }

            free(tmp);
        }
        
        node = stack_pop(stack);
        stack_delete(&stack);
        return node;
    } else {
        return NULL;
    }


}

char* treeToStr(Node* tree, char* out) {
    char* tmpStr;
    tmpStr = getTreeValue(tree);
    if (tmpStr[0] == '*') {
        tmpStr = getTreeValue(getLeftSon(tree));
        if (tmpStr[0] == '-' || tmpStr[0] == '+') {
            strcat(out, "(");
            treeToStr(getLeftSon(tree), out);
            strcat(out, ")");
        } else {
            treeToStr(getLeftSon(tree), out);
        }
        strcat(out, "*");
        tmpStr = getTreeValue(getRightSon(tree));
        if (tmpStr[0] == '-' || tmpStr[0] == '+') {
            strcat(out, "(");
            treeToStr(getRightSon(tree), out);
            strcat(out, ")");
        } else {
            treeToStr(getRightSon(tree), out);
        }
    } else if (tmpStr[0] == '+' || tmpStr[0] == '-') {
        treeToStr(getLeftSon(tree), out);
        strcat(out, getTreeValue(tree));
        treeToStr(getRightSon(tree), out);
    } else if (tmpStr[0] == '/' || tmpStr[0] == '^') {
        tmpStr = getTreeValue(getLeftSon(tree));
        if (!((is_num(tmpStr[0]) || is_alpha(tmpStr[0])))) {
            strcat(out, "(");
            treeToStr(getLeftSon(tree), out);
            strcat(out, ")");
        } else {
            treeToStr(getLeftSon(tree), out);
        }
        strcat(out, getTreeValue(tree));
        tmpStr = getTreeValue(getRightSon(tree));
        if (!((is_num(tmpStr[0]) || is_alpha(tmpStr[0])))) {
            strcat(out, "(");
            treeToStr(getRightSon(tree), out);
            strcat(out, ")");
        } else {
            treeToStr(getRightSon(tree), out);
        }
        
    } else if (is_num(tmpStr[0]) || is_alpha(tmpStr[0])) {
        strcat(out, tmpStr);
    }
    return out;
}

void variable_rec(Node* tree, char* mas, int* m)
{
    if (tree != NULL){
        //char tmp[10];
        //bzero(tmp, 10);

        if(is_alpha(tree->data[0])){

            for (int i = 1; i <= m[0]; i++){
                if (tree->data[0] == mas[i]){
                    variable_rec(tree->left, mas, m);
                    variable_rec(tree->right, mas, m);
                    return;
                } 
            }
        
        m[0]++;
        mas[m[0]] = tree->data[0];
        }
        variable_rec(tree->left, mas, m);
        variable_rec(tree->right, mas, m);
    }
}

int variable(Node* tree){

    char mas[50]; 
    bzero(mas, 50);
    int m[1];
    m[0] = 0;


    variable_rec(tree, mas, m);
    printf("number of variables: %d\n", m[0]);

    return 0;
}
int main()
{
    List list;
    Iterator it;
    Bintree tree;
    char c;
    char* value;
    int pos, m;
    char sp[128];
    char out[128];
    bzero(out, 128);
    list_create(&list);
    printf("list created\n");
    
                
    scanf("%s", sp);
    list = StrToRPN(sp);
    printf("done\n");

    Node* eT = RPNtoTree(&list);
    printTree(eT, 0);
    
    printf("\n");
    variable(eT);
    printf("\n");
    printf("to str again: \n");

    treeToStr(eT, out);
    printf("%s\n", out);
    list_destroy(&list);
    treeDestroy(&eT);
    return 0;
}