#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * http://www.reddit.com/r/dailyprogrammer/comments/341c03/20150427_challenge_212_easy_r%C3%B6varspr%C3%A5ket/
 */

main() {
	static char* robberchars = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	static char* wordchars = " \"\'-";
	printf("Enter the phrase you'd like to translate.\n");
	char input[255];
	fgets(input, 255, stdin);
    char output[255];
	int i, j = 0;
	for (i = 0; input[i] != '\0'; i++) {
		if (strchr(robberchars, input[i])) {
			output[j] = input[i];
			output[j+1] = 'o';
			if (i == 0 || strchr(wordchars, input[i - 1])) {
				output[j+2] = tolower(input[i]);
			} else {
				output[j+2] = input[i];
			}
			j+=3;
		} else {
			output[j] = input[i];
			j++;
		}
	}
	output[j] = '\0';
	printf("%s", output);
}
