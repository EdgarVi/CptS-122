///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.h
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Create binary search tree
///              
///           
///				
///////////////////////////////////////////////////////////////////////////////

#include "TransactionNode.h"

class BST {
public:
	//Constructor
	BST(Node *pNewRoot = nullptr);
	~BST();

	//Setter
	void setRootNode(Node * pNewRoot);

	//Getter
	Node * getRootNode();

	//Public methods
	bool insert(const int &newUnits, const string &newData);
	void inOrderTraversal();
	TransactionNode * &findSmallest() const;
	TransactionNode * &findLargest() const;
private:
	Node * mpRoot;

	//Private methods
	bool insert(Node * &pTree, const int &newUnits, const string &newData);
	void destroyTree(Node * &pTree);
	void inOrderTraversal(Node * pTree);


};