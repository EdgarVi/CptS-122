#include "TestPerson.h"

TestPerson::TestPerson(const string & newName, const int & newAge, 
	const string & newGender, const string & newHeight) : Person(newName, newAge, newGender, newHeight)
{
	//use initialization list 
}

TestPerson::~TestPerson()
{
	cout << "Inside TestPerson()'s destructor" << endl;
}

void TestPerson::testGetName()
{
	string testName = "Bob";
	this->setName(testName);

	if (this->getName() == testName) {
		cout << "testGetName() passed";
	} else {
		cout << "testGetName() failed";
	}
	
}

void TestPerson::testGetAge()
{
	int testAge = 20;
	this->setAge(testAge);

	if (this->getAge() == testAge) {
		cout << "testGetAge() passed";
	}
	else {
		cout << "testGetAge() failed";
	}
}

void TestPerson::testGetGender()
{
	string testGender = "Male";
	this->setGender(testGender);

	if (this->getGender() == testGender) {
		cout << "testGetGender() passed";
	}
	else {
		cout << "testGetGender() failed";
	}
}

void TestPerson::testGetHeight()
{
	string testHeight = "5' 11''";
	this->setHeight(testHeight);

	if (this->getHeight() == testHeight) {
		cout << "testGetHeight() passed";
	}
	else {
		cout << "testGetHeight() failed";
	}
}

void TestPerson::testSetName()
{
	string testName = "Bob";
	this->setName(testName);

	if (this->getName() == testName) {
		cout << "testSetName() passed";
	}
	else {
		cout << "testSetName() failed";
	}
}

void TestPerson::testSetAge()
{
	int testAge = 20;
	this->setAge(testAge);

	if (this->getAge() == testAge) {
		cout << "testSetAge() passed";
	}
	else {
		cout << "testSetAge() failed";
	}
}

void TestPerson::testSetGender()
{
	string testGender = "Male";
	this->setGender(testGender);

	if (this->getGender() == testGender) {
		cout << "testSetGender() passed";
	}
	else {
		cout << "testSetGender() failed";
	}
}

void TestPerson::testSetHeight()
{
	string testHeight = "5' 11''";
	this->setHeight(testHeight);

	if (this->getHeight() == testHeight) {
		cout << "testSetHeight() passed";
	}
	else {
		cout << "testSetHeight() failed";
	}
}

void TestPerson::testAssignmentOperator()
{
	Person notEmptyTestPerson; 
	notEmptyTestPerson.setName("Alex");
	notEmptyTestPerson.setAge(21);
	notEmptyTestPerson.setGender("Female");
	notEmptyTestPerson.setHeight("5' 6''");

	Person emptyPerson;
	
	emptyPerson = notEmptyTestPerson;

	if ((emptyPerson.getName() == "Alex") && (emptyPerson.getAge() == 21) && 
		(emptyPerson.getGender == "Female") && (emptyPerson.getHeight() == "5' 6''")) {
		cout << "= operator test worked";
	} else {
		"= operator test failed";
	}
}

void TestPerson::testInsertionOperator()
{
	Person notEmptyTestPerson;
	notEmptyTestPerson.setName("Alex");
	notEmptyTestPerson.setAge(21);
	notEmptyTestPerson.setGender("Female");
	notEmptyTestPerson.setHeight("5' 6''");

	cout << notEmptyTestPerson;

}

void TestPerson::testExtractionOperator()
{
	Person notEmptyTestPerson;
	cin >> notEmptyTestPerson;
}

