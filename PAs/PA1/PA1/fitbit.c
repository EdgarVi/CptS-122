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
#include "fitbit.h"


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
void parseData(FILE * infile, FitbitData fitBitArray[1440]){
	

	char line[100] = "", minutes[9], calories[12], distance[10], floors[10], heartrate[10], steps[10], sleeplevel[10];

	int tokenValid = 0;

	for (int i = 0; i < 1440; i++) {

		//char * token;
		char copyLine[100] = "";


		if (i == 0) {
			fgets(line, 100, infile); // get first line - header data
			puts(line, stdout); // Write the first line to standard out
			strcpy(copyLine, line); // preserve original line
		}

		

		fgets(line, 100, infile);
		strcpy(copyLine, line);
		//printf("raw data: ");
		//puts(copyLine, stdout);
	
		char * token = strtok(copyLine, ",");
		


		char * buffer;
		strncpy(buffer, token, 2);
		if (buffer[1] == ',') {
			// clean line
		}
	



		//minute
		tokenValid = validToken(token);
		if (tokenValid == 1) {
			strcpy(fitBitArray[i].minute, token);
			printf("minute: %s , ", fitBitArray[i].minute);
		} else {
			strcpy(fitBitArray[i].minute, NULL);
			printf("minute: %s , ", fitBitArray[i].minute);
		}


		// calorie
		token = strtok(NULL, ",");
		tokenValid = validToken(token);
		if (tokenValid == 1) {
			fitBitArray[i].calories = atof(token);
			printf("calorie: %lf , ", fitBitArray[i].calories);
		} else {
			fitBitArray[i].calories = -1.0;
			printf("calorie: %lf , ", fitBitArray[i].calories);
		}


		//distance
		token = strtok(NULL, ",");
		tokenValid = validToken(token);
		if (tokenValid == 1) {
			fitBitArray[i].distance = atof(token);
			printf("distance: %lf , ", fitBitArray[i].distance);
		} else {
			fitBitArray[i].distance = -1.0;
			printf("distance: %lf , ", fitBitArray[i].distance);
		}

		//floors
		token = strtok(NULL, ",");
		tokenValid = validToken(token);
		if (tokenValid == 1) {
			fitBitArray[i].floors = atoi(token);
			printf("floors: %d , ", fitBitArray[i].floors);
		} else {
			fitBitArray[i].floors = -1;
			printf("floors: %d , ", fitBitArray[i].floors);
		}

		//heartrate
		token = strtok(NULL, ",");
		tokenValid = validToken(token);
		if (tokenValid == 1) {
			fitBitArray[i].heartRate = atoi(token);
			printf("heartrate: %d , ", fitBitArray[i].heartRate);
		} else {
			fitBitArray[i].heartRate = -1;
			printf("heartrate: %d , ", fitBitArray[i].heartRate);
		}

		// steps
		token = strtok(NULL, ",");
		tokenValid = validToken(token);
		if (tokenValid == 1) {
			fitBitArray[i].steps = atoi(token);
			printf("steps: %d , ", fitBitArray[i].steps);
		} else {
			fitBitArray[i].steps = -1;
			printf("steps: %d , ", fitBitArray[i].steps);
		}


		// sleep level
		token = strtok(NULL, " ,");

		int sleepingLevel = 0;

		tokenValid = validToken(token);
		
		


		if (tokenValid == 1) {
			sleepingLevel = atoi(token);
			switch (sleepingLevel) {
			case 0:
				fitBitArray[i].sleepLevel = NONE;
				break;
			case 1:
				fitBitArray[i].sleepLevel = ASLEEP;
				break;
			case 2:
				fitBitArray[i].sleepLevel = AWAKE;
				break;
			case 3:
				fitBitArray[i].sleepLevel = REALLYAWAKE;
				break;
			}
			printf("\n");
		} else {
			token = NULL;
			fitBitArray[i].sleepLevel = NO_DATA;

		}
	}
	

}


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
/*int validToken(char * token)
{
	int valid = 0;

	int tokenNum = atoi(token);


	switch (*token)
	{
	case ',':
		valid = 0;
		break;
	case ' ':
		valid = 0;
		break;
	case '\0':
		valid = 0;
		break;
	default:
		valid = 1;
		break;
	}

	return valid;
}
*/
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
double totalCaloriesBurned(FitbitData fitBitArray[1440])
{
	double totalCaloriesBurned = 0.0;
	int i = 0;

	while (i < 1440) {
		if (fitBitArray[i].calories != -1.0) {
			totalCaloriesBurned += fitBitArray[i].calories;
		}
		i++;
	}
	return totalCaloriesBurned;
}

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
double totalDistanceWalked(FitbitData fitBitArray[1440])
{
	double distanceWalked = 0.0;

	int i = 0;

	while (i < 1440) {
		if (fitBitArray[i].distance != -1.0) {
			distanceWalked += fitBitArray[i].distance;
		}
		i++;
	}

	return distanceWalked;
}

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
int totalFloorsWalked(FitbitData fitBitArray[1440])
{
	int floorsWalked = 0;

	int i = 0;

	while (i < 1440) {
		if (fitBitArray[i].floors != -1) {
			floorsWalked += fitBitArray[i].floors;
		}
		i++;
	}

	return floorsWalked;
}

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
int totalStepsTaken(FitbitData fitBitArray[1440])
{
	int totalSteps = 0;

	int i = 0;

	while (i < 1440) {
		if (fitBitArray[i].steps != -1) {
			totalSteps += fitBitArray[i].steps;
		}
		i++;
	}

	return totalSteps;
}

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
int maxSteps(FitbitData fitBitArray[1440])
{
	int maxSteps = 0, i = 0;

	while (i < 1440) {
		if (fitBitArray[i].steps != -1) {
			if (maxSteps < fitBitArray[i].steps) {
				maxSteps = fitBitArray[i].steps;
			}
		}
		i++;
	}


	return maxSteps;
}

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
double computeAverageHeartRate(FitbitData fitBitArray[1440])
{

	double avgHeartRate = 0.0, totalHeartRate = 0;

	int i = 0, numHeartRate = 0;
	while (i < 1440) {
		if (fitBitArray[i].heartRate != -1) {
			totalHeartRate += fitBitArray[i].heartRate;
			numHeartRate++;
		}
		i++;
	}

	avgHeartRate = totalHeartRate / totalHeartRate;

	return avgHeartRate;
}

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
void worstSleep(FitbitData fitBitArray[1440], char * start, char * end)
{
	int i = 0;
	int maxRange = 0;

	while (i < 1440) {
	
		if ((fitBitArray[i].sleepLevel != NO_DATA) || (fitBitArray[i].sleepLevel != NONE) || (fitBitArray[i].sleepLevel != ASLEEP)) {
			strcpy(start, fitBitArray[i].minute);
			i++;
			while ((fitBitArray[i].sleepLevel != NO_DATA) || (fitBitArray[i].sleepLevel != NONE) || (fitBitArray[i].sleepLevel != ASLEEP)) {
				strcpy(end, fitBitArray[i].minute);
				i++;
				maxRange++;
			}
		}
		i++;
	}

}

void writeResults(FILE * outfile, int totalCaloriesBurned, int totalDistanceWalked, int totalFloorsWalked, 
	int totalStepsTaken, double averageHeartRate, int maxSteps, char start[9], char end[9])
{
	fputs("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep", outfile);
	fputs(totalCaloriesBurned, totalDistanceWalked, totalFloorsWalked, totalStepsTaken, averageHeartRate, maxSteps, start, end, outfile);
}
