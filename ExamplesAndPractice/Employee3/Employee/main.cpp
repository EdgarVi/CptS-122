// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

// History: 11/1 - Completed Manager::calculatePay (), Manager's
//                 constructor w/ an initalization list,
//                 discussed the protected keyword/visibility. 
//                 Started discussing the concept of
//                 "programming in the general". Started 
//                 implementing non-member function showPay ().

#include <iostream>
#include <string>


#include "Employee.h"
#include "Manager.h"

void showPayRate(Employee &e);

int main(void)
{
	Employee e1;
	Manager m1("Leah", 50000.00, 5, true);

	e1.setHours(90);

//	cout << "e1: " << e1.calculatePay() << endl;
//	cout << "m1: " << m1.calculatePay() << endl;

	showPayRate(e1);
	showPayRate(m1);

	return 0;
}

void showPayRate(Employee &e)
{
	cout << "e: " << e.calculatePay() << endl;
}