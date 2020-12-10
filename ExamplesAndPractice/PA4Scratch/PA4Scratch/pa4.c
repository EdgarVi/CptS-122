#include "pa4.h"

linkedListNode * makeLinkedListNode(Item pItem)
{
	linkedListNode * pNew;

	pNew = (linkedListNode*)malloc(sizeof(linkedListNode));


	if (!pNew) {
		printf("makeLinkedListNode() failed!\n");
		return NULL;
	}
	else {
		/* malloc did not fail */

		/* Assign data from pItem to new node */
		strcpy(pNew->pItem->product, pItem.product);
		pNew->pItem->processTime = pItem.processTime;
		pNew->pNext = NULL;

		return pNew;
	}

}

int insertLinkedListNodeFront(linkedListNode ** nodeHead, Item pItem)
{
	linkedListNode * pCur = NULL;
	pCur = makeLinkedListNode(pItem);
	int success = 0;

	if (pCur != NULL) {
		success = 1;
		if (*nodeHead == NULL) {
			/* List is currently empty */
			(*nodeHead) = pCur;
		}
		else {
			/* Not empty so insert at front */
			pCur->pNext = *nodeHead;
			*nodeHead = pCur;
		}
	}

	return success;

}

int isEmpty(Queue q)
{
	int empty = 0;

	if (q.pHead == NULL) {
		empty = 1;
	}

	return empty;
}

void initQueue(Queue * pQ)
{
	pQ->pHead = NULL;
	pQ->pTail = NULL;
}

QueueNode * makeQueueNode(Data data)
{

	QueueNode * pMem = (QueueNode *)malloc(sizeof(QueueNode));

	if (pMem != NULL) {
		/* malloc worked */
		pMem->pNext = NULL;
		pMem->pData = (Data *)malloc(sizeof(Data));

		if (pMem->pData != NULL) {
			/* malloc worked for pData */
			pMem->pData->customerNumber = (int *)malloc(sizeof(int));
			pMem->pData->serviceTime = (int *)malloc(sizeof(int));
			pMem->pData->totalTime = (int *)malloc(sizeof(int));
			if ((pMem->pData->customerNumber != NULL) && \
				(pMem->pData->serviceTime) != NULL && \
				(pMem->pData->totalTime) != NULL) {
				pMem->pData->customerNumber = data.customerNumber;
				pMem->pData->serviceTime = data.serviceTime;
				pMem->pData->totalTime = data.totalTime;
			}
		}
	}

	return pMem;
}

void enqueue(Queue * pQ, Data data)
{

	QueueNode * pMem = makeQueueNode(data);

	int empty = 0;
	empty = isEmpty(*pQ);

	if (empty == 1) {
		/* Empty queue, inserting first node */
		pQ->pHead = pQ->pTail = pMem;
	}
	else {
		/* Queue isn't empty, insert at end*/
		pQ->pTail->pNext = pMem;
		pQ->pTail = pMem;
	}

}

void dequeue(Queue * pQ)
{

	QueueNode * pMem = NULL;
	int empty = 0;

	empty = isEmpty(*pQ);

	if ((empty != 1) && (pQ->pHead == pQ->pTail)) {
		/* Case 1: queue has only one node */
		pMem = pQ->pHead;
		pQ->pHead = pQ->pHead->pNext;
		pQ->pTail = NULL;
		free(pMem);
	}
	else if (empty != 1) {
		/* Case 2: queue has more than one node */
		pMem = pQ->pHead;
		pQ->pHead = pQ->pHead->pNext;
		free(pMem);
	}


}

void printQueue(Queue * pQ)
{
	/* might have a bug here*/
	QueueNode * pCur = pQ->pHead;

	while (pCur) {
		/* Write to stdout */
		printf("Customer Number: ");
		fprintf(stdout, "%d", pCur->pData->customerNumber);

		printf(", Service Time: ");
		fprintf(stdout, "%d", pCur->pData->serviceTime);

		printf(", Total Time: ");
		fprintf(stdout, "%d", pCur->pData->totalTime);

		printf("\n");

		pCur = pCur->pNext;
	}
}

void runExpress(Queue * pQ, int duration)
{


	printf("Running express lane simulation...\n");

	int timeElapsed = 0, ID = 0;
	int addedCustomer = 0; /* = 0 don't add new customer, = 1 added new customer */

	int arrivalTime = 0;
	int serviceTime = 0;
	int timeWaitedSum = 0;

	Data newData;
	int empty = 0;

	while (timeElapsed <= duration) {
		addedCustomer = 0;
		arrivalTime = rand() % 5 + 1; /* Random number [1-5] */
		timeElapsed++;
		ID++;
		serviceTime = rand() % 5 + 1;
		printf("Service time generated: %d", serviceTime);
		printf(" Time elapsed: %d\n", timeElapsed);

		timeWaitedSum += serviceTime;

		newData.customerNumber = ID; /* Unique ID, starting at 1 */
		newData.serviceTime = serviceTime;
		newData.totalTime = timeWaitedSum;


		empty = isEmpty(*pQ);

		if (empty != 1) {
			/* Queue is not empty */
			if (pQ->pHead->pData->serviceTime > 0) {
				/* Customer in front hasn't been in line long enough to be serviced*/
				enqueue(pQ, newData);
				addedCustomer = 1;

				pQ->pHead->pData->serviceTime -= 1;
			}
			else {
				if ((pQ->pHead != NULL) && (pQ->pHead->pData->serviceTime == 0)) {
					/* Display customer stats to user */
					printf("Customer served: ");
					fprintf(stdout, "%d", pQ->pHead->pData->customerNumber);
					printf(", Arrival time: %d ", arrivalTime);
					printf(", Service Time: ");
					fprintf(stdout, "%d", pQ->pHead->pData->serviceTime);
					printf(", Time Waited Sum: ");
					fprintf(stdout, "%d", pQ->pHead->pData->totalTime);
					printf(" Time elapsed: %d\n", timeElapsed);
					printf("\n");

					dequeue(pQ);
				}
			}
		}
		else {
			/* Dealing with an empty queue */
			enqueue(pQ, newData);
		}

		/* Print queue every 10 minutes of the simulation*/
		if ((timeElapsed % 10 == 0) && (timeElapsed != 0)) {
			printf("Printing Queue\nTime Elapsed: %d\n", timeElapsed);
			printQueue(pQ);
		}
	}


}

runNormal(Queue * pQ, int duration)
{
	printf("Running normal lane simulation...\n");

	int timeElapsed = 0, ID = 0;
	int addedCustomer = 0; /* = 0 don't add new customer, = 1 added new customer */

	int arrivalTime = 0;
	int serviceTime = 0;
	int timeWaitedSum = 0;

	Data newData;
	int empty = 0;

	while (timeElapsed <= duration) {
		addedCustomer = 0;
		arrivalTime = rand() % 8 + 3; /* Random number [1-5] */
		timeElapsed++;
		ID++;
		serviceTime = rand() % 8 + 3;
		printf("Service time generated: %d", serviceTime);
		printf(" Time elapsed: %d\n", timeElapsed);

		timeWaitedSum += serviceTime;

		newData.customerNumber = ID; /* Unique ID, starting at 1 */
		newData.serviceTime = serviceTime;
		newData.totalTime = timeWaitedSum;


		empty = isEmpty(*pQ);

		if (empty != 1) {
			/* Queue is not empty */
			if (pQ->pHead->pData->serviceTime > 0) {
				/* Customer in front hasn't been in line long enough to be serviced*/
				enqueue(pQ, newData);
				addedCustomer = 1;

				pQ->pHead->pData->serviceTime -= 1;
			}
			else {
				if ((pQ->pHead != NULL) && (pQ->pHead->pData->serviceTime == 0)) {
					/* Display customer stats to user */
					printf("Customer served: ");
					fprintf(stdout, "%d", pQ->pHead->pData->customerNumber);
					printf(", Arrival time: %d ", arrivalTime);
					printf(", Service Time: ");
					fprintf(stdout, "%d", pQ->pHead->pData->serviceTime);
					printf(", Time Waited Sum: ");
					fprintf(stdout, "%d", pQ->pHead->pData->totalTime);
					printf(" Time elapsed: %d\n", timeElapsed);
					printf("\n");

					dequeue(pQ);
				}
			}
		}
		else {
			/* Dealing with an empty queue */
			enqueue(pQ, newData);
		}

		/* Print queue every 10 minutes of the simulation*/
		if ((timeElapsed % 10 == 0) && (timeElapsed != 0)) {
			printf("Printing Queue\nTime Elapsed: %d\n", timeElapsed);
			printQueue(pQ);
		}
	}

}

