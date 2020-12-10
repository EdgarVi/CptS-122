// This example will allow us to explore
// classes, data members, member functions,
// constructor, destructors, function overloading,
// operator overloading, etc. We are building
// these ideas around a Rational object

// History: 10/6/17 - Discussed "information hiding" and
//                    "composition". Implemented overloaded
//                    equality == operator for Rational. 
//                    Redifined the getters for Rational so
//                    that they're constant functions.
//          10/4/17 - Discussed basic file processing.
//                    Implemented overloaded stream extraction
//                    operator for ifstream. Implemented a 
//                    function template for comparing two objects
//                    to see if they're equal.
//          10/2/17 - Added overloaded + operator to Rational

#include "Rational.h"

int main(void)
{
	Rational r1(0, 1), r2(5, 2), r3, r4(7);

	cout << "size r2: " << sizeof(r2) << endl;

	// in the constructor for input, we are opening
	// "number.txt" for "read" or "input" mode. The
	// stream is now an input stream, and we can 
	// "extract" items/objects from it!
	std::ifstream input("number.txt", std::ios::in);

	if (input.is_open()) // were we successful in opening the stream?
	{
		input >> r1; // we overloaded the stream extraction (>>)
		             // operator to work with Rational objects
		cout << r1.getNumerator() << "/" << 
			    r1.getDenominator() << endl;
	}

	// compare is a function template; it checks to see
	// if two objects are equal to each other; the == operator
	// must be overloaded/defined for the objects involved!
	cout << "result: " << compare(5, 9) << endl;
	cout << "result: " << compare(r1, r3) << endl;
	std::string s1 = "cat", s2 = "cat";
	cout << "result: " << compare(s1, s2) << endl;

	//cout << "result: " << compare(5, 9) << endl;

	//r1 = r2.add(r4);
	//r1 = r2 + r4;

	//cout << "r1: " << r1.getNumerator () << "/" << r1.getDenominator () << endl;

	return 0;
}