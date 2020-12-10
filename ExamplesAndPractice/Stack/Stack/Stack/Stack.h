#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct data {
	char info;
} Data;

typedef struct node {
	Data item;
	struct node *pNext;
} Node;


typedef struct stack{
	Node * pTop;
} Stack;

int isEmpty(Stack s);
Data peek(Stack s);


int push(Stack * pStack, Data newItem);
void pop(Stack * pStack);
#endif
