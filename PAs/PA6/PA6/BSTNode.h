///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.h
/// \author       Edgar Villasenor
/// \date         25 October 2017
/// \brief        Creates a binary search tree node with left and right 
///				  pointers
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BSTNode 
{
public:
	
	//constructor
	BSTNode(const char &newEnglishCharacter = '\0', const string &newMorseCharacter = "");
	~BSTNode();

	//getters
	char getEnglishCharacter() const;
	string getMorseCharacter() const;
	BSTNode * &getLeft();
	BSTNode * &getRight();


	//setters
	void setEnglishCharacter(const char &newEnglishCharacter);
	void setMorseCharacter(const string &newMorseCharacter);
	void setLeft(BSTNode * const pNewLeft);
	void setRight(BSTNode * const pNewRight);

private:
	char mEnglishCharacter;
	string mMorseCharacter;
	BSTNode *pLeft;
	BSTNode *pRight;
};

