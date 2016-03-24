/*
 * Walker VanHouten
 * InLab3
 * CSCI 112
 * Due: 22 February 2016
 */

#include <stdio.h>
#include <math.h>

#define LOOP_LIMIT 90	//degree limit
#define PI 3.14159	//defining pi
#define STEP 15	//degrees to incriment by each time

typedef enum {	//create custom data type
	Sine,	//Sine = 0, Cosine = 1, etc
	Cosine,
	Tangent,
	QUIT
} menu_t;

double getRadians(double degrees) {	//do conversion from radians to degrees
	return PI*(degrees/180);
}

void printOut(menu_t c) {	//does the correct print out for the inputed menu option
	int i;
	switch(c) {
		case Sine:					//outputs are formatted
			for(i=0;i<=LOOP_LIMIT;i+=STEP) {	//print out sine radian vals every STEP degrees until hitting the LOOP_LIMIT
				printf("\tsin(%d) = %.4lf\n",i , sin(getRadians(i)));
			}
			break;
		case Cosine:
			for(i=0;i<=LOOP_LIMIT;i+=STEP) {	//print out sine radian vals every STEP degrees until hitting the LOOP_LIMIT
				printf("\tcos(%d) = %.4lf\n",i , cos(getRadians(i)));
			}
			break;
		case Tangent:
			for(i=0;i<=LOOP_LIMIT;i+=STEP) {	//print out tangent radian vals every STEP degrees until hitting the LOOP_LIMIT
				if(i!=90) {	//deals with the undefined case of 90 degrees from tangent
					printf("\ttan(%d) = %.4lf\n",i , tan(getRadians(i)));
				} else {
					printf("\ttan(90) is UNDEFINED\n");
				}
			}
			break;
		case QUIT:	//print exit message
			printf("You chose QUIT. Thank you, come again!\n");
			break;
		default:	//tells user their input "is an invalid option." and to "Please try again."
			printf("%d is an invalid option. Please try again.\n", c);
			break;
	}
}

int main() {
	menu_t choice;
	do {	//run this loop until input is = to 3
		printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\nEnter your choice > ");	//request input
		scanf("%u", &choice);	//get input
		printOut(choice);	//perform operation requested
	} while(choice!=QUIT);
	return 0;
}
