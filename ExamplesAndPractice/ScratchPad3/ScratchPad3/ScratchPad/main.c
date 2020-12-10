// This example is a refresher for some string operations in C.
// This will help you with PA 1

// History: 9/1 - Showed how to add one of the coverted calorie values into
//                the array of structs.
//          8/25 - Discussed reading strings from a file, 
//                 string copy operations, and string token operations

#include "PA1Help.h"

int main(void)
{
	char line[100] = "", copyLine[100] = "", minutes[9], calories[12];
	FitbitData data[1440] = { {"", 0.0, 0.0, 0, 0, 0, NONE} };
	int i = 0;

	FILE *infile = NULL;

	infile = fopen("FitbitData.csv", "r");

	if (infile != NULL)
	{
		// opended the file successfully
		// read the line

		fgets(line, 100, infile); // get the first line - header info
		fputs(line, stdout);
		fgets(line, 100, infile); // get the second line - fitbit data

		strcpy(copyLine, line); // preserve the original line

		// loop
		strcpy (minutes, strtok(copyLine, ",")); // grab the minutes token, separated by comma
		puts(minutes);
		strcpy(calories, strtok(NULL, ",")); // grab the minutes token, separated by comma
		puts(calories);

		// should be in a loop
		data[i].calories = atof(calories);
		printf("calories stored in array of structs at pos %d: %lf\n", i, data[i].calories);

		printf ("calories: %lf\n", atof(calories));
	}

	return 0;
}