///////////////////////////////////////////////////////////////////////////////
/// \file         List.cpp
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
#include "List.h"

List::List()
{
	mpHead = nullptr;
}

List::~List()
{
	destroyList();
}

Node * List::getHeadPtr() const
{
	return mpHead;
}

void List::setHeadPtr(Node * const pNewHead)
{
	this->mpHead = pNewHead;
}

bool List::insertAtFront(const int newRecordNumber, const int newIDNumber, 
						const string newName, const string newEmail, 
						const string newUnits, const string newProgram, 
						const string newLevel, const int newAbsences, const Stack newAbsentDays)
{
	bool success = false;

	Node * pMem = makeNode(newRecordNumber, newIDNumber, newName, newEmail,
		newUnits, newProgram, newLevel, newAbsences, newAbsentDays);
	
	if (pMem != nullptr) {
		//if creation of the new node was successful, set next pointer
		success = true;
		pMem->setNextPtr(this->mpHead); 
		this->mpHead = pMem;
	}

	return success;
}

bool List::deleteAtFront()
{
	bool success = false;

	if (mpHead != nullptr) {
		Node * pTemp = mpHead->getNextPtr();
		delete mpHead;
		mpHead = pTemp;
		success = true;
	}
	return success;
}

Node * List::makeNode(const int newRecordNumber, const int newIDNumber,
					const string newName, const string newEmail, 
					const string newUnits, const string newProgram,	
					const string newLevel, const int newAbsences, const Stack newAbsentDays)
{
	//create a new node
	Node * pMem = new Node(newRecordNumber, newIDNumber, newName, newEmail,
		newUnits, newProgram, newLevel, newAbsences, newAbsentDays);

	return pMem;
}

void List::destroyList()
{
	destroyListHelper(mpHead);
}

void List::destroyListHelper(Node * const pMem)
{
	if (pMem != nullptr) {
		//delete nodes allocated on the heap
		destroyListHelper(pMem->getNextPtr());
		delete pMem;
	}
}
