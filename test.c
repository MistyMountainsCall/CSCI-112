#include <stdio.h>
#include <stdlib.h>


int main() {
	char derp[] = "1";
	if(isdigit(derp)) {
		printf("works as supposed\n");
	} else {
		printf("nope\n");
	}
	
	return 0;
}


node* build_stack(char* in_string) {
	char* in_array = strtok(in_string, " ");
	int i = 0, num;
	node* top, store;
	while(in_array != NULL) {
		store = malloc(sizeof(node));		//allocate mem for new node
		switch(in_array[i]) {
			case "+":
				store->op = ADD;		//tell new node its value
				break;
			case "-":
				store->op = SUB;		//tell new node its value
				break;
			case "*":
				store->op = MUL;		//tell new node its value
				break;
			case "/":
				store->op = DIV;		//tell new node its value
				break;
			case "%":
				store->op = MOD;		//tell new node its value
				break;
			case "sqrt":
				store->op = SQRT;		//tell new node its value
				break;
			case "pow":
				store->op = POW;		//tell new node its value
				break;
			default:
				num = atoi(in_array[i];	//get number value
				if(num)) {
					store->data = num;
				} else {
					if(in_array[i][0] == '0') {	//deal with zeros
						store->data = 0;
						break;
					}
					printf("Error: Invalid input syntax at element %d\n", i);
					dealocate_stack(top);	//free up memory
					return NULL;	//return null pointer so that nothing is executed
				}
		}
		store->under = top;				//set next node in the new node
		top = store;					//set top of stack to new node
	}
}
