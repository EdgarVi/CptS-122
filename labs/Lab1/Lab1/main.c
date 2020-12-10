#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declarations
char* recursive_reverse_str(char* str, int i, int j);
char* sort_strs1(char* str1, char* str2);
char* sort_strs2(char* str1, char* str2);
char* sort_strs3(char* str1, char* str2);
void fileio(FILE* file);

int main()
{
	// variable initialization
	char string[100] = "Welcome to the world of data structures!";
	char* reversed_string;
	char* sort1, *sort2;
	FILE* infile;
	char *sort_result;

	sort1 = (char*)malloc(13);
	sort2 = (char*)malloc(15);
	strcpy(sort1, "almwvxnbyzhi");
	strcpy(sort2, "fgtujkcopqrsde");
	infile = fopen("Test.txt", "r");


	// Task 2a
	printf("Objective 1: reverse \"%s\":\n", string);

	reversed_string = recursive_reverse_str(string, 0, strlen(string) - 1);

	printf("%s\n\n", reversed_string);

	printf("Press Enter to continue...\n");
	getchar();

	// Task 2b
	printf("Objective 2: Sort two strings \"%s\" and \"%s\":\n", sort1, sort2);

	printf("Using a third fixed-size array:\n");
	sort_result = sort_strs1(sort1, sort2);

	//printf("%s\n", sort_result);
	//free(sort_result);

	printf("Press Enter to continue...\n");
	getchar();


	printf("Using a third dynamic array:\n");
	sort_result = sort_strs2(sort1, sort2);

	printf("%s\n", sort_result);
	free(sort_result);

	printf("Press Enter to continue...\n");
	getchar();


	printf("Without using a third array:\n");
	sort_result = sort_strs3(sort1, sort2);

	printf("%s\n\n", sort_result);
	free(sort_result);


	printf("Press Enter to continue...\n");
	getchar();

	// Task 2c
	printf("Objective 3: Count characters in file.\n");
	fileio(infile);



	fclose(infile);
	free(sort1);
	free(sort2);
	return 0;
}

// a. recursively reverse a string
char* recursive_reverse_str(char* str, int i, int j)
{

	char temp;
	
	// base case
	if (i > j) {
		return str;
	}
	
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;

	// recursive call
	recursive_reverse_str(str, ++i, --j); // use pre increments, change the value of i and j before the function is called

	return str;
}

// b. merge two strings in sorted order
// 
//    i. merge into a third fixed size array
char* sort_strs1(char* str1, char* str2)
{

	char merged[100];
	char tmp;
	int i, j;

	strcpy(merged, str1);
	strcat(merged, str2);

	int len = strlen(merged) - 1;

	for (i = 0; i < len; i++) {
		for (j = i; j <= len; j++) {
			if (merged[i] > merged[j]) {
				tmp = merged[i];
				merged[i] = merged[j];
				merged[j] = tmp;
			}
		}
	}

	printf("%s\n", merged);

	//int totalStrLen = 0;
	//totalStrLen = strlen(str1) + strlen(str2) + 1;

	//char str3[] = "", n, c, d, swap;
	////int result = 0;

	////result = strcmp(str1, str2);

	////if (result > 0) {
	////	strcpy(str3, strcat(str2, str1));
	////}
	////else if (result < 0) {
	////	strcpy(str3, strcat(str1, str2));
	////} else {
	////	strcpy(str3, strcat(str1, str2));
	////}



	//strcat(str3, strcat(str1, str2)); //merge the two strings
	////printf("%s", str3);

	//// sorting the merged strings
	//for (c = 0; c < (totalStrLen - 1); c++) {
	//	for (d = 0; d < (totalStrLen - c - 1); d++) {
	//		if (str3[d] > str3[d + 1]) {
	//			swap = str3[d];
	//			str3[d] = str3[d + 1];
	//			str3[d + 1] = swap;
	//		}
	//	}
	//}


	//printf("%s", str3);
	//return NULL;
}

//    ii. merge into a third dynamic array
char* sort_strs2(char* str1, char* str2)
{

	//int i = 0, j = 0, place = 0;
	//char * str3;
	//char tmp;

	//str3 = (char *)malloc(strlen(str1) + strlen(str2));

	//strcpy(str3, str1);
	//strcat(str3, str2);

	//for (j = strlen(str3) - 1; j >= 0; j--) {
	//	place = j;
	//	for (i = 0; i <= j; i++) {
	//		if (str3[i] > str3[place]);
	//	}
	//}


	return NULL;
}

//    ii. merge without using a third array
char* sort_strs3(char* str1, char* str2)
{
	int len1, len2, cIndex;
	char tmp, max;

	len1 = strlen(str1);
	len2 = strlen(str2);

	realloc(str1, 100);
	strcat(str1, str2);

	len1 = strlen(str1);

	for (int i = len1 - 1; i > 0; i--) {
		max = str1[0];
		cIndex = 0;
		for (int j = 0; j <= i; j++) {
			if (str1[j] > max) {
				max = str1[j];
				cIndex = j;
			}
		}
		tmp = str1[i];
		str1[i] = max;
		str1[cIndex] = tmp;
	}

	return str1;
}


//c. count characters within a file
void fileio(FILE* file)
{


	//table - integer array
	int table[256] = {0};
	char read = 10;
	while (read != EOF) {
		read = fgetc(file);
		table[read]++;
	}

	for (int i = 0; i < 256; i++) {
		if (table[i] > 0) {
			printf("%c\t%d\n", i, table[i]);
		}
	}

}