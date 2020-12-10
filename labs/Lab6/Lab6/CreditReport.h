#pragma once

#include <iostream>
#include <string>


using std::string;
using std::cin;
using std::cout;
using std::endl;

class CreditReport
{
public:
	/* Constructors */
	CreditReport(int cs = 0, int d = 0, string at = '\0',
		int hl = 0, int ac = 0);
	CreditReport(CreditReport & copy);
	~CreditReport();
	/* Getters */
	/* Setters */

	/* Class methods */
	void printReport();
	void updateReport();

private:
	int creditScore;
	int debt;
	string accountType;
	int historyLength;
	int accessCount;
};