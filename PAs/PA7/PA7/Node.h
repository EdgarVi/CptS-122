///////////////////////////////////////////////////////////////////////////////
/// \file         Node.h
/// \author       Edgar Villasenor
/// \date         8 November 2017
/// \brief        Class that contains nodes used by the linked list
///
///
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Node {
public:
	Node(const int &newRecordNumber = 0, const int &newIDNumber = 0,
		const string &newName = "", const string &newEmail = "",
		const string &newUnits = "", const string &newProgram = "",
		const string &newLevel = "", const int &newAbsences = 0, const Stack &newAbsentDays = NULL); // constructor
	Node(const Node &copy);
	~Node();

	//getters
	int getRecordNumber() const;
	int getIDNumber() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	int getAbsences() const;
	Stack getAbsentStack() const;
	Node * getNextPtr() const;

	//setters
	void setRecordNumber(const int newRecordNumber);
	void setIDNumber(const int newIDNumber);
	void setName(const string newName);
	void setEmail(const string newEmail);
	void setUnits(const string newUnits);
	void setProgram(const string newProgram);
	void setAbsences(const int newAbsences);
	void setAbsentStack(const Stack newAbsentDays);
	void setNextPtr(Node *const pNewNext);

private:
	int mRecordNumber;
	int mIDNumber;
	string mName;
	string mEmail;
	string mUnits;
	string mProgram;
	string mLevel;
	int mAbsences;
	Stack mAbsentDays;

	Node * mpNext;
};