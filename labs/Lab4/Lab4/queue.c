#include "queue.h"

Node * makeNode(Data newItem)
{
	// allocates space for a Node only-->two pointers!
	Node *pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL) // did malloc () fail?
	{
		pMem->pNext = NULL;
		// need to allocate space for the Data!
		pMem->pItem = (Data *)malloc(sizeof(Data));

		if (pMem->pItem != NULL) // struct Data allocated
		{
			// need to allocate space for the string that
			// is in the newItem parameter
			pMem->pItem->pData = (char *)malloc(sizeof(char) *
				(strlen(newItem.pData) + 1));
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

bool isEmpty(Queue q) {
	if (q.pHead == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

bool enqueue(Queue * q, Data newData) {
	/* Insert at tail */
	Node * pCur = makeNode(newData);

	if (pCur != NULL) {
		if (q->pHead == NULL) {
			/* The queue is empty, insert to front of queue */
			q->pHead = q->pTail = pCur; /* Since queue is empty, set tail and end to pCur */
			return TRUE;
		} else {
			q->pTail->pNext = pCur;
			q->pHead = pCur;
			return TRUE;
		}
	}
}

Data dequeue(Queue * q)
{

	Data newData = { NULL };
	//Node * pTemp = NULL;

	Node * pTemp = q->pHead;

	q->pHead = q->pTail;
	if (q->pHead == q->pTail) {
		newData = *(q->pHead->pItem);
		free(pTemp->pItem);
		return newData;
	}
	
	
}

Node * printQueueRecursive(Node * qHead) {
	
	Node * pCur = qHead;

	puts(pCur->pItem->pData);

	if (pCur->pNext != NULL) {	
		pCur = printQueueRecursive(pCur);
	}

}

