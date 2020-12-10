///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Edgar Villasenor
/// \date         25 October 2017
/// \brief        Methods associated with binary search tree
///              
///           
///				
///////////////////////////////////////////////////////////////////////////////
#include "BST.h"

///////////////////////////////////////////////////////////////////////
/// BST ()
/// \pre    None
/// \post   BSTNode has been created
/// \param  pNewRoot
/// \return	BST
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BST::BST(BSTNode * pNewRoot)
{
	this->pRoot = pNewRoot;
	mConvertTextStream.open("Convert.txt");
	mMorseTableStream.open("MorseTable.txt");

	parseMorseTable();

}

///////////////////////////////////////////////////////////////////////
/// ~BST ()
/// \pre    BST has been instantiated
/// \post   BST has been destroyed, files closed
/// \param  None
/// \return	None
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BST::~BST()
{
	//close files
	if (mConvertTextStream.is_open()) {
		mConvertTextStream.close();
	}
	if (mMorseTableStream.is_open()) {
		mMorseTableStream.close();
	}

	//delete root node
	delete this->pRoot;

}

///////////////////////////////////////////////////////////////////////
/// parseMorseTable ()
/// \pre    infile has been opened
/// \post   Contents of infile have been inserted to BST
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::parseMorseTable()
{

	char engChar = '\0';
	string morseChar, emptyLine;

	char line[100] = "";

	bool success = false;


	while (!mMorseTableStream.eof()) {
		mMorseTableStream.getline(line, 100, '\n');
		engChar = line[0];

		mMorseTableStream.getline(line, 100, '\n');
		morseChar = line;

		mMorseTableStream.getline(line, 100, '\n'); // move marker to next line
		emptyLine = line;

		// process punctuation markers
		switch (engChar)
		{
		case 'f':
			engChar = '.';
			break;
		case 'c':
			engChar = ',';
			break;
		case 'q':
			engChar = '?';
			break;
		}

		success = insert(pRoot, engChar, morseChar);
	}
}

///////////////////////////////////////////////////////////////////////
/// insert ()
/// \pre    BST has been created
/// \post   Inserted a node to BST
/// \param  newEnglishChar, newMorseChar
/// \return	bool
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
bool BST::insert(const char & newEnglishChar, const string & newMorseChar)
{
	bool success = false;

	success = insert((this->pRoot), newEnglishChar, newMorseChar); // call private insert

	return success;
}

///////////////////////////////////////////////////////////////////////
/// printTree ()
/// \pre    BST has been created
/// \post   BST printed to screen
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::printTree()
{
	cout << "Printing tree..." << endl;
	this->inOrderTraversal();
}

///////////////////////////////////////////////////////////////////////
/// inOrderTraversal ()
/// \pre    BST has been created
/// \post   BST has been traversed in order
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::inOrderTraversal()
{
	inOrderTraversal(this->pRoot); // call private inOrderTraversal
}

///////////////////////////////////////////////////////////////////////
/// inOrderTraversal ()
/// \pre    BST has been created and contents of file have been loaded
/// \post   Morse character has been found in BST
/// \param  newEnglishChar
/// \return	newMorseChar
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
string BST::searchMorse(const char &newEnglishChar)
{
	string newMorseChar;

	newMorseChar = searchMorse((this)->pRoot, newEnglishChar); // call private method

	return newMorseChar;
}

///////////////////////////////////////////////////////////////////////
/// morseCodeConversion ()
/// \pre    BST has been created 
/// \post   Morse characters have been found and echoed to screen
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::morseCodeConversion()
{
	cout << "Using morse code conversion tool" << endl << "Converted text from Convert.txt" << endl;

	char line[100] = "";

	while (!mConvertTextStream.eof()) {
	
		mConvertTextStream.getline(line, 100, '\n'); // load a full line from infile
		
		int i = 0;
		string morseTemp;
		while (line[i] != '\0') {
			// iterate through the character array
			if (line[i] == ' ') {
				// there is a space between words
				cout << "   ";
			} else {
				if (islower(line[i])) {
					// case that the character is lowercase, convert to uppercase
					line[i] = toupper(line[i]);
				}
				morseTemp = searchMorse(line[i]); // search for character's morse equivalent in BST
				cout << morseTemp << " ";
			}
			i++;
		}
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////
/// insert ()
/// \pre    BST has been created 
/// \post   Node inserted to BST
/// \param  pTree, newEnglishChar, newMorseChar
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
bool BST::insert(BSTNode *& pTree, const char & newEnglishChar, const string & newMorseChar)
{
	bool success = false;

	if (pTree == nullptr) {
		// case that the BST is empty
		BSTNode *pMem = nullptr;
		pMem = new BSTNode(newEnglishChar, newMorseChar);

		if (pMem != nullptr) {
			// pMem was successfully created
			success = true;
			pTree = pMem;
		}
	} else if (newEnglishChar > (pTree)->getEnglishCharacter()) {
		// newMorseChar is larger so go down right subtree
		success = insert(((pTree)->getRight()), newEnglishChar, newMorseChar);
	} else if (newEnglishChar < (pTree)->getEnglishCharacter()) {
		// newMorseChar is smaller so go down left subtree
		success = insert(((pTree)->getLeft()), newEnglishChar, newMorseChar);
	}
	
	return success;
}

///////////////////////////////////////////////////////////////////////
/// searchMorse ()
/// \pre    BST has been created 
/// \post   newMorseChar has been found
/// \param  pTree, newEnglishChar
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
string BST::searchMorse(BSTNode * pTree,  const char &newEnglishChar)
{
	string newMorseChar;

	if ((pTree)->getEnglishCharacter() == newEnglishChar) {
		//base case
		newMorseChar = (pTree)->getMorseCharacter();
	} else if (newEnglishChar > (pTree)->getEnglishCharacter()) {
		//newEnglishChar is larger so go down right subtree
		newMorseChar = searchMorse(((pTree)->getRight()), newEnglishChar);
	} else if (newEnglishChar < (pTree)->getEnglishCharacter()) {
		//newEnglishChar is smaller so go down left subtree
		newMorseChar = searchMorse(((pTree)->getLeft()), newEnglishChar);
	} 	
	return newMorseChar;

}


///////////////////////////////////////////////////////////////////////
/// inOrderTraversal ()
/// \pre    BST has been created 
/// \post   BST has been traversed in order
/// \param  pTree
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::inOrderTraversal(BSTNode * pTree)
{
	// iterate through tree, print nodes from smallest to largest
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		cout << "English Character: " << pTree->getEnglishCharacter() << ", Morse Code Character: " << pTree->getMorseCharacter() << endl;
		inOrderTraversal(pTree->getRight());
	}
}


