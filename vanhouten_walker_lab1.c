/*
 * Walker VanHouten
 * CSCI 112
 * 31 January 2016
 */

#include <stdio.h>

double i1, i2;	//x1 and x2 vars
int ival;	//find x ival

double sequence(double i) {	//use recursion to find element i of the sequence
	if(i == 1) {
		printf("%lf\n", i1);
		return i1;
	} else if(i == 2) {
		printf("%lf\n", i2);
		return i2;
	} else {
		//printf("%lf\n", (sequence(i-1)/2));
		return (sequence(i-2)/2)+(3*sequence(i-1));
	}	
}

void getInput() {	//for the way this program is currently set up this function makes things look neater.
	printf("Enter x1 value >>>");	//tells the user to "Enter x1 value >>>" literally
	scanf("%lf", &i1);		//gets the value
	printf("Enter x2 value >>>");	//pretty much the same thing
	scanf("%lf", &i2);
	printf("Enter positive sequence value you want >>>");	//pretty much the same thing
	scanf("%d", &ival);
}

void printResult() {	//possibly redundant
	printf("%.2lf\n", sequence(ival));	//prints resulf for the 5th element of the sequence with only 2 decimals
}

int main() {
	getInput();	//honestly just makes things look neater
			//I mean I could have it return values for each var
			//but then I'd have to pass it a string each time to tell
			//the user what to enter for that one
			//and that sounds obnoxious
	//printf("%.2lf\n", sequence(ival));	//prints resulf for the 5th element of the sequence with only 2 decimals
	printResult();	//literally executes the previous line of code that I just commented out after reading the directions
	return 0;
}
