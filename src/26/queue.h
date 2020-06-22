#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

#define POOL_SIZE 100

    typedef struct
{
	int first;
	int size;
	int data[POOL_SIZE];
}queue;


void qCreate(queue* q);
bool qEmpty(const queue* q);
int qSize(queue* q);
int qTop(queue* q);
int qPush(queue* q, int t);
int qPop(queue* q);
int qPushfew (queue* q);
void printq(queue* q);



#endif