#pragma once

#include <stdio.h> /* Used for standard input/output */
#include <stdlib.h> /* Needed for exit() */
#include <string.h> /* Used for strtok(), strcpy(), etc. */
#include <time.h> /* Used for generating list of random numbers */


typedef struct data {

	int customerNumber; /* Unique identifier, starts at 1; after 24 hours should be reset to 1 */
	int serviceTime;   /* Random time, varies between express and normal lanes; units in minutes */
	int totalTime;     /* totalTime = serviceTime + sum of serviceTimes of customers in line before this customer */

} Data; /* This memory needs to be allocated on the heap */


typedef struct item {
	
	int processTime;
	char product[20];

} Item;


typedef struct queueNode {

	Data *pData;    /* The memory for Data will need to be allocated on the heap as well! */
	struct queueNode *pNext;


} QueueNode;


typedef struct queue {
	
	QueueNode *pHead;
	QueueNode *pTail;

} Queue;

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
int isEmpty(Queue q);

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
void initQueue(Queue * pQ);

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
QueueNode * makeQueueNode(Data data);

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
void enqueue(Queue * pQ, Data data);

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
void dequeue(Queue * pQ);

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
void printQueue(Queue * pQ);

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
void runExpress(Queue * pQ, int duration);

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
runNormal(Queue * pQ, int duration);