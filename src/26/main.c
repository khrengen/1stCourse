#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "sort.h"



int main(void)
{
	queue q;
    int t;
    char string[20];
    
    qCreate(&q);
    printf("queue created\n");

    while(true){
    	scanf("%s", string);

    	
    		
    		
    	 if (strcmp(string , "push") == 0){
    		scanf("%d", &t);
    		qPush(&q, t);
    		printf("queue: ");
    		printq(&q);
    	}else if (strcmp(string , "pushfew") == 0){
            qPushfew(&q);
            printf("queue: ");
            printq(&q);
        }else if (strcmp(string , "pop") == 0){
    		qPop(&q);
    		printf("queue: ");
    		printq(&q);
    	} else if (strcmp(string, "sort") == 0){
    		Qsort(&q);
    		printq(&q);

    	} else if (strcmp(string, "exit") == 0){
            exit(0);
        } else printf("enter:\n \t 'push' to add one element\n\t 'pushfew' to add some elements\n\t 'pop' to delete element\n\t 'sort' to sort elements\n\t 'exit' to exit\n");
	}
    	return 0;
     	
    
   
}