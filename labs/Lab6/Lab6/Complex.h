#pragma once

#include <iostream>
#include <string>

class Complex
{
public:
	Complex(double r = 0, double i = 0); /* default constructor*/
	Complex(Complex & copy);
	~Complex(); /* destructor - implicitly invoked when a Complex object leaves scope */


	/* getters */
	double getReal() const;
	double getImag() const;

	/* setters */
	void setReal(double r);
	void setImag(double i);

	Complex add(Complex c2);
	Complex sub(Complex c2);
	void print();
	void read();

private:
	double real;
	double img;
};


/* Non member functions */
Complex add(Complex c1, Complex c2);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator-(const Complex &c1, const Complex &c2);
std::istream & operator >> (std::istream & lhs, Complex &rhs);
std::ostream & operator << (std::ostream &lhs, Complex &rhs);