// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

// History: 11/8 - Discussed using an array of pointers to
//                 base class objects. Discussed the term
//                 extensibility with inheritance/polymorphishm.
//          11/1 - Completed Manager::calculatePay (), Manager's
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

	Employee *arrEmployees[10];

	cout << "Enter 1. Empl, 2. Manager" << endl;
	int num = 0;
	cin >> num;

	if (num == 1)
	{
		arrEmployees[0] = new Employee;
	}
	else
	{
		arrEmployees[0] = new Manager;
	}

	cout << "Employee size: " << sizeof(Employee) << endl;
	cout << "Manager size: " << sizeof(Manager) << endl;


	e1.setHours(90);

//	cout << "e1: " << e1.calculatePay() << endl;
//	cout << "m1: " << m1.calculatePay() << endl;

	showPayRate(e1);
	showPayRate(m1);
	showPayRate(*arrEmployees[0]); // we could be showing the 
	                               // payRate () for either a(n) 
	                               // Manager or Employee or Officer!!!

	delete arrEmployees[0]; // which destructor is invoked?

	return 0;
}

void showPayRate(Employee &e) // program in the general
{
	// As long as a caculatePay() exists in a class
	// in the Employee hierarchy, then this function
	// doesn't change!
	cout << "e: " << e.calculatePay() << endl;
}