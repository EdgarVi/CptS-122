#include "BST.h"
int main(void) {


	BST<int> b;

	b.insert(5);
	b.insert(3);
	b.insert(7);

	return 0;
}


/*
Templates are generated at run time NOT when compiling
*/