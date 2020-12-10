#include "contactList.h"

Node * makeNode(Contact newData)
{
	Node * pnew;

	pnew = (Node*)malloc(sizeof(Node));

	if (!pnew)
	{
		printf("makeNode failed!\n");
		return NULL;
	}

	strcpy(pnew->data.name, newData.name);
	strcpy(pnew->data.email, newData.email);
	strcpy(pnew->data.phone, newData.phone);
	strcpy(pnew->data.title, newData.title);

	pnew->pNext = NULL;

	return pnew;
}


bool insertContactInOrder(Node **pList, Contact newData) {
	Node *pNew = NULL, *pCur = NULL, *pPrev = NULL;

	pNew = makeNode(newData);
	pCur = *pList;
	if (pNew != NULL)
	{
		while (pCur != NULL && strcmp(pNew->data.name, pCur->data.name) > 0)
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pPrev == NULL)
		{
			*pList = pNew;
			pNew->pNext = pCur;
		}
		else
		{
			pPrev->pNext = pNew;
			pNew->pNext = pCur;
		}

		return TRUE;
	}
	return FALSE;
}

bool deleteContact(Node **pList, Contact searchContact) {
	Node* pPrev, *pCur;

	pPrev = NULL;
	pCur = *pList;

	while (strcmp(pCur->data.name, searchContact.name) != 0)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
		if (pCur == NULL)
			return FALSE;
	}

	if (pPrev == NULL)
	{
		if (pCur->pNext == NULL)
		{
			free(pCur);
			*pList = NULL;
		}
		else
		{
			*pList = pCur->pNext;
			free(pCur);
		}
	}
	else if (pCur->pNext == NULL)
	{
		free(pCur);
		pPrev->pNext = NULL;
	}

	else
	{
		pPrev->pNext = pCur->pNext;
		free(pCur);
	}

	return TRUE;
}

bool editContact(Node *pList, Contact searchContact) {
	Node* pCur = pList;

	while (pCur != NULL)
	{
		if (strcmp(searchContact.name, pCur->data.name) == 0)
		{
			printf("new Name: ");
			gets(pCur->data.name);
			//...
			return TRUE;
		}
		pCur = pCur->pNext;
	}

	return FALSE;
}

// Format: Name,phone,email,title
bool loadContacts(FILE *infile, Node **pList) {
	char buf[100];
	char *token;
	Contact c;

	infile = fopen("contacts.txt", "r");

	while (fgets(buf, 100, infile))
	{
		token = strtok(buf, ",");
		strcpy(c.name, token);
		token = strtok(NULL, ",");
		strcpy(c.phone, token);
		token = strtok(NULL, ",");
		strcpy(c.email, token);
		token = strtok(NULL, ",");
		strcpy(c.title, token);

		insertContactInOrder(pList, c);
	}

	fclose(infile);
	return TRUE;
}

bool storeContacts(FILE *infile, Node *pList) {
	Node* pCur = pList;

	if (pList)
	{
		infile = fopen("contacts.txt", "w");

		while (pCur)
		{
			fprintf(infile, "%s,%s,%s,%s\n", pCur->data.name, pCur->data.phone, pCur->data.email, pCur->data.title);
			pCur = pCur->pNext;
		}
		fclose(infile);
		return TRUE;
	}
	return FALSE;
}

void printList(Node *pList) {
	Node* pCur = pList;

	while (pCur)
	{
		printf("%s, %s, %s, %s\n", pCur->data.name, pCur->data.phone, pCur->data.email, pCur->data.title);
		pCur = pCur->pNext;
	}
}

// more...