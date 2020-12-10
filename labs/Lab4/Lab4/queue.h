#ifndef  QUEUE_H
#define QUEUE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean
{
	FALSE, TRUE
} bool;


typedef struct data {
	char *pData;
} Data;

typedef struct node {
	Data *pItem;
	struct node *pNext;
}Node;

typedef struct queue {
	Node *pHead;
	Node *pTail;
} Queue;


Node * makeNode(Data newItem);
bool isEmpty(Queue q);
bool enqueue(Queue * q, Data newData);
Data dequeue(Queue * q);

Node * printQueueRecursive(Node * qHead);

#endif // ! QUEUE_H



/* 
note on queue
basically a linkedlist, has data and a pointer
*/