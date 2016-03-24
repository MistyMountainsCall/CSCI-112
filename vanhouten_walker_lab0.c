/*
 *Walker VanHouten
 *Lab 0, CSCI 112
 *1/18/2016
*/

#include <stdio.h>

int main(void){
	double cel, far; //var declaration
	char input;
	for(;;){ //run this in a loop until the user enters 3
		 //request what conversion the user wants to make
		printf("Enter 1 to convert Celcius to Fahrenheit or\nEnter 2 to to convert Fahrenheit to Celcius or\nEnter 3 to quit >>>");
		fgets(input, 1, stdin);
		printf("%c", input);
		//choose branch based on user input
		switch(input){
		case 1:
			printf("Enter a temperature in degrees Celsius>>>");	//request input temp
			scanf("%lf",&cel);
			far = cel*9/5;						//do conversion
			far += 32;			
			printf("The temperature in Fahrenheit is %f\n\n", far);	//tell conversion
			break;
		case 2:
			printf("Enter a temperature in degrees Fahrenheit>>>");	//same stuff as the first branch
			scanf("%lf",&far);
			far -= 32;						//do conversion
			cel = far*5/9;
			printf("The temperature in Celsius is %f\n\n", cel);
			break;
		case 3:
			return 0; 						//exit program
		default:
			printf("Error:invalid input (you silly goose!)\n\n"); 	//tell the user that was a BAD
			input = 4;
			break;
		}
	}
}
