#pragma once



#include <iostream>



using std::cout;

using std::endl;



class Mammal

{

public:

	Mammal(void);

	~Mammal(void);



	virtual void move() const;

	virtual void speak() const;

	/*void Move() const;
	void Speak() const;*/


protected:

	int itsAge;

};