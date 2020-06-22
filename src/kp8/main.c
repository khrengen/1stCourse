#include <stdio.h>
#include "List.h"

int main()
{
    List list;
    Iterator it;
    char c;
    int value, m, pos;
    list_create(&list);

    printf("n   -  Next \n");
    printf("u   -  Prev \n");
    printf("w   -  Fetch\n");
    printf("s   -  Store\n");
    printf("\n");
    printf("l   -  empty or not\n");
    printf("f   -  insert front(left side)\n");
    printf("b   -  insert behind(right side)\n");
    printf("d   -  delete element with your index\n");
    printf("p   -  print list\n");
    printf("e   -  add last in begining\n");
    printf("i   -  help\n");
    printf("q   -  exit\n");
    printf("\n");
    printf("list created\n");


    while (true) {
        scanf("%c", &c);
        switch (c) {
            case 'S':
                    printf("%d\n", list_size(&list));

                    break;
            case 'n':
                    if(it.node != NULL){
                        it = *it_next(&it);
                    }else printf("it on NULL");

                    break;

            case 'u':
                    if(it.node != NULL){
                        it = *it_prev(&it);
                    }else printf("it on NULL");

                    break;
            case 'w':
                    if(it.node != NULL){
                        printf("%d\n", it_fetch(&it));
                    }else printf("it on NULL");

                    break;

            case 's':

                    if(it.node != NULL){
                        printf("new value = ");
                        scanf ("%d", &m);
                        it_store(&it, m);
                    }else printf("it on NULL");

                    break;       
            case 'l':
                    if(list_empty(&list)){
                        printf("list is empty\n");
                    } else printf("list isn`t empty\n");
               
            break;

            case 'f':
                printf("enter value: ");
                scanf("%d", &value);
                printf("enter index:");
                scanf("%d", &pos);
              it = list_insert(&list, &it, pos, value);
            break;
            case 'b':
                printf("enter value: ");
                scanf("%d", &value);
               // printf("enter index\n");
               it = list_insert_after(&list, &it, value);
            break;
            case 'd':
                    if (list_empty(&list)){
                        printf("list is empty\n");
                    } else {
                        int del;
                        printf("delete : ");
                        scanf("%d", &del);
                        if (del >= list_size(&list)){
                            printf("list too small for this\n");

                        

                        } else {
                            Iterator it_del = list_find(&list, del);
                            it = list_delete(&list, &it_del);
                        }
                    } 
            break;
            case 'p':
                    list_print(&list);
               
            break;
           
            case 'q':
                    list_destroy(&list);
                return 0;
            break;
            case 'e':
                    exec(&list);
                         
               
            break;

            case 'i':
                    printf("n   -  Next \n");
                    printf("u   -  Prev \n");
                    printf("w   -  Fetch\n");
                    printf("s   -  Store\n");
                    printf("\n");
                    printf("l   -  empty or not\n");
                    printf("f   -  insert front(left side)\n");
                    printf("b   -  insert behind(right side)\n");
                    printf("d   -  delete element with your index\n");
                    printf("p   -  print list\n");
                    printf("e   -  add last in begining\n");
                    printf("i   -  help\n");
                    printf("q   -  exit\n");
                    printf("\n");
                    printf("list created\n");
        }
    }

    return 0;
}