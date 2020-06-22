//очередь
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void qCreate(queue* q)
{
	q->first = 0;
	q->size = 0;
}

bool qEmpty(const queue* q)
{
	return q->size == 0;
} 

int qSize(queue* q)
{
	return q->size;
}

int qTop(queue* q)
{
	if(q->size)
		return q->data[q->first];
}

int qPush(queue* q, int t)
{
	if (q->size == POOL_SIZE){
		fprintf(stderr, "this queue is full\n" );
		return 1;
	}
	q-> data[(q->first + q->size++) % POOL_SIZE] = t;
	return 0;

}

int qPushfew (queue* q)
{
	int t, n;
	printf("number added elements = ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		printf("element %d = ", i + 1);
		scanf("%d", &t);
		if (q->size == POOL_SIZE){
		    fprintf(stderr, "this queue is full\n" );
		    return 1;
		}
	q-> data[(q->first + q->size++) % POOL_SIZE] = t;
	}
	return 0;
}

int qPop(queue* q)
{
	if (q->size > 0){
		q-> size--;
	} else{
		fprintf(stderr,"there`s no elements in queue! ");
		return 2;
	}

    for (int i = 0; i < q->size; i++){
    	q->data[i] = q->data[i+1];
    }
    return 0;
	
}

void printq(queue* q)
{
	for (int i = 0; i < q->size; i++){
		printf("%d ", q->data[i]);
	}
	printf("\n");
}




