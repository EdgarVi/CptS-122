#include "music.h"

/**********************************************************
Function: makeNode()
Date Created: 10 September 2017
Date Last Modified: 11 September 2017
Description: Utility function that creates a node
Input parameters: A pointer to a struct Record
Returns: A struct Node
Preconditions: Memory has been allocated for record
Postconditions: A node has been created
***********************************************************/
Node * makeNode(Record songRecord)
{

	Node * pNew;

	pNew = (Node*)malloc(sizeof(Node));

	if (!pNew) {
		printf("makeNode() failed!\n");
		return NULL;
	}
	else {
		/* Allocate memory for new node */
		strcpy(pNew->songRecord.artist, songRecord.artist);
		strcpy(pNew->songRecord.songAlbum, songRecord.songAlbum);
		strcpy(pNew->songRecord.songTitle, songRecord.songTitle);
		strcpy(pNew->songRecord.genre, songRecord.genre);
		pNew->songRecord.songLength.minutes = songRecord.songLength.minutes;
		pNew->songRecord.songLength.seconds = songRecord.songLength.seconds;
		pNew->songRecord.timesPlayed = songRecord.timesPlayed;
		pNew->songRecord.rating = songRecord.rating;

		pNew->pNext = NULL;
		pNew->pPrev = NULL;

		return pNew;
	}

}

/**********************************************************
Function: insertFront()
Date Created: 12 September 2017
Date Last Modified: 12 September 2017
Description: Inserts a node to the front of the list
Input parameters: A double pointer to a node and pointer to
a struct Record
Returns: An integer that determines success
Preconditions: A head pointer has been initialized
Postconditions: Memory has been allocated for a new node and
the node has been placed at the front of list
***********************************************************/
int insertFront(Node ** recordHead, Record songRecord)
{
	Node * pCur = NULL;
	pCur = makeNode(songRecord);
	int success = 0;

	if (pCur != NULL) {
		success = 1;
		if (*recordHead == NULL) {
			/* The case that list is empty */
			(*recordHead) = pCur;
		}
		else {
			/* Inserting at front */
			pCur->pNext = *recordHead;
			(*recordHead)->pPrev = pCur;
			*recordHead = pCur;
		}
	}

	return success;
}

/**********************************************************
Function: loadSongs()
Date Created: 12 September 2017
Date Last Modified: 14 September 2017
Description: Reads information from the infile to the linked
list
Input parameters: An infile and a double pointer to recordList
Returns: An integer that determines success
Preconditions: A head pointer has been initialized
Postconditions: Contents of the file have been saved to the
linked list
***********************************************************/
int loadSongs(FILE * file, Node ** recordHead)
{
	int success = 0;

	int IDNum = 0;
	file = fopen("musicPlayList.csv", "r");

	if (file != NULL) {
		success = 1;
		printf("File was opened successfully!\n");

		int IDNum = 0;

		char buffer[100];
		char * token;
		Record songRec; /* Declare an empty struct of type record */

						/* Get songs from file */
		while (fgets(buffer, 100, file)) {

			token = strtok(buffer, ",");

			strcpy(songRec.artist, token);

			token = strtok(NULL, ",");
			strcpy(songRec.songAlbum, token);


			token = strtok(NULL, ",");
			strcpy(songRec.songTitle, token);

			token = strtok(NULL, ",");
			strcpy(songRec.genre, token);

			token = strtok(NULL, ":");
			songRec.songLength.minutes = atoi(token);

			token = strtok(NULL, ",");
			songRec.songLength.seconds = atoi(token);

			token = token = strtok(NULL, ",");
			songRec.timesPlayed = atoi(token);

			token = token = strtok(NULL, ",");
			songRec.rating = atoi(token);

			IDNum += 1;
			songRec.ID = IDNum;

			insertFront(recordHead, songRec); /* Place node to the front of the list*/
		}
		fclose(file);
		return IDNum;
	}
	else {
		printf("File did not open!\n");
		return success;
	}
}

/**********************************************************
Function: storeSongs()
Date Created: 12 September 2017
Date Last Modified: 24 September 2017
Description: Writes information to the file from the linked
list
Input parameters: An infile and a double pointer to recordList
Returns: An integer that determines success
Preconditions: A head pointer has been initialized
Postconditions: Contents of the linked list have been written
to the file
***********************************************************/
int storeSongs(FILE * file, Node * recordHead)
{
	int success = 0;
	Node * pCur = recordHead;

	if (recordHead) {
		file = fopen("musicPlayList.csv", "w");
		/* Write to file*/
		while (pCur) {
			fputs(pCur->songRecord.artist, file);
			fprintf(file, ", ");

			fputs(pCur->songRecord.songAlbum, file);
			fprintf(file, ", ");

			fputs(pCur->songRecord.songTitle, file);
			fprintf(file, ", ");

			fputs(pCur->songRecord.genre, file);
			fprintf(file, ", ");

			fprintf(file, "%d", pCur->songRecord.songLength.minutes);
			fprintf(file, ":");

			fprintf(file, "%d", pCur->songRecord.songLength.seconds);
			fprintf(file, ", ");

			fprintf(file, "%d", pCur->songRecord.timesPlayed);
			fprintf(file, ", ");

			fprintf(file, "%d", pCur->songRecord.rating);
			fprintf(file, "\n");

			pCur = pCur->pNext;
		}

		fclose(file);
		success = 1;
		printf("Stored contents to the file\n");
		return success;
	}

	printf("Didn't store contents\n");
	return success;
}

/**********************************************************
Function: displayList()
Date Created: 12 September 2017
Date Last Modified: 20 September 2017
Description: Display contents of the linked list
Input parameters: Pointer to recordList
Returns: Void function
Preconditions: List has been initialized
Postconditions: Songs will be displayed
***********************************************************/
void displayList(Node * recordHead) {
	Node * pCur = recordHead;

	/* Write to console */
	while (pCur) {
		printf("Artist: ");
		fputs(pCur->songRecord.artist, stdout);

		printf(" Album: ");
		fputs(pCur->songRecord.songAlbum, stdout);

		printf(" Song Title: ");
		fputs(pCur->songRecord.songTitle, stdout);

		printf(" Genre: ");
		fputs(pCur->songRecord.genre, stdout);

		printf("Song duration: ");
		fprintf(stdout, "%d", pCur->songRecord.songLength.minutes);

		printf(":");
		fprintf(stdout, "%d", pCur->songRecord.songLength.seconds);

		printf(" Times Played: ");
		fprintf(stdout, "%d", pCur->songRecord.timesPlayed);

		printf(" Rating: ");
		fprintf(stdout, "%d", pCur->songRecord.rating);
		printf("\n");

		pCur = pCur->pNext;
	}
}

/**********************************************************
Function: insertSong()
Date Created: 15 September 2017
Date Last Modified: 24 September 2017
Description: Inserts a new song to the linked list
Input parameters: Pointer to recordHead
Returns:  The total number of songs
Preconditions: List has been initialized
Postconditions: A new song has been inserted into the list
***********************************************************/
int insertSong(Node ** recordHead, int totalSongs)
{
	int success = 0;
	totalSongs++;


	Record songRecord;

	/* Get user input */
	printf("Enter the contents of a new song:\n");

	char newString[100];
	int newNum;


	printf("New artist: ");
	scanf("%s", newString);
	strcpy(songRecord.artist, newString);

	printf("New album: ");
	scanf("%s", newString);
	strcpy(songRecord.songAlbum, newString);


	printf("New song: ");
	scanf("%s", newString);
	strcpy(songRecord.songTitle, newString);


	printf("New genre: ");
	scanf("%s", newString);
	strcpy(songRecord.genre, newString);

	printf("New minutes: ");
	scanf("%d", &newNum);
	songRecord.songLength.minutes = newNum;

	printf("New seconds: ");
	scanf("%d", &newNum);
	songRecord.songLength.seconds = newNum;

	printf("New times played: ");
	scanf("%d", &newNum);
	songRecord.timesPlayed = newNum;

	printf("New rating: ");
	scanf("%d", &newNum);
	songRecord.rating = newNum;

	insertFront(recordHead, songRecord);

	return success;
}

/**********************************************************
Function: deleteSong()
Date Created: 15 September 2017
Date Last Modified: 24 September 2017
Description: Delete a  song from the list list
Input parameters: Pointer to recordHead and the total number
of songs
Returns:  An integer that determines success
Preconditions: List has been initialized
Postconditions: A  song has been deleted from the list
***********************************************************/
int deleteSong(Node ** recordHead)
{
	int success = 0;
	Node * pPrevious = NULL;
	Node * pCur = NULL;

	pCur = *recordHead;

	char song[100];

	printf("Select a song: ");
	scanf("%s", song);

	/* Song is not found */
	while (strcmp(pCur->songRecord.songTitle, song) != 0) {
		pPrevious = pCur;
		pCur = pCur->pNext;
		if (pCur == NULL) {
			return success;
		}
	}

	/* Song is found */
	if (pPrevious == NULL) {
		if (pCur->pNext == NULL) {
			free(pCur);
			*recordHead = NULL;
		}
		else {
			*recordHead = pCur->pNext;
			free(pCur);
		}
	}
	else if (pCur->pNext == NULL) {
		free(pCur);
		pPrevious->pNext = NULL;
	}
	else {
		pPrevious->pNext = pCur->pNext;
		free(pCur);
	}

	success = 1;

	return success;
}

/**********************************************************
Function: editSong()
Date Created: 15 September 2017
Date Last Modified: 24 September 2017
Description: Modify a song in the list
Input parameters: Head of the linked list
Returns:  An integer that determines success
Preconditions: List has been initialized
Postconditions: Contents of a song in the list have been
edited
***********************************************************/
int editSong(Node * recordHead) {
	int success = 0;

	Node * pCur = recordHead;
	char artist[100];

	printf("Select an artist: ");
	scanf("%s", artist);

	/* Search for desired artist */
	while (pCur) {
		if (strcmp(pCur->songRecord.artist, artist) == 0) {
			break;
		}
		pCur = pCur->pNext;
	}

	/* Get user input */
	int attribute = 0;
	printf("Select the corressponding interger to edit attribute:\n");
	printf("(1) Artist\n(2) Album\n(3) Song\n(4) Genre\n(5) Minutes\n(6)\
 Seconds\n(7) Times Played\n(8) Rating\n");
	scanf("%d", &attribute);

	char newString[100];
	int newNum = 0;

	switch (attribute)
	{
	case 1:
		printf("New artist: ");
		scanf("%s", newString);
		strcpy(pCur->songRecord.artist, newString);
		break;
	case 2:
		printf("New album: ");
		scanf("%s", newString);
		strcpy(pCur->songRecord.songAlbum, newString);
		break;
	case 3:
		printf("New song: ");
		scanf("%s", newString);
		strcpy(pCur->songRecord.songTitle, newString);
		break;
	case 4:
		printf("New genre: ");
		scanf("%s", newString);
		strcpy(pCur->songRecord.genre, newString);
		break;
	case 5:
		printf("New minutes: ");
		scanf("%d", &newNum);
		pCur->songRecord.songLength.minutes = newNum;
		break;
	case 6:
		printf("New seconds: ");
		scanf("%d", &newNum);
		pCur->songRecord.songLength.seconds = newNum;
		break;
	case 7:
		printf("New times played: ");
		scanf("%d", &newNum);
		pCur->songRecord.timesPlayed = newNum;
		break;
	case 8:
		printf("New rating: ");
		scanf("%d", &newNum);
		pCur->songRecord.rating = newNum;
		break;
	}


	return success;
}

/**********************************************************
Function: sortSongs()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on user input
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: List has been initialized
Postconditions: The list has been sorted
***********************************************************/
int sortSongs(Node ** recordHead)
{

	int option = 0;

	printf("Search by:\n1) Artist (A-Z)\n2) Album Title (A-Z)\n3) Rating\
 (largest - smallest)\n4) Times Played (largest - smallest)");

	switch (option)
	{
	case 1:
		sortByArtist(&recordHead);
		break;
	case 2:
		sortByAlbumTitle(&recordHead);
		break;
	case 3:
		sortByRating(&recordHead);
		break;
	case 4:
		sortByTimesPlayed(&recordHead);
		break;
	}

}

/**********************************************************
Function: sortByArtist()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on Artist title
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected method of sorting
Postconditions: The list has been sorted
***********************************************************/
int sortByArtist(Node ** recordHead)
{
	Node * pHead = *recordHead; /* pHead will always point tp head of list */
	*recordHead = NULL;
	while (pHead) {
		Node ** pLeft = NULL;
		Node ** pRight = NULL;

		pLeft = &pHead;
		pRight = &pHead->pNext;

		/* Bubble sort used to sort list */
		int swapped = 0; /* if 1, swapped = true */
		{
			while (*pRight) {
				if (strcmp((*pRight)->songRecord.songAlbum, (*pLeft)->songRecord.songAlbum)) {
					Node * pTemp = NULL;
					Record songRecord;
					pTemp = makeNode(songRecord);

					/* Swap right and left pointers */
					pTemp->pPrev = (*pLeft)->pPrev;
					pTemp->pNext = (*pLeft)->pNext;

					(*pLeft)->pPrev = (*pRight)->pPrev;
					(*pLeft)->pNext = (*pRight)->pNext;

					(*pRight)->pPrev = pTemp->pPrev;
					(*pRight)->pNext = pTemp->pNext;
					swapped = 1;
				}
				else {
					pLeft = pRight;
					pRight = &(*pRight)->pNext;
				}
			}

			*pRight = *recordHead;

			if (swapped == 1) {
				*recordHead = *pLeft;
				*pLeft = NULL;
			}
			else {
				*recordHead = pHead;
				break;
			}
		}
	}
}

/**********************************************************
Function: sortByAlbumTitle()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on Album title
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected method of sorting
Postconditions: The list has been sorted
***********************************************************/
int sortByAlbumTitle(Node ** recordHead)
{
	Node * pHead = *recordHead; /* pHead will always point tp head of list */
	*recordHead = NULL;
	while (pHead) {
		Node ** pLeft = NULL;
		Node ** pRight = NULL;

		pLeft = &pHead;
		pRight = &pHead->pNext;

		/* Bubble sort used to sort list */
		int swapped = 0; /* if 1, swapped = true */
		{
			while (*pRight) {
				if (strcmp((*pRight)->songRecord.songAlbum, (*pLeft)->songRecord.songAlbum) > 0) {
					Node * pTemp = NULL;
					Record songRecord;
					pTemp = makeNode(songRecord);

					/* Swap right and left pointers*/
					pTemp->pPrev = (*pLeft)->pPrev;
					pTemp->pNext = (*pLeft)->pNext;

					(*pLeft)->pPrev = (*pRight)->pPrev;
					(*pLeft)->pNext = (*pRight)->pNext;

					(*pRight)->pPrev = pTemp->pPrev;
					(*pRight)->pNext = pTemp->pNext;
					swapped = 1;
				}
				else {
					pLeft = pRight;
					pRight = &(*pRight)->pNext;
				}
			}

			*pRight = *recordHead;

			if (swapped == 1) {
				*recordHead = *pLeft;
				*pLeft = NULL;
			}
			else {
				*recordHead = pHead;
				break;
			}
		}
	};
}

/**********************************************************
Function: sortByRating()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on rating title
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected method of sorting
Postconditions: The list has been sorted
***********************************************************/
int sortByRating(Node ** recordHead)
{
	Node * pHead = *recordHead; /* pHead will always point tp head of list */
	*recordHead = NULL;
	while (pHead) {
		Node ** pLeft = NULL;
		Node ** pRight = NULL;

		pLeft = &pHead;
		pRight = &pHead->pNext;
		/* Bubble sort used for sorting */
		int swapped = 0; /* if 1, swapped = true */
		{
			while (*pRight) {
				if ((*pRight)->songRecord.rating > (*pLeft)->songRecord.rating) {
					Node * pTemp = NULL;
					Record songRecord;
					pTemp = makeNode(songRecord);

					/* Swap right and left pointers */
					pTemp->pPrev = (*pLeft)->pPrev;
					pTemp->pNext = (*pLeft)->pNext;

					(*pLeft)->pPrev = (*pRight)->pPrev;
					(*pLeft)->pNext = (*pRight)->pNext;

					(*pRight)->pPrev = pTemp->pPrev;
					(*pRight)->pNext = pTemp->pNext;
					swapped = 1;
				}
				else {
					pLeft = pRight;
					pRight = &(*pRight)->pNext;
				}
			}

			*pRight = *recordHead;

			if (swapped == 1) {
				*recordHead = *pLeft;
				*pLeft = NULL;
			}
			else {
				*recordHead = pHead;
				break;
			}
		}
	}
}

/**********************************************************
Function: sortByTimesPlayed()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on number of times played title
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected method of sorting
Postconditions: The list has been sorted
***********************************************************/
int sortByTimesPlayed(Node ** recordHead)
{
	Node * pHead = *recordHead; /* pHead will always point tp head of list */
	*recordHead = NULL;
	while (pHead) {
		Node ** pLeft = NULL;
		Node ** pRight = NULL;

		pLeft = &pHead;
		pRight = &pHead->pNext;
		int swapped = 0; /* if 1, swapped = true */
		{
			while (*pRight) {
				if ((*pRight)->songRecord.timesPlayed > (*pLeft)->songRecord.timesPlayed) {
					Node * pTemp = NULL;
					Record songRecord;
					pTemp = makeNode(songRecord);

					/* Swap right and left ptrs*/
					pTemp->pPrev = (*pLeft)->pPrev;
					pTemp->pNext = (*pLeft)->pNext;

					(*pLeft)->pPrev = (*pRight)->pPrev;
					(*pLeft)->pNext = (*pRight)->pNext;

					(*pRight)->pPrev = pTemp->pPrev;
					(*pRight)->pNext = pTemp->pNext;
					swapped = 1;
				}
				else {
					pLeft = pRight;
					pRight = &(*pRight)->pNext;
				}
			}

			*pRight = *recordHead;

			if (swapped == 1) {
				*recordHead = *pLeft;
				*pLeft = NULL;
			}
			else {
				*recordHead = pHead;
				break;
			}
		}
	}
}

/**********************************************************
Function: rateSong()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Rate song selected by user
Input parameters: Head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected a song
Postconditions: A song has been rated
***********************************************************/
int rateSong(Node * recordHead)
{
	int success = 0;

	Node * pCur = recordHead;
	char song[100];

	printf("Select a song to rate: ");
	gets(song);

	/* Search for desired song */
	while (pCur) {
		if (strcmp(pCur->songRecord.songTitle, song) == 0) {
			break;
		}
		else {
			pCur = pCur->pNext;
		}
	}


	int newRating = 0;

	printf("New rating: ");
	scanf("%d", &newRating);
	pCur->songRecord.rating = newRating;


	return success;
}

/**********************************************************
Function: rateSong()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Rate song selected by user
Input parameters: Head of the linked list
Returns:  An integer that determines success
Preconditions: List has been initialized
Postconditions: List has been played
***********************************************************/
int playSongs(Node * recordHead)
{
	/*
	Will need to let user select a song and play all songs until
	you get back to the song
	*/

	int success = 0;

	Node * pCur = recordHead;

	char song[100];

	printf("Select a song: ");
	scanf("%s", song);

	/* Search for desired artist */
	while (pCur) {
		if (strcmp(pCur->songRecord.songTitle, song) == 0) {
			break;
		}
		else {
			pCur = pCur->pNext;
		}
	}

	do {
		printf("Artist: ");
		fputs(pCur->songRecord.artist, stdout);

		printf(" Album: ");
		fputs(pCur->songRecord.songAlbum, stdout);

		printf(" Song Title: ");
		fputs(pCur->songRecord.songTitle, stdout);

		printf(" Genre: ");
		fputs(pCur->songRecord.genre, stdout);

		printf("Song duration: ");
		fprintf(stdout, "%d", pCur->songRecord.songLength.minutes);

		printf(":");
		fprintf(stdout, "%d", pCur->songRecord.songLength.seconds);

		printf(" Times Played: ");
		fprintf(stdout, "%d", pCur->songRecord.timesPlayed);

		printf(" Rating: ");
		fprintf(stdout, "%d", pCur->songRecord.rating);
		printf("\n");

		pCur = pCur->pNext;
		system("pause");
	} while (strcmp(pCur->songRecord.artist, song) == 0);


	return success;
}

/**********************************************************
Function: shuffleSongs()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Function that shuffles the songs in the list
Input parameters: Head of the linked list and total number of songs
Returns:  An integer that determines success
Preconditions: List has been initialized
Postconditions: Songs have been shuffled
***********************************************************/
int shuffleSongs(Node * recordHead, int totalSongs)
{

	Node * pCur = NULL;
	pCur = recordHead;



	while (pCur->pNext != NULL) {
		pCur = pCur->pNext;
		totalSongs++;
	}

	int * randListPtr;

	const int total = totalSongs;

	randListPtr = malloc(sizeof(int) * total);

	if (!randListPtr) {
		/* error allocating memory */
		randListPtr = NULL;
		printf("error\n");
	}

	memset(randListPtr, 0, sizeof(int) * total); /* Initialzie randListPtr */

	int i = 0, k = 0, count = 0;
	int randNum = 0;

	for (count = 0; count < total; count++) {
		randListPtr[count] = rand() % total + 1;
	}


	while (i < total) {
		int r = rand() % total + 1;
		for (k = 0; k < i; k++) {
			if (randListPtr[k] == r) {
				break;
			}
		}
		if (k == i) {
			randListPtr[i++] = r;
		}
	}


	i = 0, k = 0;
	while (i < total) {
		for (k = 0; k < i; k++) {
			if (pCur->songRecord.ID == randListPtr[k]) {
				playSongs(pCur);
			}
			pCur = pCur->pNext;
		}
		pCur = recordHead;
	}
}

/**********************************************************
Function: endProgram()
Date Created: 14 September 2017
Date Last Modified: 14 September 2017
Description: Ends the program
Input parameters: None
Returns: Void function
Preconditions: None
Postconditions: Program has been closed
***********************************************************/
void endProgram() {
	printf("The program is shutting down\n");
	exit(0);
}
