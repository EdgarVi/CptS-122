/******************************************************************************
* Programmer: Edgar Villasenor												  *
* Class: CptS 122 Lab Section 1												  *
* Programming Assignment 2: Digital Music Manager & Doubly Linked Lists Part 1*
* Date: 24 September 2017													  *
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
	int totalSongs = 0;

	Node * recordHead = NULL; /* Initialize head of linked list */

	totalSongs = loadSongs(file, &recordHead);

	int option = 0;

	/* Main program function */
	do {
		printf("Welcome to the main menu\n");
		printf("Please enter the corresponding integer to select your command\n");
		printf("(1) load\n(2) store\n(3) display\n(4) insert\n(5) delete\n(6) edit \n(7)\
 sort\n(8) rate\n(9) play\n(10) shuffle\n(11) exit\n");
		printf("Option: ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			system("cls");
			totalSongs = loadSongs(file, &recordHead);
			break;
		case 2:
			system("cls");
			storeSongs(file, recordHead);
			break;
		case 3:
			system("cls");
			displayList(recordHead);
			break;
		case 4:
			system("cls");
			totalSongs = insertSong(&recordHead, totalSongs);
			break;
		case 5:
			system("cls");
			totalSongs = deleteSong(&recordHead);
			break;
		case 6:
			system("cls");
			editSong(recordHead);
			break;
		case 7:
			system("cls");
			sortSongs(&recordHead);
			break;
		case 8:
			system("cls");
			rateSong(recordHead);
			break;
		case 9:
			playSongs(recordHead);
			break;
		case 10:
			system("cls");
			shuffleSongs(recordHead, totalSongs);
			break;
		case 11:
			endProgram();
			break;
		}
	} while (option != 11);



	return 0;
}