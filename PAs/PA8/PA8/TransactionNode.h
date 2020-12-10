///////////////////////////////////////////////////////////////////////////////
/// \file         TransactionNode.h
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Publically inherits from Node, contain
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"

class TransactionNode : public Node {
public:
	//Constructors
	TransactionNode(const int &newUnits = 0, const string &newData = "");
	~TransactionNode();

	//Setter
	void setUnits(int const &newUnits);

	//Getter
	int getUnits() const;
	
	void printData();
private:
	int mUnits;
};