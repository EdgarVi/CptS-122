///////////////////////////////////////////////////////////////////////////////
/// \file         Node.h
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Virtual base class Node (can not be instantiated on it's own)
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
using namespace std;


class Node {
public:
	//Constructors
	Node(const string &newData = "");
	virtual ~Node();

	//Setters
	void setData(const string &newData);
	void setLeft(Node * const pNewLeft);
	void setRight(Node * const pNewRight);

	//Getters
	string getData() const;
	Node * &getLeft();
	Node * &getRight();

	virtual void printData() = 0; // pure virtual

protected:
	string mData;
	Node * mpLeft;
	Node * mpRight;
};
