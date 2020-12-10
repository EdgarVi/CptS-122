#include "Stack.h"
#include "TestStack.h"

int main(void)
{


	Stack s = {NULL}; // empty stack


	char testArray[100] = "cat";
	int index = 0;
	
	Data temp = { '\0' };
	puts(testArray);

	for (index = 0; testArray[index] != '\0'; ++index) {
		temp.info = testArray[index];
		push(&s, temp);
	}

	for (index = 0; !isEmpty(s); ++index) {
		temp = peek(s);
		pop(&s); // removes a node
		testArray[index] = temp.info;
	}

	puts(testArray);

	return 0;
}