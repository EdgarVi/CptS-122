#include "queue.h"

/**************************************************************
Function: isEmpty ()
Date Created: 27 September 2017
Date Last Modified: 27 September 2017
Description: Checks to see if the queue is empty
Input parameters: A queue of type Queue
Returns: An integer that determines if the queue is empty
Preconditions: The queue has been initialized
Postconditions: It has been determined if the queue is empty
**************************************************************/
int isEmpty(Queue q)
{
	int empty = 0;

	if (q.pHead == NULL) {
		empty = 1;
	}

	return empty;
}

/**************************************************************
Function: initQueue ()
Date Created: 27 September 2017
Date Last Modified: 27 September 2017
Description: Initizializes the head and tail pointers of the queue
Input parameters: A pointer to a queue
Returns: Void function, does not return a value
Preconditions: Memory has been allocated for a pointer to a queue
Postconditions: The actual queue has been initialized
**************************************************************/
void initQueue(Queue * pQ)
{
	pQ->pHead = NULL;
	pQ->pTail = NULL;
}

/**************************************************************
Function: makeQueueNode ()
Date Created: 25 September 2017
Date Last Modified: 28 September 2017
Description: Creates a node and seeds it with the given data
Input parameters: A struct containing the desired data
Returns: A pointer to the node
Preconditions: The data has been initialized
Postconditions: The node has been intialized with the desired
data
**************************************************************/
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
			
			/* malloc worked for customerNumber, serviceTime, totalTime */
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

/**************************************************************
Function: enqueue ()
Date Created: 25 September 2017
Date Last Modified: 27 September 2017
Description: Inserts a node at the end of the queue
Input parameters: A pointer to the queue and the data in
the new node
Returns: Void function, does not return a value
Preconditions: The data has been initialized
Postconditions: The node will have been inserted at the end,
pTail will point to this node and *pNext is NULL
**************************************************************/
void enqueue(Queue * pQ, Data data)
{
	
	QueueNode * pMem = makeQueueNode(data);

	int empty = 0;
	empty = isEmpty(*pQ);

	if (empty == 1) {
		/* Empty queue, inserting first node */
		pQ->pHead = pQ->pTail = pMem;
	} else {
		/* Queue isn't empty, insert at end*/
		pQ->pTail->pNext = pMem; 
		pQ->pTail = pMem;
	}

}

/**************************************************************
Function: dequeue ()
Date Created: 25 September 2017
Date Last Modified: 27 September 2017
Description: Deletes the node at the front of the queue
Input parameters: A pointer to the queue
Returns: Void function, does not return a value
Preconditions: The queue has been initialized
Postconditions: The head node has been deleted and replaced by
the previous node
**************************************************************/
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
	} else if (empty != 1) {
		/* Case 2: queue has more than one node */
		pMem = pQ->pHead;
		pQ->pHead = pQ->pHead->pNext;
		free(pMem);
	}

}

/**************************************************************
Function: printQueue ()
Date Created: 25 September 2017
Date Last Modified: 27 September 2017
Description: Prints the contents of the queue
Input parameters: Pointer to the queue
Returns: Void function, does not return a value
Preconditions: The queue has been initialized
Postconditions: The contents of the queue have been printed
**************************************************************/
void printQueue(Queue * pQ)
{
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

/**************************************************************
Function: runExpress()
Date Created: 27 September 2017
Date Last Modified: 4 October 2017
Description: Runs the express simulation
Input parameters: Pointer to the queue and duration of the
simulation
Returns: Void function, does not return a value
Preconditions: The queue has been initialized and the user has
selected a duration
Postconditions: The simulation has run
**************************************************************/
void runExpress(Queue * pQ, int duration)
{

	printf("Running express lane simulation...\n");

	int timeElapsed = 0, ID = 0;

	int arrivalTime = 0, serviceTime = 0, timeWaitedSum = 0;

	Data newData;
	int empty = 0;

	while (timeElapsed <= duration) {
		arrivalTime = rand() % 5 + 1; /* Random number [1-5] */ 
		timeElapsed++;
		ID++;
		serviceTime = rand() % 5 + 1;
		
		timeWaitedSum += serviceTime;

		newData.customerNumber = ID; /* Unique ID, starting at 1 */
		newData.serviceTime = serviceTime; 
		newData.totalTime = timeWaitedSum; 

		empty = isEmpty(*pQ);

		if (empty != 1) {
			/* Queue is not empty */
			if(pQ->pHead->pData->serviceTime > 0) {
				/* Customer in front hasn't been in line long enough to be serviced*/
				enqueue(pQ, newData);
				pQ->pHead->pData->serviceTime -= 1;
			} else {
				if ((pQ->pHead != NULL) && (pQ->pHead->pData->serviceTime  == 0)) {
					/* Customer in front has been serviced, dequeue */
					dequeue(pQ);
				}
			}
		} else {
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

/**************************************************************
Function: runNormal()
Date Created: 28 September 2017
Date Last Modified: 4 October 2017
Description: Runs the express simulation
Input parameters: Pointer to the queue and duration of the
simulation
Returns: Void function, does not return a value
Preconditions: The queue has been initialized and the user has
selected a duration
Postconditions: The simulation has run
**************************************************************/
runNormal(Queue * pQ, int duration)
{
	printf("Running normal lane simulation...\n");

	int timeElapsed = 0, ID = 0;

	int arrivalTime = 0, serviceTime = 0, timeWaitedSum = 0;

	Data newData;
	int empty = 0;

	while (timeElapsed <= duration) {
		arrivalTime = rand() % 8 + 3; /* Random number [3-8] */
		timeElapsed++;
		ID++;
		serviceTime = rand() % 8 + 3; 

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
				pQ->pHead->pData->serviceTime -= 1;
			}
			else {
				if ((pQ->pHead != NULL) && (pQ->pHead->pData->serviceTime == 0)) {
					/* Customer in front has been serviced, dequeue */
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
			printf("Printing Queue...\nTime Elapsed: %d\n", timeElapsed);
			printQueue(pQ);
		}
	}

}

