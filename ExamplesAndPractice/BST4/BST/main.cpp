// This example works with a BST.

// History: 10/16 - Discussed passing a reference to a pointer,
//                  and completed implementing insert (). Implemented
//                  inorderTraversal () as well.
//          10/13 - Motivated design decisions for the insert ()
//                  functions. We still need to finish the 
//                  function.
//          10/11 - Defined parts of class Node and class BST.
//                  We have many more design decisions to make,
//                  along with functions to implement!

#include "Node.h"
#include "BST.h"

int main(void)
{
	BST tree;

	tree.insert("2");
	tree.insert("1");
	tree.insert("4");
	tree.insert("3");

	cout << "In order traversal:" << endl;
	tree.inorderTraversal();

	cout << "Post order traversal:" << endl;
	tree.postOrderTraversal();

	cout << "Pre order traversal:" << endl;
	tree.preOrderTraversal();

	return 0;
}