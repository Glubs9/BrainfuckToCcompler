#include <stdlib.h>
#include "read.h"
#include "lex.h"
#include "generate.h"

#define MAX_FILE_NAME_LENGTH

int main(int argc, char *argv[])
{
	char *file_name;
	file_name = argv[1];
	//check for no file name given
	char *file_str = malloc(sizeof(char) * MAX_FILE_LENGTH); //might need to allocate
	read_file(file_name, file_str);
	char *cleaned = malloc(sizeof(char) * MAX_FILE_LENGTH);
	cleaned = clean(file_str);
	//generate code (should be fairly easy)
	char *gen_str = generate(cleaned);
	FILE *fp = fopen("a.c", "w+");
	fprintf(fp, "%s", gen_str); //no need for fprintf fputs would work fine
	fclose(fp);
	return 0;
}
