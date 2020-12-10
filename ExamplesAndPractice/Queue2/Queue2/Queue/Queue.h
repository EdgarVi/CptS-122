#ifndef  QUEUE_H
#define QUEUE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	char *pData;
} Data;

typedef struct node
{
	Data *pItem;
	struct node *pNext;
}Node;

typedef struct queue
{
	Node *pHead;
	Node *pTail;
} Queue;

Node *makeNode(Data newItem);
int enqueue(Queue *pQ, Data newItem);

#endif // ! QUEUE_H

