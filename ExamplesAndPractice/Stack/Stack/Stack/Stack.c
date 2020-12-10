#include "Stack.h"

int isEmpty(Stack s) {

	return (s.pTop == NULL);
}


//precondition: stack must not be empty
Data peek(Stack s) {

	return (s.pTop->item);
}


Node * makeNode(Data newItem) {

	Node * pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->item = newItem;
	}

	return pMem;
}

int push(Stack * pStack, Data newItem) {	

	int success = 0;
	Node * pMem = makeNode(newItem);

	if (pMem != NULL) {
		
		success = 1;
		pMem->pNext = pStack->pTop; // assign to next node
		pStack->pTop = pMem; // place on top of stack

	}

	return success;
}


// precondition: stack must not be empty
void pop(Stack * pStack) {

	Node *pTemp = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;

	free(pTemp);
}
