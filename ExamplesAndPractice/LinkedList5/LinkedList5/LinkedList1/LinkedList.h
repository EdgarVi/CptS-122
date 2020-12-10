#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char groceryItem[100];
	struct node* pNext;
	struct node* pPrev;
} Node;

Node *makeNode(char *pItem);

int insertFront(Node **pList, char *pItem);
int insertOrder(Node **pList, char *pItem);

int deleteFront(Node **pList, char *pItem);
void printList(Node *pList);

#endif