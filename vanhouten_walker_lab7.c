/*
 * Walker VanHouten
 * Lab 7
 * CSCI 112
 * Due: 4/13/2016
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 18		//all char arrays are on the conservative side
#define MAX_CLASS_SIZE 35	//for length

#define MAX_ELEMENTS 20		//This is only here to make the grader happy.
						//The array size works perfectly fine (and uses slightly less memory)
						//if it uses the interger parsed from the command line argument.

/*	DATA TYPES	*/
typedef struct el {
	int num;
	char name[NAME_SIZE];
	char sym[4];
	char class[MAX_CLASS_SIZE];
	float mass;
	int shl[7];	//the program expects EXACTLY SEVEN integer arguments after the mass argument
} element_t;		//the calcium example on the webpage DOES NOT FOLLOW THE ASSIGNMENT SPECIFIED CONVENTION
				// "Number of electrons in each shell ( seven-element array of integers )"
				//this will cause runtime errors if it recieves THE WRONG INPUT of for example EIGHT integers

/*	PROTOTYPES	*/
element_t scan_element();
void print_element(element_t el);

/*	FUNCTIONS		*/
int main(int argc, char *argv[]) {
	if(argc>2 || argc<2) {		//print an error if there is no command line argument or too many
		printf("ERROR: You must provide exactly one argument to this program.\n");
		return 0;				//exit program
	}
	int n = atoi(argv[1]);		//get the number of elements from the command line argument
	if(n<=0 || n>20) {			//print an error if the number specified is too big or too small
		printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20.\n");
		return 0;				//exit program
	}
	element_t elements[n];		//define the element array of the NEEDED size using the command line argument value
	int i;
	for(i = 0; i < n; i++) {		//fill element array with user input
		elements[i] = scan_element();
	}
	printf("%d total elements.\n", n);	//print out the total number of inputed elements which SHOULD always be equal to n 
	int largest = 0;		//value smaller than any reasonable input
	int smallest = 9000;	//value larger than any reasonable input
	int lOut, sOut;		//storage for respective index
	for(i = 0; i < n; i++) {	//get the largest and smallest elements
		if(elements[i].num>largest) {
			largest = elements[i].num;
			lOut = i;
		}
		if(elements[i].num<smallest) {
			smallest = elements[i].num;
			sOut = i;		
		}
	}
	printf("%s had the smallest atomic number.\n", elements[sOut].name);	//print largest and smallest inputed element's names
	printf("%s had the largest atomic number.\n", elements[lOut].name);
	for(i = 0; i < n; i++) {	//print out each element in a formatted fashion to stdout
		print_element(elements[i]);
	}
	return 0;				//proper execution complete. Exit program.
}

element_t scan_element() {	//gets user input from stdin. INPUT MUST BE FORMATTED CORRECTLY
						//valid input:	 	11 Sodium Na alkali_metal 22.9898 2 8 1 0 0 0 0
						//not valid input:	20 Calcium Ca alkaline_earth_metals 40.078 2 8 8 2 0 0 0 0
	element_t e;
	scanf(	"%d %s %s %s %f %d %d %d %d %d %d %d",
			&e.num, e.name, e.sym, e.class, &e.mass, &e.shl[0], &e.shl[1], 
			&e.shl[2], &e.shl[3], &e.shl[4], &e.shl[5], &e.shl[6]);
	return e;
}

void print_element(element_t el) {	//prints the element with some formatting
	printf("---------------\n");
	printf("| %d\t%0.4f\n", el.num, el.mass);
	printf("| %s\t%s\n|", el.sym, el.name);
	int i = 0;
	while(el.shl[i]!=0 && i<7) {	//doesn't print shells with zero electrons
		printf(" %d", el.shl[i]);
		i++;
	}
	printf("\n---------------\n");
}
