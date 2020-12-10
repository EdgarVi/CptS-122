#include "Dog.h"

Dog::Dog()
{
	cout << "Inside dog's constructor!" << endl;
	this->itsAge = 1;
}

Dog::~Dog()
{
	cout << "Inside dog's destructor" << endl;
}

void Dog::Move() const
{
	cout << "Dog move" << endl;
}

void Dog::Speak() const
{
	cout << "Dog barks!" << endl;
}
