#ifndef LINKED
#define LINKED

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//structures
typedef struct node {
	char groceryItem[100];
	struct node *pNext;
	struct node *pPrev;

} Node;

//function prototypes

Node *makeNode(char *pItem);

int insertFront(Node **pList, char *pItem);
int insertOrder(Node **pList, char *pItem);

int deleteFront(Node **pList, char *pItem); // need to update this for a doubly linked list for myself
void printList(Node *pList);

#endif
