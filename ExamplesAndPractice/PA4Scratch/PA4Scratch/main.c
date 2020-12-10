/******************************************************************************
* Programmer: Edgar Villasenor												  *
* Class: CptS 122 Lab Section 1												  *
* Programming Assignment 4: Grocery Store Simulation						  *
* Date: 3 October 2017  													  *
* Description: 													      *
*																			  *
* Format of input 															  *
*																			  *
* Format of output 															  *
*******************************************************************************/

#include "pa4.h"

int main(void) {


	int n = 0; /* The number of minutes the simulation will run, input by the user */

			   /*printf("Duration of simulation: ");
			   scanf("%d", &n);*/


	srand((unsigned int)time(NULL)); //Seed the program for random numbers


	n = 25;


	Queue expressQueue; //make express queue
						//Queue normalQueue; //make regular queue


	initQueue(&expressQueue);
	//initQueue(&normalQueue);


	runExpress(&expressQueue, n);
	//runNormal(&normalQueue, n);


	return 0;
}

/*
Note on assignment:

Don't need to run both simulations at the same time,
run simulation on express then

Will create two queues (lines, one representing express
and the other representing a normal line)

One minute is the base unit of time

The two queues are made up of Nodes which only point to
the next node and a pointer to it's data. The queues
only have pointers to the head and tail nodes.

In the express lane, customers arrive every 1 to 5 minutes.
Service times are 1 to 5 minutes.

In the regular lane, customers arrive every 3 to 8 minutes
Service times are 3 to 8 minutes
*/