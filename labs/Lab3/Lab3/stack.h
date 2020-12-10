#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	double data;
	struct node *pNext;
}stackNode;



// returns 1 if stack is empty, 0 otherwise
int isEmpty(stackNode *pStack);

// pushes a node containing data to the stack. 
void push(stackNode **pStack, double data);

// pops a node from  the top of the stack
double pop(stackNode **pStack);

// returns the value at the top of the stack
double peek(stackNode *pStack);