#include "LinkedList.h"

int main(int arg, char *argv[]) {
	// initList();
	Node * pList = NULL;

	char item[100] = ""; 


	insertFront(&pList, "milk");
	insertFront(&pList, "steak");
	printList(pList);

	deleteFront(&pList, item);
	puts(item);
	printList(pList);

	return 0;
}
