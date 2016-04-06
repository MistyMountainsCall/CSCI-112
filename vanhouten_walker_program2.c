/*
 * Walker VanHouten
 * Program 2
 * CSCI 112
 * Due: 4/6/2016
 */

#include <stdio.h>

void pluralize(char *word, char *store);

int main(int argc, char *argv[]) {
	/* Print an error message if there are no command line arguments. 			*/
	if(argc <= 1) {
		printf("ERROR: You must pass the nouns to be pluralized as program arguments\n\n\n");
		return 0;
	}
	int i;
	int n = 1;
	/* Run this loop and print noun and respective plural for each argument.	*/
	/* (not including program name of course) 									*/
	for(i = 1; i < argc; i++) {
		while(argv[i][n]) {
			n++;
		}
		char store[n];
		printf("noun:\t%s\n", argv[i]);
		pluralize(argv[i], store);
		printf("plural:\t%s\n\n", store);
	}
	return 0;
}

void pluralize(char *word, char *store) {
	int i = 0;
	/* Transfer word from short argv char array to one of acceptable size and	*/
	/* get the possition of the terminating character of the original string.	*/
	while(word[i]!='\0') {
		store[i] = word[i];
		i++;
	}
	/* Choose which way the word needs to be modified and perform it			*/
	if(word[i-1]!='s' && word[i-1]!='y') {	/* all but y and s endings			*/
		store[i] = 's';
		store[i+1] = '\0';
	} else if(word[i-1]=='y') {				/* y endings						*/
		store[i-1] = 'i';
		store[i] = 'e';
		store[i+1] = 's';
		store[i+2] = '\0';
	} else {								/* s endings						*/
		store[i] = 'e';
		store[i+1] = 's';
		store[i+2] = '\0';
	} 
}
