/*
 * Walker VanHouten
 * Lab 5
 * CSCI 112
 * Due: 2/7/16
 */

#include <stdio.h>
#define LENGTH 12	//barcode length

void printBarcode(int in[LENGTH]) {
	printf("\nYou entered the code: ");
	int i;
	for(i = 0; i < LENGTH; i++) {	//print out each element of array with a space after it
		printf("%d ", in[i]);
	}
	printf("\n");
}

int getCheckDigit(int i) {
	//i values range from 0 to 207 therefore it may be necessary to strip off two digits
	if(i >= 100) {
		i = i % 100;	//get last two digits
		i = i % 10;	//get last digit
		
	} else if(i >= 10) {
		i = i % 10;	//get last digit
	}
	if(i == 0) {
		return 0;	//return a 0 if final digit is 0
	} else {
		return 10 - i;	//otherwise return 10 - last digit
	}
}

void verifyBarcode(int in[LENGTH]) {
	//Step 1
	int i;
	int sum = 0;
	for(i = 0; i < LENGTH; i+=2) {	//get sum of odd numbered inputs
		sum += in[i];
	}
	sum = sum * 3;			//multiply sum by 3;
	printf("STEP 1: Sum of odds times 3 is %d\n", sum);
	//Step 2
	int sum2 = 0;
	for(i = 1; i < LENGTH-2; i+=2) {	//get sum of odd numbered inputs
		sum2 += in[i];
	}
	printf("STEP 2: Sum of the even digits is %d\n", sum2);
	//Step 3
	printf("STEP 3: Total sum is %d\n", sum + sum2);	//print out sum of previous two steps
	//Step 4
	int checkDigit = getCheckDigit(sum + sum2);		//extract the last digit from combined sum
	printf("STEP 4: Calculated check digit is %d\n", checkDigit);
	//Step 5: Result
	if(checkDigit == in[LENGTH-1]) {		//find whether valid and print it out
		printf("STEP 5: Check digit and last digit match\n");
		printf("Barcode is VALID.\n");
	} else {
		printf("STEP 5: Check digit and last digit do not match\n");
		printf("Barcode is INVALID.\n");
	}
}

int main( void ) {
	int input[LENGTH];		//create array to store inputs
	int i;
	printf("Enter a bar code to check. Separate digits with a space >\n");
	for(i = 0; i < LENGTH; i++) {	//read in LENGTH number of ints into an array
		scanf("%d", &input[i]);
	}
	printBarcode(input);		//print out the input
	verifyBarcode(input);		//test to find if barcode is valid and print out steps and result
	return 0;
}
