/*
 * Walker VanHouten
 * Program 3
 * CSCI 112
 * Due: 4/30/2016
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARG_LENGTH	6

/*	DATA TYPES	***********************************************************/

typedef struct node {
	struct node* under;		//points to node under this node
	double data;			//holds the data of the node
} node;

/*	FUNCTION PROTOTYPES		*************************************************/

node* 	get_data(node* top, char* t);
node* 	execute_stack(node* top, char* op);
node* 	pop(node* top);
node* 	push(node* top);
void 	print(node* top);

int main() {
	char input[MAX_INPUT_LENGTH];		//storage for line from user
	fgets(input, MAX_INPUT_LENGTH, stdin);	//get line from user
	
	node* top = NULL;				//create bottom of stack
	char* nxt_arg;
	nxt_arg = strtok(input, " ");
	do {
		if(nxt_arg == NULL) break;	//exit loop with sucsess upon no more user args left
		top = get_data(top, nxt_arg);	//decide what to do with the argument
		print(top);				//print out current stack state
		nxt_arg = strtok(NULL, " ");	//next argument
	} while(top != NULL);			//exit loop here if an error has occurred
	if(top != NULL) {				//don't print result on error exit
		printf("Result = %lf\n", top->data);
	}
	return 0;
}

node* push(node* top) {		//add empty node to the top of the stack
	node* new_top = malloc(sizeof(node));	//allocate memory
	new_top->under = top;				//put old top of stack under new top
	return new_top;					//return new top
}

void print(node* top) {		//prints off data values of each node on the stack
	node* nxt = top;		//until it reaches the bottom which is signified by a null pointer
	while(nxt != NULL) {	//iterate through stack and print values
		printf("%lf\n", nxt->data);
		nxt = nxt->under;
	}
	printf("\n");
}

node* get_data(node* top, char* t) {
	if(atoi(t) || t[0] == '0' || t[0] == '.') {	//detect if argument is data
		top = push(top);
		top->data = atof(t);	//parse out data and put it on top of the stack
		return top;
	} else {	//execute if argument is not data
		return execute_stack(top, t);	//execute operation and return new top of stack
	}
}

node* execute_stack(node* top, char* op) {
	switch(op[0]) {	//find the correct operation to perform
	/*
	 * General format of each operation is:
	 * detect if possible given stack values
	 * if so execute and push result onto stack
	 * otherwise print an error and return a null pointer to cause the program
	 * to exit early without printing out anything else.
	 */
		case '+':
			if(top != NULL && top->under != NULL) {
				double store = 0;
				while(top != NULL) {	//not limited to two elements to be added
					store += top->data;
					top = pop(top);
				}
				top = push(top);
				top->data = store;
				printf("add\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		case '-':
			if(top != NULL && top->under != NULL) {
				double store = top->data;
				top = pop(top);
				while(top != NULL) {
					store -= top->data;
					top = pop(top);
				}
				top = push(top);
				top->data = -1 * store;
				printf("subtract\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		case '*':
			if(top != NULL && top->under != NULL) {
				double store = top->data;
				top = pop(top);
				while(top != NULL) {
					store *= top->data;
					top = pop(top);
				}
				top = push(top);
				top->data = store;
				printf("multiply\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		case '/':
			if(top != NULL && top->under != NULL) {
				double str = top->under->data / top->data;
				top = pop(top);
				top->data = str;
				printf("divide\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		case '%':
			if(top != NULL && top->under != NULL) {
				if(top != NULL && top->under != NULL) {
					top->data = fmod(top->under->data, top->data);
				}
				printf("modulus\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		case 's':
		case 'S':	//in case of uppercase for some reason
			if(top != NULL) {
				top->data = sqrt(top->data);
				printf("square root\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		case 'p':
		case 'P':	//in case of uppercase for some reason
			if(top != NULL && top->under != NULL) {
				double str = pow(top->data, top->under->data);
				top = pop(top);
				top->data = str;
				printf("raise to power\n");
				return top;
			} else {
				printf("ERROR: The user has not provided enough input values\n");
				return NULL;
			}
		default:
			printf("ERROR: Invalid input syntax\n");
			return NULL;
	}
}

node* pop(node* top) {		//remove top element of stack
	node* next_top = top->under;
	free(top);
	return next_top;
}
