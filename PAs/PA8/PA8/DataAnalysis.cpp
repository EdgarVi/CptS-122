///////////////////////////////////////////////////////////////////////////////
/// \file         DataAnalysis.cpp
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Create application
///              
///           
///				
///////////////////////////////////////////////////////////////////////////////
#include "DataAnalysis.h"

///////////////////////////////////////////////////////////////////////
/// DataAnalysis ()
/// \pre    None
/// \post   The application has been initialized
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
DataAnalysis::DataAnalysis()
{
	//Nothing needed
}
///////////////////////////////////////////////////////////////////////
/// runAnalysis ()
/// \pre    None
/// \post   mDataStream has been closed
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
DataAnalysis::~DataAnalysis()
{
	//Close stream
	if (mDataStream.is_open()) {
		mDataStream.close();
	}
}

///////////////////////////////////////////////////////////////////////
/// runAnalysis ()
/// \pre    None
/// \post   The application has completed it's run
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void DataAnalysis::runAnalysis()
{
	openStream(); //open stream
	parseStream(mDataStream); //read from stream and populate both BSTs
	displayTrends(); //display trends
}


///////////////////////////////////////////////////////////////////////
/// openStream ()
/// \pre    None
/// \post   "data.csv" has been opened
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void DataAnalysis::openStream()
{
	mDataStream.open("data.csv");

	if (!mDataStream.is_open()) {
		cout << "openStream() failed" << endl;
	}
}

///////////////////////////////////////////////////////////////////////
/// parseStream ()
/// \pre    "data.csv" has been opened
/// \post   Nodes have been placed into appropirate trees
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void DataAnalysis::parseStream(ifstream & filestream)
{

	string line;

	getline(filestream, line, '\n'); //read first line from csv file

	string newTransactionType = "", newData = "";
	int newUnitsSold = 0;


	while (!filestream.eof()) {
		//get units
		getline(filestream, line, ',');
		newUnitsSold = stoi(line);

		//get data
		getline(filestream, line, ',');
		newData = line;

		//get transaction type
		getline(filestream, line, '\n');
		newTransactionType = line;

		//insert to appropriate tree
		insertToTree(newTransactionType, newUnitsSold, newData);
	}

	//Display trees
	cout << "Sold Units Tree:" << endl;
	this->mSoldUnits.inOrderTraversal();
	cout << endl;
	cout << "Purchased Units Tree:" << endl;
	this->mPurchasedUnits.inOrderTraversal();
	cout << endl;

}

///////////////////////////////////////////////////////////////////////
/// insertToTree ()
/// \pre    Line from infile has been read
/// \post   Data has been placed into correct BST
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void DataAnalysis::insertToTree(string const & newTransactionType, int const & newUnits, string const & newData)
{
	//Place into correct BSTs
	if (newTransactionType == "Purchased") {
		this->mPurchasedUnits.insert(newUnits, newData);
	} else if (newTransactionType == "Sold"){
		this->mSoldUnits.insert(newUnits, newData);
	}
}

///////////////////////////////////////////////////////////////////////
/// displayTrends ()
/// \pre    BSTs have been populated
/// \post   Trends have been analysed and displayed
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void DataAnalysis::displayTrends()
{
	
	TransactionNode * pMem = nullptr;
	pMem = new TransactionNode();

	cout << "Analysis of Units Sold" << endl;
	pMem = this->mSoldUnits.findSmallest();
	cout << "Minimum Units Sold" << endl;
	pMem->printData();

	pMem = this->mSoldUnits.findLargest();
	cout << "Maximum Units Sold" << endl;
	pMem->printData();

	cout << endl;

	cout << "Analysis of Units Purchased" << endl;
	pMem = this->mPurchasedUnits.findSmallest();
	cout << "Minimum Units Purchased" << endl;
	pMem->printData();
	cout << "Maximum Units Purchased" << endl;
	pMem = this->mPurchasedUnits.findLargest();
	pMem->printData();

}
