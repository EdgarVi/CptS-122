///////////////////////////////////////////////////////////////////////////////
/// \file         main.cpp
/// \author       Edgar Villasenor
/// \date         17 November 2017
/// \brief        Data analysis using binary search tree. Data about items 
///				  purchased and sold are read in from a csv file, data.csv. 
///				  That information is placed into two different BSTs based 
///				  on whether the item was sold or purchased. The items that
///				  were purchased or sold the least amount and greatest amount
///				  are selected using the appropriate BST and displayed to the 
///				  screen.
///				
///////////////////////////////////////////////////////////////////////////////
#include "DataAnalysis.h"
int main(void) {


	DataAnalysis MainApplication;

	MainApplication.runAnalysis();

	return 0;
}