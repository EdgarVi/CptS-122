#include "Complex.h"

Complex::Complex(double r, double i) 
{
	this->real = r;
	this->img = i;
}

Complex::Complex(Complex & copy)
{
	this->real = copy.real;
	this->img = copy.img;
}

double Complex::getReal() const 
{
	return this->real;
}

double Complex::getImag() const
{
	return this->img;
}

void Complex::setImag(double i) 
{
	img = i;
}

void Complex::setReal(double r) 
{
	real = r;
}

Complex Complex::add(Complex c2) 
{
	Complex temp;
	temp.img = c2.img + this->img;
	temp.real = c2.real + this->real;

	return temp;
}

Complex Complex::sub(Complex c2)
{
	Complex temp;
	temp.img = c2.img - this->img;
	temp.real = c2.real - this->real;

	return temp;
}

void Complex::print()
{
	std::cout << real << " + " << img << "i" << std::endl;
}

void Complex::read() 
{
	/*  
	user input: "a+bi"
	*/
	std::string s;
	std::cin >> s;

	this->real = std::stod(s.substr(0, s.find('+')));
	this->img = std::stod(s.substr(s.find('+') + 1));


}

/* non member functions */
Complex add(Complex c1, Complex c2) 
{
	Complex temp;

	temp.setReal(c1.getReal() + c2.getReal());
	temp.setImag(c1.getImag() + c2.getImag());

	return temp;
}

Complex operator+(const Complex &c1, const Complex &c2) 
{
	Complex temp;

	temp.setReal(c1.getReal() + c2.getReal());
	temp.setImag(c1.getImag() + c2.getImag());

	return temp;
}

Complex operator-(const Complex &c1, const Complex &c2)
{
	Complex temp;

	temp.setReal(c1.getReal() - c2.getReal());
	temp.setImag(c1.getImag() - c2.getImag());

	return temp;
}

std::istream & operator>> (std::istream &lhs, Complex &rhs)
{
	/*Complex temp;

	std::string s;
	std::cin >> s;

	temp.setReal(std::stod(s.substr(0, s.find('+'))));
	temp.setImag(std::stod(s.substr(s.find('+') + 1)));*/

	std::string s;
	lhs >> s;

	rhs.setReal(std::stod(s.substr(0, s.find('+'))));
	lhs.setImag(std::stod(s.substr(s.find('+') + 1)));
	
	return lhs;

}

std::ostream & operator << (std::ostream &lhs, Complex &rhs)
{
	lhs << rhs.getReal << " + " << rhs.getImag() << "i" << std::endl;

	return lhs;
}