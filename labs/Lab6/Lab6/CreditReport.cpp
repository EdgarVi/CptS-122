#include "CreditReport.h"

CreditReport::CreditReport(int cs, int d, string at,
	int hl, int ac) 
{
	this->creditScore = cs;
	this->debt = d;
	this->accountType = at;
	this->historyLength = hl;
	this->accountType = at;

}

CreditReport::CreditReport(CreditReport & copy)
{
	this->creditScore = copy.creditScore;
	this->debt = copy.debt;
	this->accountType = copy.accountType;
	this->historyLength = copy.historyLength;
	this->accessCount = copy.accessCount;

}

CreditReport::~CreditReport()
{
	/*
	Deallocate previously allocated memory
	*/
}