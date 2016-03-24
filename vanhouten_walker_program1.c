/*
 * Walker VanHouten
 * Program 1
 * CSCI 112
 * Due: 3/11/2016
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 50	//max number of values in the array

int populate_array( int array[] );			// Fill array with values from user.
void print_array( int array[], int n );			// Print out the array values
void swap( int *location1, int *location2 );		// Swap values of two ints in memory (used to swap two array elements.)
void quicksort( int array[], int low, int high );	// Sorting algorithm
int partition( int array[], int low, int high );	// Find the partition point (pivot)

int main() {
	int arr[MAX_ARRAY_SIZE];
	int n = populate_array(arr);	//fill the array with values from user
	printf("The initial array contains:\n");
	print_array(arr, n);		//printout the entered array
	quicksort(arr, 0, n-1);		//run sorting algorithm
	printf("The array is now sorted:\n");
	print_array(arr, n);		//printout the sorted array
	return 0;
}

int populate_array( int array[] ) {	//fill array with user input and return array length
	int n, i;
	do {		//request a n value from user. loop until a valid input is entered
		printf("Enter the value of n >");
		scanf("%d", &n);
		if(n>MAX_ARRAY_SIZE) {	//if statements tell user what they did wrong
			printf("%d exceeds the maximum array size. Please try again.\n\n", n);
		} else if(n<0) {
			printf("%d is less than zero. Please try again.\n\n", n);
		}
	} while(n>MAX_ARRAY_SIZE || n<0);
	printf("Enter %d integers (positive, negative, or zero) >\n", n);
	for(i=0; i < n;i++) {		//ask the user to input n integers and store them in the array
		scanf("%d", &array[i]);
	}
	return n;	//return array length
}
//prints out the first n elements of array passed
void print_array( int array[], int n ) {
	int i;
	for(i=0; i<n; i++) {	//print out array with formatting
		printf("%+5d\n", array[i]);
	}
}

void swap( int *location1, int *location2 ) {	//swaps values of the two integers at the addresses passed
	int temp = *location1;
	*location1 = *location2;
	*location2 = temp;
}

//begin quicksort algorithm implementation area
//alogorithm sorts array of integers in the array range specified by low and high
//for information on how algorithm works look at https://en.wikipedia.org/wiki/Quicksort
void quicksort( int array[], int low, int high ) {
	int pivot;
	if(low < high) {
		pivot = partition(array, low, high);
		quicksort(array, low, pivot-1);
		quicksort(array, pivot+1, high);
	}

}
int partition( int array[], int low, int high ) {
	int pivot = array[high];
	int i = low;
	int j;
	for(j=low; j<high; j++) {
		if(array[j] <= pivot) {
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return i;
}
//end quicksort algorithm implementation area
