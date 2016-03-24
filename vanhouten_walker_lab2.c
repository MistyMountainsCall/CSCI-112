/*
 * Walker VanHouten
 * CSCI 112
 * 31 January 2016
 */

#include <stdio.h>
#include <math.h>

int n;

int getN(void) {	//gets a positive number for series length
	int n = -1;
	do {
		printf("Enter a value for N that is >= 0: ");
		scanf("%d", &n);
		if(n < -1) {
			printf("Invalid value for N\n");
		} 
	} while(n < 0);
	return n;
}

double getNumber() {	//gets the value of one of the elements in the series
	double num;
	printf("Enter a number: ");
	scanf("%lf", &num);
	return num;
}

double sumArray(double arr[]) {	//adds up values in the array provided
	double sum;
	for(int i = 0;i < n;i++) {
		sum += arr[i];
	}
	return sum;
}

double squareSumArray(double arr[]) {	//adds up the squares of values in the array provided
	double sum;
	for(int i = 0;i < n;i++) {
		sum += arr[i] *arr[i];
	}
	return sum;
}

double averageArray(double arr[]) {	//finds the average of the elements in the array
	if(n == 0) {
		return 0;
	} else {
		return sumArray(arr) / n;
	}
}

double standardDev(double arr[]) {	//calculates the standard deviation of the elements of the provided array
	if(n == 0) {
		return 0;
	} else {
	double out = squareSumArray(arr) / n;
	double avg = averageArray(arr);
	out -= avg * avg;
	return sqrt(out);
	}
}

int main(void) {
	n = getN();		//get number of elements in series
	double array[n];	//create an array to store them in
	if(n == 0) {
		array[0] = 0;		//deal with input of zero series length
	} else {
		array[0] = getNumber();	//get first value
	}
	double highest = array[0];	//set highest and lowest to that val
	double lowest = array[0];
	for(int i = 1; i < n;i++) {
		array[i] = getNumber();		//get values
		if(array[i] > highest) {	//find if higher or lower than previous vals
			highest = array[i];
		}
		if(array[i] < lowest) {
			lowest = array[i];
		}
	}
	printf("The Highest is: %.3lf\n", highest);	//print out results
	printf("The Lowest is: %.3lf\n", lowest);
	printf("The Average is: %.3lf\n", averageArray(array));
	printf("The Range is: %.3lf\n", highest - lowest);
	printf("The Standard deviation is: %.3lf\n", standardDev(array));
	return 0;
}
