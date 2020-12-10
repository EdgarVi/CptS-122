#pragma once

#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class Rectangle {

	public:
		/* setters - mutators, change data */

		/* getters -accessors, return data */
		int getLength();
		int getWidth();

	private:
		int mLength;
		int mWidth;
};