#include "LinkedList.h"

Node * makeNode(char * pItem){

	Node *pMem = NULL;
	
	pMem = (Node *) malloc(sizeof(Node)); // allocate space on heap
	
	// malloc succeeded
	if (pMem != NULL) {
		//Initialize memory
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		strcpy(pMem->groceryItem, pItem);
	}

	return pMem;
}

int insertFront(Node ** pList, char * pItem) {
	Node *pMem = NULL;
	int success = 0;

	//heap memory - up to programmer to manage
	//pMem = (Node *)malloc(sizeof(Node));    // allocating 104 bytes of memory

	pMem = makeNode(pItem);


	// did malloc () fail? If it does return null pointer
	if (pMem != NULL) {

		success = 1;

		if (*pList == NULL) {	// dealing w/empty list
			(*pList) = pMem;
		}
		else {
			/* Now we're inserting at front */
			pMem->pNext = *pList;
			//doubly linked
			(*pList)->pPrev = pMem;
			*pList = pMem;
		}
	}

	return success;
}

int insertOrder(Node ** pList, char * pItem){
	int success = 0;
	Node *pMem = NULL, *pPrev = NULL, *pCur = NULL;

	pCur = *pList; // set to first node in list, if it exists

	pMem = makeNode(pItem);


	// was memory allocated?
	if(pMem != NULL){
		success = 1;
		// where to insert in order
		while((pCur != NULL) && (strcmp(pItem, pCur->groceryItem) > 0)){
		// allow for us to advance through the list
			pPrev = pCur;
			pCur = pCur->pNext;
		}
		// found the place to insert
		if (pPrev != NULL){
			// Not inserting at the front
			pPrev->pNext = pMem;
			pMem->pNext = pCur;
		} else { //inserting at front
			pMem->pNext = pCur; // could also set to *pList

		}
	}

	return success;
}

int deleteFront(Node **pList, char *pItem) {
	int success = 0;
	Node *pTemp = NULL;

	//will need to use free()
	if (*pList != NULL) {
		// A node should be deleted - front one
		pTemp = *pList;
		strcpy(pItem, pTemp->groceryItem);
		*pList = (*pList)->pNext;
		//consider 1 node - deleting the 1 node --> empty list


		//consider more than 1 node in list
		if (*pList == NULL) {
			(*pList)->pPrev = NULL;
		}

		free(pTemp);
		
	}
	return success;
}

void printList(Node *pList) {
	printf("-->");
	while (pList != NULL) {
		printf("%s -->", pList->groceryItem);
		pList = pList->pNext;
	}
	printf("\n");
}
