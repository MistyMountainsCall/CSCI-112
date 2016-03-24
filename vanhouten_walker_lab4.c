/*
 * Walker VanHouten
 * InLab4
 * CSCI 112
 * Due: 29 February 2016
 */

#include <stdio.h>
#include <math.h>

    // List of all function prototypes

    // displays user menu, reads input, and validates input
    int user_menu();

    // Equation functions that are pass by reference
    void equation1(float *);            // calculate motion equation 1
    void equation2(float *);            // calculate motion equation 2
    void equation3(float *);            // calculate motion equation 3
    void equation4(float *);            // calculate motion equation 4

    // User input functions return a value from user
    float get_position_initial(void);   // Prompts user for x0
    float get_position_final(void);     // Prompts user for xf
    float get_velocity_initial(void);   // Prompts user for v0
    float get_velocity_final(void);     // Prompts user for vf
    float get_acceleration(void);       // Prompts user for a
    float get_time(void);               // Prompts user for t

int main (void) {
        // Print welcome message
        printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

        // Variable for the user choice menu.
        int user_choice;

	do
	{
		user_choice = user_menu();  // print menu, validate choice is between 1 and 5

		// You will pass the address of this variable to your equation functions. 
		float result;               // Variable to hold calculated result

		// Handle menu choice selected by user
		switch( user_choice ) {
		case 1:
			equation1(&result);
			break;
		case 2:
			equation2(&result);
			break;
		case 3:
			equation3(&result);
			break;
		case 4:
			equation4(&result);
			break;
		case 5:
			// exit program if user selected QUIT
			printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
			return 0;
			break;
		}

		// Print out the calculated result with four digits after the decimal place
		printf("Your result is %.4f.\n\n", result);


        } while ( user_choice != 5 );

	return 0; // exit with no error
}

int user_menu() {
	int in;
	for(;;) {
		printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
		scanf("%d", &in);
		if(in>=1&&in<=5) {
			return in;
		} else {
			printf("Invalid Option. Please try again.\n");
		}
	}
}


float in, out;	//create output storage variable
//equation 1-4 respectively calculates kinimatic equations 1-4
void equation1(float *result) {
	float a, b, c;	//input storage
	a = get_velocity_initial();	//get inputs
	b = get_acceleration();
	c = get_time();
	out = a + (b*c);	//calculation
	*result = out;	//the passed pointer result point to out which stores the calculated result
}
void equation2(float *result) {
	float a, b, c, d;	//input storage
	a = get_position_initial();
	b = get_velocity_initial();
	c = get_time();
	d = get_acceleration();
	out = a + (b*c) + (c*c*d/2);
	*result = out;	//the passed pointer result point to out which stores the calculated result
}
void equation3(float *result) {
	float a, b, c, d;	//input storage
	a = get_velocity_initial();
	b = get_acceleration();
	c = get_position_final();
	d = get_position_initial();
	out = sqrt((a*a) + (2*b*(c-d)));
	*result = out;	//the passed pointer result point to out which stores the calculated result
}
void equation4(float *result) {
	float a, b, c, d;	//input storage
	a = get_position_initial();
	b = get_velocity_final();
	c = get_velocity_initial();
	d = get_time();
	out = a + (0.5*(b+c)*d);
	*result = out;	//the passed pointer result point to out which stores the calculated result
}
//get input functions request user input
float get_position_initial() {
	printf("\tEnter initial position > ");
	scanf("%f", &in);	//grabs next float entered into command line and stores it in in
	return in;
}
float get_position_final() {
	printf("\tEnter final position > ");
	scanf("%f", &in);
	return in;
}
float get_velocity_initial() {
	printf("\tEnter initial velocity > ");
	scanf("%f", &in);
	return in;
}
float get_velocity_final() {
	printf("\tEnter final velocity > ");
	scanf("%f", &in);
	return in;
}
float get_acceleration() {
	printf("\tEnter acceleration > ");
	scanf("%f", &in);
	return in;
}
float get_time() {
	printf("\tEnter time > ");
	scanf("%f", &in);
	return in;
}
