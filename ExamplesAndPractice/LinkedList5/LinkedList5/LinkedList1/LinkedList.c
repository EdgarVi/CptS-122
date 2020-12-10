#include "LinkedList.h"


// inserts an item at the front of the list
int insertFront(Node **pList, char *pItem)
{
	///////////////////////////////////////////
	// working with doubly linked list now!
	///////////////////////////////////////////

	Node *pMem = NULL;
	int success = 0;

	// heap memory - up to programmer to manage
	//pMem = (Node *) malloc(sizeof (Node)); // 104 bytes
	pMem = makeNode(pItem);
	// did malloc () fail? Null ptr
	if (pMem != NULL)
	{
		success = 1;

	//	pMem->pNext = NULL;
	//	strcpy(pMem->groceryItem, pItem);

		if (*pList == NULL) // dealing with an empty list!
		{
			(*pList) = pMem;
		}
		else // // not dealing with empty list
		{
			pMem->pNext = *pList;
			// doubly linked
			(*pList)->pPrev = pMem;
			*pList = pMem;
		}
	}

	return success;
}

// tries to allocate space for a Node on the heap
// initializes the Node with the item passed in, sets the next pointer to NULL
// returns a pointer to the beginning of the allocated block
Node *makeNode(char *pItem)
{
	///////////////////////////////////////////
	// working with doubly linked list now!
	///////////////////////////////////////////

	Node *pMem = NULL;

	pMem = (Node *) malloc(sizeof (Node)); // allocate space on heap

	if (pMem != NULL) // malloc succeeded
	{
		// init memory
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		strcpy(pMem->groceryItem, pItem);
	}

	return pMem;
}


// This function inserts items in alphabetical A - Z order.
// The case of the character matters! 'a' > 'A'
int insertOrder(Node **pList, char *pItem)
{
	////////////////////////////////////////////////////////////////
	// we did not convert this code to work with doubly linked lists
	////////////////////////////////////////////////////////////////
	int success = 0;
	Node *pMem = NULL, *pPrev = NULL, *pCur = NULL;

	pCur = *pList; // set to first node in list, if it exists

	pMem = makeNode(pItem);

	if (pMem != NULL) // was memory allocated?
	{
		success = 1;

		// where to insert in order?
		while ((pCur != NULL) && (strcmp (pItem, pCur->groceryItem) > 0)) // short circuit?
		{
			// allow for us to advance through list
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		// found the place to insert

		if (pPrev != NULL) // 
		{
			// not inserting at the front
			pPrev->pNext = pMem;
			pMem->pNext = pCur;
		}
		else // inserting at front
		{
			pMem->pNext = pCur; // *pList
			*pList = pMem;
		}
	}

	return success;
}

// print out all of the items in the list
void printList(Node *pList)
{
	printf("--> ");
	while (pList != NULL)
	{
		printf("%s --> ", pList->groceryItem);
		pList = pList->pNext;
	}
	putchar('\n');
}

// deletes the Node at the front of the list, and returns the item
// that was stored in it. 
// ensures that the list is not empty before it attempts to delete the front Node
int deleteFront(Node **pList, char *pItem)
{
	///////////////////////////////////////////
	// working with doubly linked list now!
	///////////////////////////////////////////

	int success = 0;
	Node *pTemp = NULL;

	// free ()
	if (*pList != NULL)
	{
		// a node should be deleted - front one
		pTemp = *pList;
		strcpy(pItem, pTemp->groceryItem);
		*pList = (*pList)->pNext;
		// consider 1 node  - deleting the 1 node --> empty list


		// consider more than 1 node in list
		if (*pList != NULL)
		{
			(*pList)->pPrev = NULL;
		}

		free(pTemp);
	}
	return success;

}