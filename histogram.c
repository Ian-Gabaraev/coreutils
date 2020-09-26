/*This program draws a frequency histogram of characters appearing in a line*/

#include <stdio.h>

#define MAX_STR_LEN 4096

struct String
{
	int len;
	char contents[MAX_STR_LEN];
};


int
contains(char c, char string[], int len) {

	if (len == 0) {
		return 0;
	}

	for (int i = 0; i<len; i++) {
		if(c == string[i]) {
			return 1;
		}
	}

	return 0;
}

struct String
get_string()
{
	struct String str;
	int c;
	str.len = 0;

	for (int i=0; i<MAX_STR_LEN-1 && (c=getchar()) != '\n'; i++) {
		++str.len;
		str.contents[i] = c;
	}

	return str;
}


int
draw(struct String str)
{
	struct String seen;

	for (int i=0; i<str.len; i++) {
		for (int j=i+1; j<str.len; j++) {
			if (str.contents[i] == str.contents[j] && contains(str.contents[i], seen.contents, seen.len) == 0) {
				printf("*");
			}
		}
		if (contains(str.contents[i], seen.contents, seen.len) == 0) {
			printf("* --- %c\n", str.contents[i]);
		}
		seen.contents[i] = str.contents[i];
		++seen.len;
	}

	return 0;
}


int
main()
{
	struct String string = get_string();
	draw(string);

	return 0;
}