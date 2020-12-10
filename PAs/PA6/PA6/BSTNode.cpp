///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Edgar Villasenor
/// \date         25 October 2017
/// \brief        Methods asscociated with BST Nodes
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#include "BSTNode.h"

///////////////////////////////////////////////////////////////////////
/// BSTNode ()
/// \pre    None
/// \post   BSTNode has been created
/// \param  newEnglishCharacter, newMorseCharacter
/// \return	BSTNode
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BSTNode::BSTNode(const char & newEnglishCharacter, const string & newMorseCharacter)
{
	this->mEnglishCharacter = newEnglishCharacter;
	this->mMorseCharacter = newMorseCharacter;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

///////////////////////////////////////////////////////////////////////
/// ~BSTNode ()
/// \pre    BSTNode is done being used
/// \post   BSTNode has been deleted
/// \param  None
/// \return	None
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BSTNode::~BSTNode()
{
	delete this->pLeft;
	delete this->pRight;
}

///////////////////////////////////////////////////////////////////////
/// getEnglishCharacter ()
/// \pre    mEnglishCharacter has been set
/// \post   mEnglishCharacter has been returned
/// \param  None
/// \return	mEnglishCharacter
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
char BSTNode::getEnglishCharacter() const
{
	return this->mEnglishCharacter;
}

///////////////////////////////////////////////////////////////////////
/// getEnglishCharacter ()
/// \pre    mMorseCharacter has been set
/// \post   mMorseCharacter has been returned
/// \param  None
/// \return	mMorseCharacter
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
string BSTNode::getMorseCharacter() const
{
	return this->mMorseCharacter;
}

///////////////////////////////////////////////////////////////////////
/// getLeft ()
/// \pre    pLeft has been set
/// \post   pLeft has been returned
/// \param  None
/// \return	pLeft
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BSTNode *& BSTNode::getLeft()
{
	return this->pLeft;
}

///////////////////////////////////////////////////////////////////////
/// getRight ()
/// \pre    pRight has been set
/// \post   pRight has been returned
/// \param  None
/// \return	pRight
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
BSTNode *& BSTNode::getRight()
{
	return this->pRight;
}

///////////////////////////////////////////////////////////////////////
/// setEnglishCharacter ()
/// \pre    BSTNode instantiated
/// \post   mEnglishCharacter has been set
/// \param  newEnglishCharacter
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BSTNode::setEnglishCharacter(const char & newEnglishCharacter)
{
	this->mEnglishCharacter = newEnglishCharacter;
}

///////////////////////////////////////////////////////////////////////
/// setMorseCharacter ()
/// \pre    BSTNode instantiated
/// \post   mMorseCharacter has been set
/// \param  newMorseCharacter
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BSTNode::setMorseCharacter(const string & newMorseCharacter)
{
	this->mMorseCharacter = newMorseCharacter;
}

///////////////////////////////////////////////////////////////////////
/// setLeft ()
/// \pre    BSTNode instantiated
/// \post   pNewLeft has been set
/// \param  pNewLeft
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BSTNode::setLeft(BSTNode * const pNewLeft)
{
	this->pLeft = pNewLeft;
}

///////////////////////////////////////////////////////////////////////
/// setRight ()
/// \pre    BSTNode instantiated
/// \post   pNewRight has been set
/// \param  pNewRight
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void BSTNode::setRight(BSTNode * const pNewRight)
{
	this->pRight = pNewRight;
}


