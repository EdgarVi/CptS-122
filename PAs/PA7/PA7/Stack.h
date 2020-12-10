///////////////////////////////////////////////////////////////////////////////
/// \file         Stack.h
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
#pragma once

#include <iostream>
#include <fstream>
#include <string>


#define MAX_STACK_SIZE 100 //define max size of a stack, 100 absent days

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;



class Stack {
public:


	Stack(const int &newStackTop = 0, const int &newStackSize = MAX_STACK_SIZE);
	~Stack();



	//all these functions should execute in constant time
	void push(string newString);
	string pop();
	string peek() const;
	bool isEmpty();


private:
	
	int mStackTop;
	int mStackSize;
	string mStackArray[MAX_STACK_SIZE];
	
};