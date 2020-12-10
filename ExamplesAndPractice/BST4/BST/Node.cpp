#include "Node.h"

Node::Node(const string &newData)
{
	this->mData = newData;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

string Node::getData() const
{
	return mData;
}

void Node::setData(const string &newData)
{
	this->mData = newData;
}


Node * &Node::getLeft()
{
	return this->pLeft;
}

void Node::setLeft(Node * const pNewLeft)
{
	this->pLeft = pNewLeft;
}

Node * &Node::getRight()
{
	return this->pRight;
}

void Node::setRight(Node * const pNewRight)
{
	this->pRight = pNewRight;
}
