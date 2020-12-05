#ifndef FILE_READ_H
#define FILE_READ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_LENGTH 100000
#define MAX_LINE_LENGTH 10000

//reason why i am not returning the string rather than taking input is because it feels more like
//c that way
void read_file(char file_name[], char *out_str)
{
	FILE *fp = fopen(file_name, "r");
	//handle no file found
	char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
	{
		strcat(out_str, line);
	}
	fclose(fp);
}

#endif
