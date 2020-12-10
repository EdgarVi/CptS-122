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
Node * makeNode(Record * record)
{
	/* Allocate memory for node */
	Node * pNew = NULL;
	pNew = (Node*)malloc(sizeof(Node));

	/* Check to see if there was space if not, return null */
	if (!pNew) {
		printf("makeNode failed!!");
		return NULL;
	}


	pNew->pNext = NULL;
	pNew->pPrev = NULL;
	printf("made a node!\n");

	return pNew;
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
int insertFront(Node ** recordList, Record * record)
{

	Node * pMem = NULL; 

	pMem = makeNode(record);
	int success = 0;

	if (pMem != NULL) {
		/* Node was successfully created */
		success = 1;
		if (*recordList == NULL) {
			/* Dealing with empty list */
			(*recordList) = pMem;
		}
		else {
			/* List is not empty */
			pMem->pNext = *recordList;
			(*recordList)->pPrev = pMem;
			*recordList = pMem;
		}
	}

	printf("inserted a node at front!!\n");
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
int loadSongs(FILE * file, Node  ** recordList)
{
	int success = 0;

	file = fopen("musicPlayList.csv", "r");

	if (file != NULL) {
		success = 1;
		printf("File was opened successfully!\n");
		
		
		char * token;
		char buffer[100], copyLine[100];
		Record songRec;

		/* Loop through the infile */
		while (fgets(buffer, 100, file)) {
			
			token = strtok(buffer, ",\"");
				
			strcpy(songRec.artist, token);	

			token = strtok(NULL, ",\"");
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

			/* Place current node to the front of the list*/
			insertFront(recordList, &songRec);
		}
		fclose(file);
		return success;
	} else {
		success = 0;
		printf("File did not open!\n");
		return success;
	}


	
}

/**********************************************************
Function: songRating()
Date Created: 12 September 2017
Date Last Modified: 14 September 2017
Description: Allows user to change song rating
Input parameters: Pointer to recordList
Returns: Void function
Preconditions: A head pointer has been initialized
Postconditions: Rating of the song has been changed
***********************************************************/
void songRating(Node * recordList)
{
	Node * pCur = recordList;
	int rating = 0;
	char song[100];

	printf("Song to rate: ");
	scanf("%s", song);

	printf("Rating: ");
	scanf("%d", &rating);

	/* Search for correct song */
	while (pCur->songRecord.songTitle != song) {
		pCur = pCur->pNext;
	}
	/* Edit rating when correct song has been found */
	pCur->songRecord.rating = rating;
}

void playSong(Node * recordList)
{

	Node * pCur = recordList;

	char song[100];
	printf("Song to play: \n");

	scanf("%s", song);


	while (pCur->pNext != NULL) {
		printf("Currently playing: %s by %s", pCur->songRecord.songTitle, pCur->songRecord.artist);
		system("pause");
		system("cls");
		pCur = pCur->pNext;
	}
}

/**********************************************************
Function: displayList()
Date Created: 12 September 2017
Date Last Modified: 14 September 2017
Description: Display contents of the linked list
Input parameters: Pointer to recordList
Returns: Void function
Preconditions: List has been initialized
Postconditions: Songs will be displayed
***********************************************************/
void displayList(Node * recordList)
{
	Node * pCur = recordList;

	while (pCur)
	{
		printf("Contents of selected song:\n");
		printf("Artist: %s, Album : %s, Song : %s, Genre : %s, Duration : %d : %d, Times Played : %d, Rating : %d", pCur->songRecord.artist,\
			pCur->songRecord.songAlbum, pCur->songRecord.songTitle, pCur->songRecord.songLength.minutes, pCur->songRecord.songLength.seconds,\
			pCur->songRecord.timesPlayed, pCur->songRecord.rating);
		pCur = pCur->pNext;
	}
}

/**********************************************************
Function: editSong()
Date Created: 12 September 2017
Date Last Modified: 14 September 2017
Description: Edit all data of a selected song
Input parameters: Pointer to recordList
Returns: Void function
Preconditions: Song has been initialized
Postconditions: Song data has been changed
***********************************************************/
void editSong(Node * recordList)
{

	Node * pCur = recordList;
	char artist[100];

	printf("Select an artist: ");
	scanf("%s", artist);

	/* Search for desired artist */
	while (pCur->songRecord.artist != artist) {
		pCur = pCur->pNext;
	}

	int attribute = 0;
	printf("Select the corressponding interger to edit attribute: ");
	printf("(1) Artist\n(2) Album\n(3) Song\n(4) Genre\n(5) Minutes\n(6) Seconds\n(7) Times Played\n(8) Rating\n");
	scanf("%d", &attribute);

	char newString[100];
	int newNum;

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

}

/**********************************************************
Function: storeContents()
Date Created: 12 September 2017
Date Last Modified: 14 September 2017
Description: Store data to an outfile
Input parameters: File pointer and a pointer to recordList
Returns: Integer that determines success
Preconditions: Linked list has been initialized
Postconditions: File has been closed and data has been
written to the outfile
***********************************************************/
int storeContents(FILE * file, Node * recordList)
{

	int success = 0;
	Node * pCur = recordList;

	if (recordList) {
		file = fopen("musicPlayList.csv", "w");

		while (pCur) {
			fprintf(file, "Artist: %s, Album: %s, Song: %s, Genre: %s, Duration: %d:%d, Times Played: %d, Rating: %d", recordList->songRecord.artist,\
			recordList->songRecord.songAlbum, recordList->songRecord.songTitle, recordList->songRecord.songLength.minutes, recordList->songRecord.songLength.seconds,\
			recordList->songRecord.timesPlayed, recordList->songRecord.rating);
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
Function: endProgram()
Date Created: 14 September 2017
Date Last Modified: 14 September 2017
Description: Ends the program
Input parameters: None
Returns: Void function
Preconditions: None
Postconditions: Program has been closed
***********************************************************/
void endProgram()
{
	printf("The program is shutting down\n");
	exit(0);
}
