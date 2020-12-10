///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
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
#include "Node.h"


Node::Node(const int & newRecordNumber, const int & newIDNumber, 
	const string & newName, const string & newEmail, 
	const string & newUnits, const string & newProgram, 
	const string & newLevel, const int &newAbsences, const Stack &newAbsentDays)
{
	//constructor for new node
	this->mRecordNumber = newRecordNumber;
	this->mIDNumber = newIDNumber;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mUnits = newUnits;
	this->mProgram = newProgram;
	this->mLevel = newLevel;
	this->mAbsences = newAbsences;
	this->mAbsentDays = newAbsentDays;
	this->mpNext = nullptr;
}

Node::Node(const Node & copy)
{
	mRecordNumber = copy.mRecordNumber;
	mIDNumber = copy.mIDNumber;
	mName = copy.mName;
	mEmail = copy.mEmail;
	mUnits = copy.mUnits;
	mProgram = copy.mProgram;
	mLevel = copy.mLevel;
	mAbsences = copy.mAbsences;
	mAbsentDays = copy.mAbsentDays;
	mpNext = copy.mpNext;
}

Node::~Node()
{
	//Nodes are actually deleted by the List destructor
}


int Node::getRecordNumber() const
{
	return this->mRecordNumber;
}

int Node::getIDNumber() const
{
	return this->mIDNumber;
}

string Node::getName() const
{
	return this->mName;
}

string Node::getEmail() const
{
	return this->mEmail;
}

string Node::getUnits() const
{
	return this->mUnits;
}

string Node::getProgram() const
{
	return this->mProgram;
}

string Node::getLevel() const
{
	return this->mLevel;
}

int Node::getAbsences() const
{
	return this->mAbsences;
}

Stack Node::getAbsentStack() const
{
	return mAbsentDays;
}

Node * Node::getNextPtr() const
{
	return mpNext;
}

void Node::setRecordNumber(const int newRecordNumber)
{
	this->mRecordNumber = newRecordNumber;
}

void Node::setIDNumber(const int newIDNumber)
{
	this->mIDNumber = newIDNumber;
}

void Node::setName(const string newName)
{
	this->mName = newName;
}

void Node::setEmail(const string newEmail)
{
	this->mEmail = newEmail;
}

void Node::setUnits(const string newUnits)
{
	this->mUnits = newUnits;
}

void Node::setProgram(const string newProgram)
{
	this->mProgram = newProgram;
}

void Node::setAbsences(const int newAbsences)
{
	this->mAbsences = newAbsences;
}

void Node::setAbsentStack(const Stack newAbsentDays)
{
	this->mAbsentDays = newAbsentDays;
}

void Node::setNextPtr(Node * const pNewNext)
{
	this->mpNext = pNewNext;
}
