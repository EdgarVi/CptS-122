#include "Person.h"

Person::Person(const string & newName, const int & newAge, const string & newGender, const string & newHeight)
{
	mName = newName;
	mAge = newAge;
	mGender = newGender;
	mHeight = newHeight;
}

Person::Person(Person & copy)
{
	mName = copy.getName();
	mAge = copy.getAge();
	mGender = copy.getGender();
	mHeight = copy.getHeight();
}

Person::~Person()
{
	cout << "Inside Person()'s destructor";
}

string Person::getName()
{
	return mName;
}

int Person::getAge()
{
	return mAge;
}

string Person::getGender()
{
	return mGender;
}

string Person::getHeight()
{
	return mHeight;
}

void Person::setName(const string & newName)
{
	mName = newName;
}

void Person::setAge(const int & newAge)
{
	mAge = newAge;
}

void Person::setGender(const string & newGender)
{
	mGender = newGender;
}

void Person::setHeight(const string & newHeight)
{
	mHeight = newHeight;
}

Person & Person::operator=(const Person & rhs)
{

	//check for self assignment
	if (this != &rhs) {
		this->mName = rhs.mName;
		this->mAge = rhs.mAge;
		this->mGender = rhs.mGender;
		this->mHeight = rhs.mHeight;
	}

	//returning left side of operation
	return(*this);
}

ostream & operator<<(ostream & lhs, Person & rhs)
{
	//write to screen
	lhs << rhs.getName() << " " << rhs.getAge() << " " << rhs.getGender() << " " << rhs.getHeight() << endl;

	return lhs;
}

istream & operator >> (istream & lhs, Person & rhs)
{
	//get input from screen
	string name;
	int age;
	string gender, height;


	//get values from a user
	cout << "Name: ";
	cin >> name;
	rhs.setName(name);


	cout << "Age: ";
	cin >> age;
	rhs.setAge(age);

	cout << "Gender: ";
	cin >> gender;
	rhs.setGender(gender);

	cout << "Height: ";
	cin >> height;
	rhs.setHeight(height);


	return lhs;
}
