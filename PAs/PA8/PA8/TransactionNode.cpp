///////////////////////////////////////////////////////////////////////////////
/// \file         TransactionNode.cpp
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Methods associated with Transaction Node
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////

#include "TransactionNode.h"

///////////////////////////////////////////////////////////////////////
/// Node ()
/// \pre    None
/// \post   Node has been created
/// \param  newData
/// \return	Node
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
TransactionNode::TransactionNode(const int & newUnits, const string & newData) : Node(newData)
{
	this->mUnits = newUnits;
}

///////////////////////////////////////////////////////////////////////
/// ~Node ()
/// \pre    TransactionNode is done being used
/// \post   TransactionNode has been deleted
/// \param  None
/// \return	None
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
TransactionNode::~TransactionNode()
{
	//TransactionNodes are deleted by BST's destroyTree so nothing needed here
}

///////////////////////////////////////////////////////////////////////
/// setUnits ()
/// \pre    TransactionNode instantiated
/// \post   mUnits set
/// \param  newUnits
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void TransactionNode::setUnits(int const & newUnits)
{
	this->mUnits = newUnits;
}

///////////////////////////////////////////////////////////////////////
/// getUnits ()
/// \pre    TransactionNode instantiated
/// \post   mUnits returned
/// \param  None
/// \return	mUnits
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
int TransactionNode::getUnits() const
{
	return mUnits;
}

///////////////////////////////////////////////////////////////////////
/// printData ()
/// \pre    Data members for TransactionNode set
/// \post   Data printed to screen
/// \param  None
/// \return	mUnits
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void TransactionNode::printData()
{
	cout << "Units: " << this->getUnits() << ", Type: " << this->getData() << endl;
}
