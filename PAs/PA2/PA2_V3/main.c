/******************************************************************************
* Programmer: Edgar Villasenor												  *
* Class: CptS 122 Lab Section 1												  *
* Programming Assignment 2: Digital Music Manager & Doubly Linked Lists Part 1*
* Date: 13 September 2017													  *
*																			  *
* Description: This is a music manager where users may edit and play songs.   *
*																			  *
* Format of input file ("musicPlayList.csv"):								  *
* Artist (string) Album (string) Song (string) Genre (string)  Minutes (int)  *
* Seconds (int) Times Played (int)  Rating (int)							  *
*																			  *
* Format of output file ("musicPlayList.csv"):								  *
* Artist (string) Album (string) Song (string) Genre (string)  Minutes (int)  *
* Seconds (int) Times Played (int)  Rating (int)							  *
*******************************************************************************/

#include "music.h"

int main(void) {

	FILE * file = NULL;

	Node * recordHead = NULL; /* Initialize head of linked list */
	Record record;

	int option = 0;

	/* Main program function */
	do {
	
		printf("Welcome to the main menu\n");
		printf("Please enter the corresponding integer to select your command\n");
		printf("(1) load\n(2) store\n(3) display\n(4) insert\n(5) delete\n(6) edit \n(7)\
 sort\n(8) rate\n(9) play\n(10) shuffle\n(11) exit\n");
		printf("Option: ");		
		scanf("%d", &option);

		/* Will loop until the user selects 11 to end the program */
		switch (option) {
		case 1:
			system("cls");
			loadSongs(file, &recordHead);
			break;
		case 2:
			system("cls");
			storeContents(file, recordHead);
			break;
		case 3:
			system("cls");
			displayList(recordHead);
			break;
		case 4:
			printf("That feature is not yet supported\n");
			system("pause");
			system("cls");
			break;
		case 5:
			printf("That feature is not yet supported\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			editSong(recordHead);
			break;
		case 7:
			printf("That feature is not yet supported\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			songRating(recordHead);
			break;
		case 9:
			playSong(recordHead);
			break;
		case 10:
			printf("That feature is not yet supported\n");
			system("pause");
			system("cls");
			break;
		case 11:
			endProgram();
			break;
		}
	} while(option != 11);

	return 0;
}