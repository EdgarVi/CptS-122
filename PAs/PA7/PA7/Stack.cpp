///////////////////////////////////////////////////////////////////////////////
/// \file         Stack.cpp
/// \author       Edgar Villasenor
/// \date         8 November 2017
/// \brief        Stack class, implemented with an array of strings
///
///
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#include "Stack.h"

Stack::Stack(const int & newStackTop, const int & newStackSize)
{
	this->mStackSize = newStackSize;
	this->mStackTop = newStackTop;

}

Stack::~Stack()
{
	//stacks deleted by List's destructor
}

void Stack::push(string newString)
{
	//place new string at top of stack
	this->mStackTop++;
	this->mStackArray[this->mStackTop] = newString;

}  

string Stack::pop()
{
	// return and delete string at top of stack
	string newString;

	newString = mStackArray[mStackTop];
	mStackArray[mStackTop] = "";
	mStackTop--;

	return newString;
}

string Stack::peek() const
{
	//return top string
	string topString;

	topString = mStackArray[mStackTop];

	return topString;
}

bool Stack::isEmpty()
{
	//check if stack is empty
	bool isStackEmpty = false;

	if (this->mStackTop == 0) {
		isStackEmpty = true;
	}
	
	return isStackEmpty;
}
