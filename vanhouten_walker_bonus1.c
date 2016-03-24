#include <stdio.h>

#define MAX_SIZE 25
#define MAX_WRONG_GUESSES 6

char guessed[26];
char word[], wordOut[];
int used = 0;
int length;

void printHangman(int stateNum) {	//numbers 1 through 7 accepted
	switch(stateNum) {
		case 0:
			printf("___\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("-----\n");
			break;
		case 1:
			printf("___\n");
			printf("| o\n");
			printf("|\n");
			printf("|\n");
			printf("-----\n");
			break;
		case 2:
			printf("___\n");
			printf("|\\o\n");
			printf("|\n");
			printf("|\n");
			printf("-----\n");
			break;
		case 3:
			printf("___\n");
			printf("|\\o/\n");
			printf("| |\n");
			printf("|\n");
			printf("-----\n");
			break;
		case 4:
			printf("___\n");
			printf("|\\o/\n");
			printf("| |\n");
			printf("|\n");
			printf("-----\n");
			break;
		case 5:
			printf("___\n");
			printf("|\\o/\n");
			printf("| |\n");
			printf("|/\n");
			printf("-----\n");
			break;
		default:
			printf("Not dead yet!\n");
		case 6:
			printf("___\n");
			printf("|\\o/\n");
			printf("| |\n");
			printf("|/ \\\n");
			printf("-----\n");
			break;
	}
}

int checkGuess(char guess) {
	used++;
	int i;	
	for(i=0; i < used;i++) {
		if(guess==guessed[i]) {
			return 0;
		}
	}
	guessed[used] = guess;
	int n = 0;
	int done = 1;
	for(i=0; i < length;i++) {
		if(guess==word[i]) {
			wordOut[i] = word[i];	//display part of word allready guessed
			n++;
		}
		if(wordOut[i]=='*') {
			done = 0;
		}
	}
	if(done) {
		return 2;
	} else {
		return -1 * n;
	}
}

void setWord(char *w) {
	int i;
	for(i=0; i < length; i++) {
		word[i] = *(w + i);	
	}
}

int main(int argc, char *argv[]) {
	length = sizeof(argv[1])/sizeof(char);
	if(length>25) {	//checks if input string is too long and exits if so
		printf("ERROR: Input argument is too long\n");
		return 0;
	}
	int i;
	for(i=0; i < length; i++) {
		if(word[i]=='*') {
			printf("That is a bad word. Don't say swears. (astericks break my program)\n");
			return 1;
		}
		wordOut[i] = '*';	
	}
	setWord(argv[1]);
	
	i = MAX_WRONG_GUESSES;
	char g;
	int val;
	do {
		printf("Guess a letter (6 attempts left) > ");
		scanf("%c", &g);		//get user guess
		val = checkGuess(g);
		switch(val) {
			case 1:		//letter repeated
				printf("You already guessed %c\n", g);
				i--;
				break;
			default:		//correct guess
				if(val<-1) {
					printf("There is %d %c\n", -1*val, g);
				} else {
					printf("There is 1 %c\n", g);
				}
				break;
			case 0:		//wrong guess
				printf("There are no %c's\n", g);
				i--;
				break;
			case 2:		//game over win
				printf("Game Over\n%d total guesses made.\nYou won!\n", used);		//game over statement
				return 0;	//exit game
		}
		printHangman((MAX_WRONG_GUESSES-i));
	}while(i>0);
	//game over loss
	printf("Game Over\n%d total guesses made.\nOut of guesses.\nYou lost\n", used);		//game over statement
	return 0;
}



