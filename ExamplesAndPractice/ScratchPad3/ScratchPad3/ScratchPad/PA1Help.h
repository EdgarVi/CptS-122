#ifndef PA1_HELP_H
#define PA1_HELP_H

#include <stdio.h>
#include <string.h> // strcpy, strcmp, strtok
#include <stdlib.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

#endif
