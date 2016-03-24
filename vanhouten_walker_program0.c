/*
 * Walker VanHouten
 * CSCI 112
 * 16 February 2016
 */

#include <stdio.h>

int isValid(int i) {	//finds if input is valid
	if(i<1) {	//test for less than 1
		printf("You have entered a number less than 1. Please try again. \n");
		return 1;
	} else if (i>9) {	//test for over 9
		printf("You have entered a number greater than 9. Please try again. \n");
		return 1;
	} else if(i%2==0) {	//test if even
		printf("You have entered an even number. Please try again.\n");
		return 1;
	} else {
		return 0;	//if all other tests are passed return false to escape while loop in getInput
	}
}

int getInput() {	//gets input value from user as could be inferred by its rather fitting name "getInput" who would have thought
	int input;
	do {
		printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
		scanf("%d", &input);	//get an int from standard input
	} while(isValid(input));	//check if valid
	return input;
}

int main() {
	int a, b, k=0, n, up=1, in=getInput();	//variable declaration
	for(a=0;a<in;a++) {	//each loop through does one line of the pattern
		if(up) {	//print top half of pattern
			k++;	//pattern generation
			n = 0;
			for(b=0;b<in;b++) {
				if((in/2-k<b)&&(in/2+k>b)) {
					n++;
					printf("%d ", n);
					if(n==in) {	//switch to bottom half of pattern
						up = 0;
					}
				} else {
					printf("  ");
				}
			}
			printf("\n");
		} else {	//print bottom half of pattern
			k--;	//pattern generation
			n = 0;
			for(b=0;b<in;b++) {
				if((in/2-k<b)&&(in/2+k>b)) {
					n++;
					printf("%d ", n);
				} else {
					printf("  ");
				}
			}
			printf("\n");
		}
	}
}
