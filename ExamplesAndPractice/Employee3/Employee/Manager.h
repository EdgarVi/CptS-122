#pragma once

#include <iostream>
#include <string>

#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Manager is a derived class, it's derived from Employee - need to complete the inheritance in class
class Manager : public Employee
{
public:
	Manager(const string &newName = "", 
		const double &newPayRate = 0.0, 
		const double &newHours = 0, 
		const bool &newSalariedEmployee = false);
	~Manager();

	// With inheritance, we should NOT have to redefine
	// many of the functions that we find in the Employee
	// class!

	// added 10/30
	bool getIsSalaried() const;
	// added 10/30
	void setIsSalaried(const bool &newIsSalaried);

	// added 10/30
	double calculatePay();

private:
	// added 10/30
	bool mIsSalaried;
};