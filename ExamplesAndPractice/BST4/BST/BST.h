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

class BST
{
public:
	BST(Node *pNewRoot = nullptr);

	bool insert(const string &newData);

	void inorderTraversal();

	void postOrderTraversal();

	void preOrderTraversal();
private:
	Node *pRoot;

	bool insert(Node *&pTree, const string &newData);
	void inorderTraversal(Node *pTree);


	void postOrderTraversal(Node *pTree);

	void preOrderTraversal(Node * pTree);
};