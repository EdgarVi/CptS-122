///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Methods associated with Binary Search Tree
///              
///           
///				
///////////////////////////////////////////////////////////////////////////////
#include "BST.h"

///////////////////////////////////////////////////////////////////////
/// BST ()
/// \pre    None
/// \post   BSTNode has been created
/// \param  pNewRoot
/// \return	BST
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BST::BST(Node * pNewRoot)
{
	this->mpRoot = pNewRoot;
}

///////////////////////////////////////////////////////////////////////
/// ~BST ()
/// \pre    BST has been instantiated
/// \post   BST has been destroyed
/// \param  None
/// \return	None
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BST::~BST()
{
	destroyTree(this->mpRoot);
}

///////////////////////////////////////////////////////////////////////
/// setRootNode ()
/// \pre    BST has been instantiated
/// \post   Root node has been set
/// \param  pNewRoot
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::setRootNode(Node * pNewRoot)
{
	this->mpRoot = pNewRoot;
}

///////////////////////////////////////////////////////////////////////
/// getRootNode ()
/// \pre    Root node has been set
/// \post   Root node has been returned
/// \param  None
/// \return	mpRoot
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
Node * BST::getRootNode()
{
	return this->mpRoot;
}

///////////////////////////////////////////////////////////////////////
/// insert ()
/// \pre    BST has been created
/// \post   Inserted a node to BST
/// \param  newUnits, newData
/// \return	success
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
bool BST::insert(const int & newUnits, const string & newData)
{
	bool success = false;

	success = insert((this->mpRoot), newUnits, newData);

	return success;
}

///////////////////////////////////////////////////////////////////////
/// inOrderTraversal ()
/// \pre    BST has been created
/// \post   BST has been traversed in order
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::inOrderTraversal()
{
	TransactionNode * pTNRoot = dynamic_cast<TransactionNode*>(this->mpRoot);
	inOrderTraversal(pTNRoot); // call private inOrderTraversal
}

///////////////////////////////////////////////////////////////////////
/// findSmallest ()
/// \pre    Nodes have been added to BST
/// \post   Smallest node based on mUnits has been selected
/// \param  pTree
/// \return	TransactionNode &
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
TransactionNode *& BST::findSmallest() const
{

	TransactionNode * pTNRoot = dynamic_cast<TransactionNode*>(this->mpRoot);


	while (pTNRoot->getLeft() != nullptr) {
		pTNRoot = dynamic_cast<TransactionNode*>(pTNRoot->getLeft());
	}

	return pTNRoot;
}

///////////////////////////////////////////////////////////////////////
/// findLargest ()
/// \pre    Nodes haevh been added to BST
/// \post   Largest node based on mUnits has been selected
/// \param  None
/// \return	TransactionNode &
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
TransactionNode *& BST::findLargest() const
{
	TransactionNode * pTNRoot = dynamic_cast<TransactionNode*>(this->mpRoot);


	while (pTNRoot->getRight() != nullptr) {
		pTNRoot = dynamic_cast<TransactionNode*>(pTNRoot->getRight());
	}

	return pTNRoot;
}

///////////////////////////////////////////////////////////////////////
/// insert ()
/// \pre    BST has been created 
/// \post   Node inserted to BST
/// \param  pTree, newUnits, newData
/// \return	success
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
bool BST::insert(Node *& pTree, const int & newUnits, const string & newData)
{
	
	bool success = false;

	TransactionNode * pTNRoot = dynamic_cast<TransactionNode*>(pTree);

	if (pTNRoot == nullptr) {
		// case that the BST is empty
		TransactionNode *pMem = nullptr;
		pMem = new TransactionNode(newUnits, newData);

		if (pMem != nullptr) {
			// pMem was successfully created
			success = true;
			pTree = pMem;
		}
	} else if (newUnits > pTNRoot->getUnits()) {
		// newUnits is larger so go down right subtree
		success = insert(pTNRoot->getRight(), newUnits, newData);
	} else if (newUnits < pTNRoot->getUnits()) {
		// newUnits is smaller so go down left subtree
		success = insert(pTNRoot->getLeft(), newUnits, newData);
	}

	return success;

}

///////////////////////////////////////////////////////////////////////
/// destroyTree ()
/// \pre    BST has been used for all intended purposes 
/// \post   Nodes in BST have been deleted
/// \param  pTree
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BST::destroyTree(Node *& pTree)
{
	if (pTree != nullptr) {
		//delete nodes, post order
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

///////////////////////////////////////////////////////////////////////
 /// inOrderTraversal ()
 /// \pre    BST has been created 
 /// \post   BST has been traversed in order
 /// \param  pTree
 /// \return	Void
 /// \throw	No exception handling
 ///////////////////////////////////////////////////////////////////////
void BST::inOrderTraversal(Node * pTree)
{
	//process Nodes from least units to most
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}

