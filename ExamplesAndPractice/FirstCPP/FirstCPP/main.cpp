#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
/* It is poor programming practice to use, using statements */

int function(int num[]);


/* Function overloading? */

int add(int n1, int n2);
double add(double n1, double n2);
string add(string s1, string s2);


int main(void) {
	
	std::cout << "Hello world" << std::endl;
	/* 
	cout is an object, cout has a type associated with it,
	std::ostream
	*/
	

	cout << "Enter a number:	";
	int num = 0;
	cin >> num;
	/*
	cin std::istream
	use >> to extract
	*/
	//cout << "The number is: " << num << endl;


	//cout << "this is a problem" << endl;


	//int num[16];

	//cout << function(num) << endl;

	string s1 = "cat", s2 = "dog";





	cout << add(4, 5) << endl;
	cout << add(4.0, 5.0) << endl;
	cout << add(4.0, (1.0 * 5)) << endl;

	cout << add(s1, s2) << endl;
	return 0;
}



/* 
C++ is object oriented, C is procedural 
Encapsulation
*/

/*
Interview Question: Find size of array
*/
int function(int num[]) {

	int size = sizeof(num) / sizeof(int);
	return size;
}

int add(int n1, int n2)
{
	return n1 + n2;
}

double add(double n1, double n2)
{
	return n1 + n2;
}

string add(string s1, string s2)
{
	/* concatenate strings, only works with standards strings */
	return s1 + s2;
}
