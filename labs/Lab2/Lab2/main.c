#include "contactList.h"

int main(int argc, char* argv[])
{
	Node* pHead = 0;
	char* buf[256];
	Contact c;
	FILE* file = NULL;

	c.phone[1] = 0;
	c.email[1] = 0;
	c.title[1] = 0;
	// insert 5 contacts into list
	for (int i = 0; i<5; i++)
	{
		printf("Name of contact: ");
		// could be dangerous, why?
		if (!gets(c.name))
		{
			// safeguard, shouldn't be able to come here
		}
		//// skipped error checking here
		//printf("Phone number: ");
		//gets(c.phone);
		//
		////.... fill out email and title
		//printf("Email: ");
		//gets(c.email);
		//
		//printf("Title: ");
		//gets(c.title);


		if (insertContactInOrder(&pHead, c))
			printf("Insert successful\n");
		else
			printf("Insert failed\n");
	}

	printList(pHead);


	printf("Name of contact to delete: ");
	// could be dangerous, why?
	if (!gets(c.name))
	{
		// safeguard, shouldn't be able to come here
	}
	//// skipped error checking here
	//printf("Phone number: ");
	//gets(c.phone);
	//
	////.... fill out email and title
	//printf("Email: ");
	//gets(c.email);
	//
	//printf("Title: ");
	//gets(c.title);

	if (deleteContact(&pHead, c))
		printf("Delete successful\n");
	else
		printf("Delete failed\n");

	printList(pHead);

	printf("Name of contact to edit: ");
	// could be dangerous, why?
	if (!gets(c.name))
	{
		// safeguard, shouldn't be able to come here
	}
	editContact(pHead, c);

	printList(pHead);



	storeContacts(file, pHead);
	pHead = NULL;
	loadContacts(file, &pHead);

	printList(pHead);


	return 0;
}