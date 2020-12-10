/**********************************************************************************
* Programmer: Andrew S. O'Fallon                                                 *
* Class: Cpt S 122; Lab Section 0                                                *
* Programming Assignment:                                                        *
* Date:                                                                          *
*                                                                                *
* Description:                                                                   *
*                                                                                *
*********************************************************************************/

#include <stdio.h>
#include "evaluationDriver.h"

void runApp(void)
{
	char infix[MAX] = { '\0' }, postfix[MAX] = { '\0' };
	int postfixResult = 0;

	printf("Enter infix expression: ");
	gets(infix);

	convertToPostfix(infix, postfix);

	printf("Postfix expression: %s\n", postfix);

	postfixResult = evaluatePostfixExpression(postfix);

	printf("Postfix expression evaluated as: %d\n", postfixResult);
}