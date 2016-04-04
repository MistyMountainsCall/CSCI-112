/*
 * Walker VanHouten
 * Lab 6
 * CSCI 112
 * Due: 4/4/2016
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 80

void printReversedWords(char line[]);

int main(int argc, char *argv[]) {
	if(argc<=1) {
		printf("ERROR: Please provide an integer greater than or equal to 0\n");
		return 0;
	}
	int n = (int) strtol(argv[1], NULL, 10);
	int i;
	for(i = 0; i < n; i++) {
		char str[SIZE];
		if ( fgets( str, SIZE, stdin ) ) {
			printReversedWords(str);
		}
	}
	return 0;
}

void printReversedWords(char *line) {
	int n = 0;	//get number of words in line
	int i = 0;
	while(line[i]!='\0') {
		if(line[i]=='\n') {
			break;
		}
		if(line[i]==' ') {
			n++;
		}
		i++;
	}
	//print out words in reverse order
	int a = i - 1;
	int c;
	for(i = 0; i < n; i++) {
		int b = 0;						//reset b to 0. (b represents length of the word/substring to be printed next)
		while(line[a]!=' ' && a>=0) {	//starting from the last character in the string go back until a space or string begining is found
			b++;
			a--;
		}
		for(c = 1; c <= b; c++) {		//print out word found by the previous while loop
			if(line[a+c]!='?' && line[a+c]!='.' && line[a+c]!='!' && line[a+c]!=',')
			printf("%c", line[a+c]);
		}
		a--;
		printf(" ");
	}
	printf("\n");
}
