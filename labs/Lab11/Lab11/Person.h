#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace std;

//Person is a base class
class Person {
public:

	//constructors
	Person(const string &newName = "", const int &newAge = 0, 
		const string &newGender = "", const string &newHeight = "");
	Person(Person &copy);
	~Person();

	//getters
	string getName();
	int getAge();
	string getGender();
	string getHeight();


	//setters
	void setName(const string &newName);
	void setAge(const int &newAge);
	void setGender(const string &newGender);
	void setHeight(const string &newHeight);

	// overloaded assignment operator =
	Person & operator = (const Person &rhs);

private:
	string mName;
	int mAge;
	string mGender;
	string mHeight;
};




// overloaded insertion operator <<
ostream & operator << (ostream &lhs, Person &rhs);
// overloaded extraction operator >>
istream & operator >> (istream &lhs, Person &rhs);