///////////////////////////////////////////////////////////////////////////////
/// \file         Main Program App (main.cpp)
/// \author       Edgar Villasenor
/// \date         25 October 2017
/// \brief        Program that places morse code into a binary search tree and
///				  allows users to translate english text to morse code
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////

#include "BST.h"

int main(void) {

	
	BST LookupTree;
	
	LookupTree.printTree(); // print BST
	
	system("pause");
	system("cls");

	LookupTree.morseCodeConversion(); // convert english text from infile to morse code and echo the results to screen
	
	return 0;
}
