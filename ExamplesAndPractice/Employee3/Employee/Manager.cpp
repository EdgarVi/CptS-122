#include "Manager.h"

// the Manager is using an initialization list!!!
Manager::Manager(const string &newName,
	const double &newPayRate,
	const double &newHours,
	const bool &newSalariedEmployee) : Employee(newName, newPayRate,
		                                        newHours), mIsSalaried(newSalariedEmployee)
{
	//this->setHours(newHours);
}

Manager::~Manager()
{
	cout << "Inside Manager destructor!" << endl;
}

bool Manager::getIsSalaried() const
{
	return mIsSalaried;
}

void Manager::setIsSalaried(const bool &newIsSalaried)
{
	this->mIsSalaried = newIsSalaried;
}

double Manager::calculatePay()
{
	double pay = 0.0;

	if (!mIsSalaried)
	{
		// hourly, so reuse the Employee's calculatePay ()
		pay = Employee::calculatePay();
	}
	else
	{
		// salaried
		//pay = this->getPayRate();
		this->mPayRate; // can now perform because mPayRate is 
		                // a protected member of Employee
	}

	return pay;
}
