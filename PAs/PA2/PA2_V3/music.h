#pragma once

#include <stdio.h> /* Used for standard input/output */
#include <stdlib.h> /* Needed for exit() */
#include <string.h> /* Used for strtok(), strcpy() */


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
} Record;


typedef struct node {

	Record songRecord;
	struct node * pNext;
	struct node * pPrev;

} Node;



/* Function Prototypes */

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
Node * makeNode(Record * record);

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
int insertFront(Node ** recordList, Record * record);

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
int loadSongs(FILE * file, Node ** recordList);

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
void songRating(Node * recordList);

/**********************************************************
Function: playSong()
Date Created: 12 September 2017
Date Last Modified: 14 September 2017
Description: Play current song and the rest of the songs in
the playlist
Input parameters: Pointer to recordList
Returns: Void function
Preconditions: A head pointer has been initialized
Postconditions: Songs have been played
***********************************************************/
void playSong(Node * recordList);

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
void displayList(Node * recordList);

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
void editSong(Node * recordList);

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
int storeContents(FILE * file, Node * recordList);

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