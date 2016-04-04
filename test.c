#include <stdio.h>

#define SIZE 80

int main(void) {
		
	char store[SIZE/2];	
	char (*pt)[10];
	char word[] = "derp";
	pt[1][2] = word[2];
	printf("%c\n", pt[1][2]);
	return 0;
}
