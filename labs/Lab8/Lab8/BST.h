#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class BST;

template <class T>
class BSTNode
{
	friend class BST<T>;
private:
	T data;
	BSTNode<T> *pleft;
	BSTNode<T> *pright;

public:
	BSTNode();
	BSTNode(const T &newval);
	~BSTNode();
};

template <class T>
BSTNode<T>::BSTNode()
{
	pleft = nullptr;
	pright = nullptr;
}

template <class T>
BSTNode<T>::BSTNode(const T& newval)
{
	data = newval;
	pleft = nullptr;
	pright = nullptr;
}

template <class T>
BSTNode<T>::~BSTNode()
{
	// don't need anything here.
}

// BST======================================================
template <class T>
class BST
{
private:
	BSTNode<T> *root;

	// helper functions
	BSTNode<T> *& findlocation(BSTNode<T> *&node, T newdata);
	void inOrder(BSTNode<T> *node);
	void preOrder(BSTNode<T> *node);
	void postOrder(BSTNode<T> *node);

public:
	BST();
	~BST();
	void insert(T newdata);
	void inOrder();
	void postOrder();
	void preOrder();
};

template <class T>
BST<T>::BST()
{
	root = nullptr;
}

template <class T>
BST<T>::~BST()
{
	// come back to this
}

template <class T>
BSTNode<T>*& BST<T>::findlocation(BSTNode<T>*& node, T newdata)
{
	if (!node)
		return node;
	if (newdata < node->data)
		return findlocation(node->pleft, newdata);
	else
		return findlocation(node->pright, newdata);
}

template <class T>
void BST<T>::insert(T newdata)
{
	BSTNode<T> *pmem = new BSTNode<T>(newdata);
	if (!root)
	{
		root = pmem;
		return;
	}
	findlocation(root, newdata) = pmem;
}

template <class T>
void BST<T>::inOrder()
{
	inOrder(root);
}

template <class T>
void BST<T>::inOrder(BSTNode<T>* node)
{
	if (!node)
		return;
	inOrder(node->pleft);
	cout << node->data << endl;
	inOrder(node->pright);
}

template <class T>
void BST<T>::preOrder()
{
	preOrder(root);
}

template <class T>
void BST<T>::preOrder(BSTNode<T>* node)
{
	if (!node)
		return;

	cout << node->data << endl;
	preOrder(node->pleft);
	preOrder(node->pright);
}

template <class T>
void BST<T>::postOrder()
{
	postOrder(root);
}

template <class T>
void BST<T>::postOrder(BSTNode<T>* node)
{
	if (!node)
		return;

	postOrder(node->pleft);
	postOrder(node->pright);
	cout << node->data << endl;

}
