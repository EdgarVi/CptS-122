/*******************************************************************************
* Programmer: Edgar Villasenor                                                 *
* Class: CptS 121; Lab Section 1                                               *
* Programming Assignment 1: Analyzing Fitbit Data                              *
* Date: 7 September 2017                                                       *
*                                                                              *
* Description: This program parses through a CSV file contataing 24 hours of   *
*				fitbit data	and calculates several different values	based off  *
*				the data													   *
*																			   *
*                                                                              *
* Relevant Formulas: Refer to each function definition.                        *
*                                                                              *
* Format of record in input file (input.dat):								   *
*   minute,calories,distance,floors,heart,steps,sleep_level					   *
*																			   *
*                                                                              *
* Format of output file (Results.CSV):										   *
*	totalCaloriesBurned, totalDistanceWalked, totalFloorsWalked,			   *
*	totalStepsTaken, averageHeartRate, maxSteps, start, end					   *
*******************************************************************************/

#include "fitbit.h"

int main(void) {

	FILE *infile = NULL;
	FILE *outfile = NULL;

	/* Open files */
	infile = fopen("FitbitData.csv", "r"); 
	outfile = fopen("Results.csv", "w"); 
	
	FitbitData fitBitArray[1440];

	double caloriesBurned = 0.0, distanceWalked = 0.0, averageHeartRate = 0.0;
	int floorsWalked = 0, stepsTaken = 0, maxSteps = 0;
	char worstSleepStart[9] = "", worstSleepEnd[9] = "";
	char * startPtr = &worstSleepStart;
	char * endPtr = &worstSleepEnd;

	if (infile != NULL) {
		/* File has been opened successfully */
		parseData(infile, fitBitArray);
		caloriesBurned = totalCaloriesBurned(fitBitArray);
		distanceWalked = totalDistanceWalked(fitBitArray);
		floorsWalked = totalDistanceWalked(fitBitArray);
		stepsTaken = totalStepsTaken(fitBitArray);
		averageHeartRate = computeAverageHeartRate(fitBitArray);
		worstSleep(fitBitArray, startPtr, endPtr);
		writeResults(outfile, caloriesBurned, distanceWalked, floorsWalked, stepsTaken, maxSteps, worstSleepStart, worstSleepEnd, infile);

	} else {
		printf("file was not successfully opened");
	}

	/* Close files */
	fclose(infile); 
	fclose(outfile);


	return 0;
}