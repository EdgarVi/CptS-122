///////////////////////////////////////////////////////////////////////////////
/// \file         List.h
/// \author       Edgar Villasenor
/// \date         8 November 2017
/// \brief        Class that creates a linked list
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

#include "Node.h"
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;


class List {
public:

	//constructors
	List();
	~List();


	//getters
	Node * getHeadPtr() const;
	
	//setters
	void setHeadPtr(Node * const pNewHead);

	bool insertAtFront(const int newRecordNumber, const int newIDNumber,
		const string newName, const string newEmail,
		const string newUnits, const string newProgram,
		const string newLevel, const int newAbsences, const Stack newAbsentDays);
	bool deleteAtFront();

private:
	//member attributes
	Node * mpHead;
	Node * makeNode(const int newRecordNumber, const int newIDNumber,
		const string newName, const string newEmail,
		const string newUnits, const string newProgram,
		const string newLevel, const int newAbsences, const Stack newAbsentDays);


	void destroyList();
	void destroyListHelper(Node * const pMem);
};