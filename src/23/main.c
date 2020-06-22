#include "bintree.h"
#include <time.h>

void help(void)
{
    printf("INSERT: Press a\n");
    printf("DELETE: Press d\n");
    printf("PRINT: Press p\n");
    printf("CHECKLEALS: Press l\n");
    printf("INSTRUCTIONs: Press i\n");
    printf("EXIT: Press q\n");
}

int main(void)
{
    Bintree tree;
    int value;
    char c;

    tree = tree_create();
    help();
    while (true) {
        scanf("%c", &c);
        switch (c) {
            case 'a':
                printf("Enter key: ");
                scanf("%d", &value);
                tree_insert(&tree, value);
            break;
            case 'd':
                printf("Enter key: ");
                scanf("%d", &value);
                if (tree_del(&tree, value) == -1)
                    printf("This key is not exist\n");
            break;
            case 'p':
                tree_print(&tree);
            break;
            case 'l':
                
                leafscheck(&tree);
            break;
            case 'i':
                help();
            break;
            case 'q':
                tree_destroy(&tree);
                return 0;
            break;
        }
    }
}