/*******************************************************************************
* Programmer: Edgar Villasenor                                                 *
* Class: CptS 121; Lab Section 1                                               *
* Programming Assignment 1: Analyzing Fitbit Data                              *
* Date:                                                                        *
*                                                                              *
* Description: This program parses through a CSV file contataing 24 hours of   *
*				fitbit data	and calculates several different values	based off  *
*				the data													   *
*																			   *
*                                                                              *
* Relevant Formulas: Refer to each function definition.                        *
*                                                                              *
* Format of record in input file (input.dat): 12345678 (ID int)                *
*                                             3.78     (gpa double)            *
*									           3        (class standing int)   *
*									           20.5     (age double)           *
*                                                                              *
* Format of output file (Results.CSV): totalCaloriesBurned, totalDistanceWalked,*
*									   totalFloorsWalked, totalStepsTaken,	   *
*									   averageHeartRate, maxSteps, start, end  *
*******************************************************************************/
#pragma once

#include <stdio.h> /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <stdlib.h> /* Needed for atoi (), atof (), etc. */
#include <string.h> /* Needed for strcpy () and strtok ()*/

/* Data Structures */
typedef enum sleep { 
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3, NO_DATA = -1
} Sleep;

/* FitbitData was provided in the prompt*/
typedef struct fitbit{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;



/* Function prototypes */

/*************************************************************
* Function: parseData ()                                     *
* Date Created: 30 August 2017                               *
* Date Last Modified: 7 September 2017                       *
* Description: This function reads the data from the infile  *
*			   and places the data into the fields of the    *
*			   fitBitArray struct							 *
*															 *
* Input parameters: An input file pointer, an array of       *
*					structs.								 *
* Returns: Nothing/void function                             *
* Preconditions: The input file must already be open.        *
* Postconditions: The fields of the fitBitArray struct are   *
*				  filled									 *
*************************************************************/
void parseData(FILE * infile, FitbitData fitBitArray[1440]);

/*****************************************************************
* Function: validToken ()										 *
* Date Created: 6 September 2017								 *
* Date Last Modified: 7 September 2017						     *
* Description: Determines if the token is valid				     *
*															     *
* Input parameters: A pointer to a token						 *
* Returns: An integer that determines if the token is valid	     *
* Preconditions: strtok () has been called on a string		     *
* Postconditions: The validity of the token has been determined  *
*****************************************************************/
int validToken(char * token);

/*****************************************************************
*Function: totalCaloriesBurned ()								 *
*Date Created: 6 September 2017									 *
*Date Last Modified: 7 September 2017							 *
*Description: Computes the total number of calories burned       *
*																 *
*Input Parameters: An array of structs							 *
*Returns: The total number of calories burned					 *
*Preconditions: fitBitArray has been initialized				 *
*Postconditions: The total number of calories burned has been    *
*computed														 *
******************************************************************/
double totalCaloriesBurned(FitbitData fitBitArray[1440]);

/*****************************************************************
* Function: totalDistanceWalked ()								 *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Computes the total distance walked                *
*																 *
* Input Parameters:	An array of structs							 *
* Returns: The total distance walked							 *
* Preconditions: fitBitArray has been initialized				 *
* Postconditions: totalDistanceWalked has been computed			 *
******************************************************************/
double totalDistanceWalked(FitbitData fitBitArray[1440]);

/*****************************************************************
* Function: totalFloorsWalked ()								 *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Computes the total floors walked                  *
*																 *
* Input Parameters:	An array of structs							 *
* Returns: The total floors walked							     *
* Preconditions: fitBitArray has been initialized				 *
* Postconditions: totalFloorsWalked has been computed			 *
******************************************************************/
int totalFloorsWalked(FitbitData fitBitArray[1440]);


/*****************************************************************
* Function: totalStepsTaken ()								     *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Computes the total steps walked                   *
*																 *
* Input Parameters:	An array of structs							 *
* Returns: The total steps walked							     *
* Preconditions: fitBitArray has been initialized				 *
* Postconditions: totalStepsTaken has been computed			     *
******************************************************************/
int totalStepsTaken(FitbitData fitBitArray[1440]);

/*****************************************************************
* Function: maxSteps ()								             *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Computes the max steps taken in one  minute       *
*																 *
* Input Parameters:	An array of structs							 *
* Returns: The total steps taken							     *
* Preconditions: fitBitArray has been initialized				 *
* Postconditions: maxSteps has been computed					 *
******************************************************************/
int maxSteps(FitbitData fitBitArray[1440]);

/*****************************************************************
* Function: computeAverageHeartRate ()							 *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Computes the avearge heart rate                   *
*																 *
* Input Parameters:	An array of structs							 *
* Returns: The average heart rate							     *
* Preconditions: fitBitArray has been initialized				 *
* Postconditions: averageHeartRate has been computed			 *
******************************************************************/
double computeAverageHeartRate(FitbitData fitBitArray[1440]);

/*****************************************************************
* Function: worstSleep ()								         *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Computes the range of worst sleep                 *
*																 *
* Input Parameters:	An array of structs							 *
* Returns: The worst range of sleep 						     *
* Preconditions: fitBitArray has been initialized				 *
* Postconditions: The worst range of sleep is returned		     *
******************************************************************/
void worstSleep(FitbitData fitBitArray[1440], char * start, char * end);

/*****************************************************************
* Function: writeResults ()								         *
* Date Created: 6 September 2017                                 *
* Date Last Modified: 7 September 2017                           *
* Description: Writes the compiled computations to the outfile   *
*																 *
* Input Parameters:	Outfile, calories burned, distance walked,	 *
* floors walked, steps taken, average heart rate, max steps,	 *
* max steps and range of worst sleep							 *
*																 *
* Returns: None/void function 									 *
* Preconditions: The outfile has been opened for writing, all    *
* computations have been performed								 *
* Postconditions: The worst range of sleep is returned		     *
******************************************************************/
void writeResults(FILE * outfile, int totalCaloriesBurned, int totalDistanceWalked,
	int totalFloorsWalked, int totalStepsTaken, double averageHeartRate, int maxSteps, 
	char start[9], char end[9]);

