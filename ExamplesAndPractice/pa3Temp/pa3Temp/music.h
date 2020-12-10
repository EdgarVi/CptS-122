#pragma once

#include <stdio.h> /* Used for standard input/output */
#include <stdlib.h> /* Needed for exit() */
#include <string.h> /* Used for strtok(), strcpy(), etc. */
#include <time.h> /* Used for generating list of random numbers */

/* Struct definitions */
typedef struct duration {

	int minutes;
	int seconds;

} Duration;

typedef struct record {

	char songTitle[100];
	char songAlbum[100];
	char artist[100];
	char genre[100];
	Duration songLength;
	int timesPlayed;
	int rating;
	int ID;
} Record;


typedef struct node {

	Record songRecord;
	struct node * pNext;
	struct node * pPrev;

} Node;

/**********************************************************
Function: makeNode()
Date Created: 10 September 2017
Date Last Modified: 24 September 2017
Description: Utility function that creates a node
Input parameters: A pointer to a struct Record
Returns: A struct Node
Preconditions: Memory has been allocated for record
Postconditions: A node has been created
***********************************************************/
Node * makeNode(Record songRecord);

/**********************************************************
Function: insertFront()
Date Created: 12 September 2017
Date Last Modified: 24 September 2017
Description: Inserts a node to the front of the list
Input parameters: A double pointer to a node and pointer to
a struct Record
Returns: An integer that determines success
Preconditions: A head pointer has been initialized
Postconditions: Memory has been allocated for a new node and
the node has been placed at the front of list
***********************************************************/
int insertFront(Node ** recordHead, Record songRecord);

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
int loadSongs(FILE * file, Node ** recordHead);

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
int storeSongs(FILE * file, Node * recordHead);

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
void displayList(Node * recordHead);

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
int insertSong(Node ** recordHead, int totalSongs);

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
int deleteSong(Node ** recordHead);

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
int editSong(Node * recordHead);

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
int sortSongs(Node ** recordHead);

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
int sortByArtist(Node ** recordHead);

/**********************************************************
Function: sortByAlbumTitle()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on Artist title
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected method of sorting
Postconditions: The list has been sorted
***********************************************************/
int sortByAlbumTitle(Node ** recordHead);

/**********************************************************
Function: sortByRating()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Sort the list based on Artist title
Input parameters: Pointer to the head of the linked list
Returns:  An integer that determines success
Preconditions: User has selected method of sorting
Postconditions: The list has been sorted
***********************************************************/
int sortByRating(Node ** recordHead);

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
int sortByTimesPlayed(Node ** recordHead);

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
int rateSong(Node * recordHead);

/**********************************************************
Function: rateSong()
Date Created: 20 September 2017
Date Last Modified: 24 September 2017
Description: Used has selected to play songs
Input parameters: Head of the linked list
Returns:  An integer that determines success
Preconditions: List has been initialized
Postconditions: List has been played
***********************************************************/
int playSongs(Node * recordHead);

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
int shuffleSongs(Node * recordHead, int totalSongs);

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
void endProgram();