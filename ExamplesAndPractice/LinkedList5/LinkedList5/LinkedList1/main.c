#include "LinkedList.h"

// History: 9/1 - Finished implementing deleteFront (), makeNode (),
//                and insertOrder ()
//
//          8/30 - Implemented insertFront (), printList (),
//                 started deleteFront ()

int main(int argc, char *argv[])
{
	// initList()
	Node *pList = NULL;
	char item[100] = "";

	insertFront(&pList, "milk");
	insertFront(&pList, "steak");
	printList(pList); // should see --> "steak" --> "milk" -->

	deleteFront(&pList, item);
	puts(item); // should see "steak"
	printList(pList); // should see --> "milk" -->

	insertOrder(&pList, "steak");
	insertOrder(&pList, "eggs");
	printList(pList); // should see --> "eggs" --> "milk" --> "steak" -->

	return 0;
}