#include "BST.h"

BST::BST(Node *pNewRoot)
{
	this->pRoot = pNewRoot;
}


// public
bool BST::insert(const string &newData)
{
	bool success = false;

	success = insert((this->pRoot), newData); // private

	return success;
}

bool BST::insert(Node *&pTree, const string &newData)
{
	bool success = false;

	if (pTree == nullptr) // base case?
	{
		Node *pMem = nullptr;

		pMem = new Node(newData);

		if (pMem != nullptr)
		{
			success = true;
			pTree = pMem;
		}
	}
	else if (newData > (pTree)->getData())// recursive step
	{
		// go down right subtree
		success = insert(((pTree)->getRight()), newData);
	}
	else if (newData < (pTree)->getData())// left subtree
	{
		success = insert(((pTree)->getLeft()), newData);
	}
	else // duplicate
	{
		cout << "dup" << endl;
	}

	return success;
}

void BST::inorderTraversal()
{
	inorderTraversal(this->pRoot);
}

void BST::postOrderTraversal()
{
	postOrderTraversal(this->pRoot);
}

void BST::preOrderTraversal()
{
	preOrderTraversal(this->pRoot);
}




void BST::inorderTraversal(Node *pTree)
{
	//	algorithm: 
	//	1. go as far left as possible 
	//	2. process the node (print)
	//	3. go as far right as possible
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeft());
		cout << pTree->getData() << endl;
		inorderTraversal(pTree->getRight());
	}
}

void BST::postOrderTraversal(Node * pTree)
{
	//	algorithm
	//	1. go far left as possible
	//	2. go far right as possible
	//	3. process the node (print)

	if (pTree != nullptr) {
		postOrderTraversal(pTree->getLeft());
		postOrderTraversal(pTree->getRight());
		cout << pTree->getData() << endl;
	}

}

void BST::preOrderTraversal(Node * pTree)
{
	if (pTree != nullptr) {
		cout << pTree->getData() << endl;
		preOrderTraversal(pTree->getLeft());
		preOrderTraversal(pTree->getRight());
	}
}

// main - 
// FitAppWrapper faw;
// faw.run_app ();
