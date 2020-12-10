#pragma once

#include <iostream>
#include <string>

#include "Person.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// TestPerson publicly inherits from Person
class TestPerson : public Person {
public:
	TestPerson(const string &newName = "", const int &newAge = 0,
		const string &newGender = "", const string &newHeight = "");
	~TestPerson();
	
	//test getters
	void testGetName();
	void testGetAge();
	void testGetGender();
	void testGetHeight();

	//test setters
	void testSetName();
	void testSetAge();
	void testSetGender();
	void testSetHeight();

	//test overloaded operators
	void testAssignmentOperator();
	void testInsertionOperator();
	void testExtractionOperator();
private:

};

//test overloaded operators