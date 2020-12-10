#include "Queue.h"

// Be sure to cross reference with the types listed in
// Queue.h! There are a few malloc () calls, which may
// only be understood by refering to Queue.h.
// Note: this function does not deallocate the space
// for each part of the node, if one malloc () fails.
Node *makeNode(Data newItem)
{
	// allocates space for a Node only-->two pointers!
	Node *pMem = (Node *) malloc(sizeof(Node));

	if (pMem != NULL) // did malloc () fail?
	{
		pMem->pNext = NULL;
		// need to allocate space for the Data!
		pMem->pItem = (Data *)malloc(sizeof(Data));

		if (pMem->pItem != NULL) // struct Data allocated
		{
			// need to allocate space for the string that
			// is in the newItem parameter
			pMem->pItem->pData = (char *) malloc(sizeof (char) * 
				(strlen (newItem.pData) + 1));
			if (pMem->pItem->pData != NULL) // space for a string allocated!
			{
				// finally, initialize the space with
				// the string pointed to by the field
				// in newItem
				strcpy(pMem->pItem->pData, newItem.pData);
			}
		}
	}

	return pMem;
}


// Insert at the end of the queue. This
// function is not finished!
int enqueue(Queue *pQ, Data newItem)
{
	Node *pMem = makeNode(newItem);
	int success = 0;

	if (pMem != NULL) // memory was successfully allocated
	{
		if (pQ->pHead == NULL) // empty?
		{
			// it's an empty queue!
			// connect both the head and tail to the one new node
			pQ->pHead = pQ->pTail = pMem;
			success = 1;
		} else {
			/* Not empty */
			pQ->pTail->pNext = pMem;
			pQ->pTail = pMem;
			success = 1;
		}
	}

	return success;
}

