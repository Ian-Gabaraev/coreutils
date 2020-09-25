/* This program counts characters, words and lines */

#include <stdio.h>

int main() {

	#define IN 1
	#define OUT 0

	int characters;
	int lines;
	int words;
	int state;
	int c;

	state = OUT;

	characters = lines = words = 0;

	while ((c = getchar()) != 65) {

		++characters;

		if (c == '\n') {
			++lines;
		}

		if (c == '\n' || c == '\t' || c == ' ') {
			state = OUT;
		}

		else if(state == OUT) {
			state = IN;
			++words;
		}
	}

	for (int counter = 0; counter < 20; counter++) {
		printf("*");
	}
	printf("\n");

	printf("Chars\tLines\tWords\n");
	printf("\n");
	printf("%d\t%d\t%d\n", characters, lines, words);

}
