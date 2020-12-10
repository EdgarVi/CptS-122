#include "quiz.h"

char myStrCpy(char * destination, const char * source){
	
	while (*source) {
		*destination = *source;
		source++;
		destination++;
	}

	return destination;
}

char myStrNCat(char * destination, const char * source, int n) {

	if (n != 0) {
		while (*destination != 0) {
			destination++;
		} do {
			if ((*destination = *source++) == 0) {
				break;
			}
			destination++;
		} while (--n != 0);
		*destination = 0;
	}

	return  destination;

}

int myStrCmp(const char * s1, const char * s2) {
	for (; *s1 == *s2; s1++, s2++) {
		if (*s1 == '\0') {
			return 0;
		}
	}

	return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}
