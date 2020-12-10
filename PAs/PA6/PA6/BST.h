///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.h
/// \author       Edgar Villasenor
/// \date         25 October 2017
/// \brief        Creates a binary search tree
///              
///           
///				
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BSTNode.h"

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

using namespace std;

class BST {
public:
	BST(BSTNode *pNewRoot = nullptr); // Constructor
	~BST(); // Destructor


	void parseMorseTable(); 
	bool insert(const char &newEnglishChar, const string &newMorseChar);
	
	void printTree();
	void inOrderTraversal();

	string searchMorse(const char &newEnglishChar);
	void morseCodeConversion();


private:
	BSTNode *pRoot;
	fstream mConvertTextStream;
	fstream mMorseTableStream;

	// private methods
	bool insert(BSTNode * &pTree, const char &newEnglishChar, const string &newMorseChar);
	string searchMorse(BSTNode *pTree, const char &newEnglishChar);
	void inOrderTraversal(BSTNode *pTree);
};

