/*
 * idea is to define c equivalents to all commands.
 * i should be able to define [] as goto statements
 *  to do that i need to match pairs and write a unique value next to them.
 *  like 1 and 2 maybe
 *  idk about that but i should be bale to map everything pre easily.
 *  maybe i could write it in some new form where i first match all open and closed parens and
 *  struct it up and then go through and add each one or something
 *
 *
 *  main func:
 *	strcat #include <stdlib.h>
 *	strcat #include <stdio.h>
 *	match_braces //this is the hard part 
 *	for n in chars
 *	    strcat(ret, find_str(n))
 *
 *  okay actually we could have it be that when the generator discovers a [ it finds the matching ]
 *  and then it adds to a list the position of the ] and the id of the open and htne when it
 *  encounters ] it outputs the vlaue there
 */

//note: newlines in compiled code unecersarry but might be deleted later

#include <stdlib.h>
#include <string.h>

#define BRACKET_MAX 10000
int matched_brackets[BRACKET_MAX][2];

int match_bracket(char *tokens, int pos)
{
	static int am = 0;
	int brackets_needed = 0;
	do {
		switch (*(tokens+pos)) {
		case '[':
			brackets_needed++;
			break;
		case ']':
			brackets_needed--;
			break;
		}
		pos++;
	} while(brackets_needed != 0);
	matched_brackets[am][0] = pos-1; //not setting or something like that
	matched_brackets[am][1] = am;
	am++;
	return am-1;
}

int find_bracket(int pos)
{
	for (int n = 0; n < BRACKET_MAX; n++) {
		if (pos == matched_brackets[n][0]) {
			return matched_brackets[n][1];
		}
	}
	//error nothing found
	printf("no bracket found \n");
	return -1;
}

char *open_bracket(char *tokens, int pos)
{
	int position = match_bracket(tokens, pos);
	char *buff = malloc(sizeof(char) * 1000); //change size later mayb?
	sprintf(buff, "n%do: ;if(t[p]==0){goto n%dc;}", position, position);
	return buff;
}

char *close_bracket(char *tokens, int pos)
{
	int position = find_bracket(pos);
	char *buff = malloc(sizeof(char) * 1000);
	sprintf(buff, "n%dc: ;if(t[p]!=0){goto n%do;}", position, position);
	return buff;
}

//i could move handling [ and ] outside this function so i don't have to pass tokens and pos
char *gen_char(char tok, char *tokens, int pos) 
{
	switch (tok) {
	case '<':
		return "p--;";
	case '>':
		return "p++;";
	case '+':
		return "t[p]++;";
	case '-':
		return "t[p]--;";
	case '.':
		return "putchar(t[p]);";
	case ',':
		return "scanf(\" %c\", &(t[p]));"; //dowhile loop for flushing input before user input
	case '[':
		return open_bracket(tokens, pos);
	case ']':
		return close_bracket(tokens, pos);
	}
	//error do something if this happens
}

#define MAX_OUTPUT_LENGTH 10000000

//if i were writing this proper i would have chucked it into an ast first but i thought it would
//just be easier to just do it manually when i discover square brackets
char *generate(char *tokens)
{
	char *output = malloc(sizeof(char) * MAX_OUTPUT_LENGTH);
	strcpy(output, "#include <stdio.h>\nint main(){int t[30000];int p=0;");
	for (int n = 0; n < strlen(tokens); n++) {
		strcat(output, gen_char(*(tokens+n), tokens, n));
	}
	strcat(output, "return 0;}");
	return output;
}
