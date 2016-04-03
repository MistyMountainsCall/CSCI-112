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
	printf("running");
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
		if(line[i]==' ') {
			n++;
		}
		i++;
	}
	int a = 0;
	char* wordArr[n];	//get the words and store them in an array
	for(i = 0; i < n; i++) {
		int b = 0;
		while(line[a]!=' ' || line[a]!='\0') {
			*(wordArr + i)[b] = line[a];
			a++;
			b++;
		}
		a++;
	}
	//print out words in reverse order
	for(i = 0; i < n; i++) {
		printf("%s ", *(wordArr + n - i));
	}
	printf("\n");
}
