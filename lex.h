#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "read.h"

bool check(char test)
{
	static char accepted_tokens[] = {'>', '<', '+', '-', ',', '.', '[', ']'}; //static so function is faster and better with memory
	for (int n = 0; n < 8; n++) {
		if (test == *(accepted_tokens+n)) {
			return true;
		}
	}
	return false;
}

char *clean(char *str_in)
{
	char *out = malloc(sizeof(char) * MAX_FILE_LENGTH);
	int head = 0;
	for (int n = 0; n < strlen(str_in); n++) {
		if (check(*(str_in+n))) {
			*(out+head) = *(str_in+n);
			head++;
		}
	}
	return out;
}
