#include "practice.h"

int main(void) {


	char sen[] = "Edgar is really good at coding, he is also very attractive";

	char * word = strtok(sen, " .");
	while (word != NULL) {
		printf("%s\n", word);
		word = strtok(NULL, " .");
	}

	return 0;
}