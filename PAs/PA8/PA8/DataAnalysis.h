///////////////////////////////////////////////////////////////////////////////
/// \file         DataAnalysis.h
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Create application
///              
///           
///				
///////////////////////////////////////////////////////////////////////////////

#include "BST.h"



class DataAnalysis {

public:
	//Constructors
	DataAnalysis();
	~DataAnalysis();

	//Public methods
	void runAnalysis();

private:
	BST mSoldUnits;
	BST mPurchasedUnits;
	ifstream mDataStream;

	//Private methods
	void openStream();
	void parseStream(ifstream & filestream);
	void insertToTree(string const &newTransactionType, int const &newUnits, string const &newData);
	void displayTrends();
};