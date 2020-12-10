/******************************************************************************
* Programmer: Edgar Villasenor												  *
* Class: CptS 122 Lab Section 1												  *
* Programming Assignment 4: Grocery Store Simulation						  *
* Date: 4 October 2017  													  *
* Description: Grocery store simulation, simulate two lines, express lane and *
* normal lane as queues. As customers are serviced, the line is dequeued and  *
* the next customer is service												  *
*																			  *
* Format of input: No input													  *
*																			  *
* Format of output: Customer Number: , Service Time: , Total Time: \n		  *
*******************************************************************************/

#include "queue.h"

int main(void) {


	int n = 0; /* The number of minutes the simulation will run, input by the user */

	printf("Duration of simulation: ");
	scanf("%d", &n);
	

	srand((unsigned int)time(NULL)); /* Seed the program for random numbers */
	
	Queue expressQueue; /* make express queue */
	Queue normalQueue; /* make regular queue */

	/* Initialize queues */
	initQueue(&expressQueue);
	initQueue(&normalQueue);

	/* Run simulations */
	runExpress(&expressQueue, n);
	runNormal(&normalQueue, n);


	return 0;
}
