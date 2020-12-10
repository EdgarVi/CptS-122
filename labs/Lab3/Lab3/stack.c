#include "stack.h"

// returns 1 if stack is empty, 0 otherwise
int isEmpty(stackNode *pStack)
{

	return (pStack == NULL) ? 0: 1;
}

// pushes a node containing data to the stack. 
void push(stackNode **pStack, double data)
{
	stackNode * pMem;
	pMem = (stackNode *)malloc(sizeof(stackNode));

	pMem->data = data;
	pMem->pNext = *pStack;
	*pStack = pMem;

}

// pops a node from  the top of the stack
double pop(stackNode **pStack)
{

	stackNode * pTemp;
	double data;

	data = pTemp->data;
	pTemp = (stackNode *)malloc(sizeof(stackNode));
	
	pTemp = *pStack;
	*pStack = pTemp->pNext;
	free(pTemp);

	return data;
}

// returns the value at the top of the stack
double peek(stackNode *pStack)
{

}