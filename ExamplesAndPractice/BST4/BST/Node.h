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

class Node
{
public:
	Node(const string &newData = "");

	string getData() const;
	Node * &getLeft();
	Node * &getRight();

	void setData(const string &newData);
	void setLeft(Node * const pNewLeft);
	void setRight(Node * const pNewRight);



private:
	string mData;
	Node *pLeft;
	Node *pRight;
};