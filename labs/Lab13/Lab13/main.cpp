//#include "Task1.h"
//
//
//int main(void)
//
//{
//
//	Base* ptr = new Base;
//	ptr->testFunction();         // prints "Base class"
//	delete ptr;
//	ptr = new Derived;
//	ptr->testFunction();         // prints "Base class" because the base class function is not virtual
//	delete ptr;
//
//	return 0;
//
//}

#include "Mammal.h"

#include "Dog.h"



int main()

{

	Mammal *pDog = new Dog;



	pDog->Move();

	pDog->Speak();



	Dog *pDog2 = new Dog;



	pDog2->Move();

	pDog2->Speak();



	return 0;

}