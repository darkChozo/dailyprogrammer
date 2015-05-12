#include <stdio.h>
#include <ctype.h>

/*
 * http://www.reddit.com/r/dailyprogrammer/comments/351b0o/20150506_challenge_213_intermediate_the_lazy/
 *
 * obviously not complete (or really started), might come back to it someday."
 */

main(int argc, char *argv[]) {
	char keyboard[4][10] = {"qwertyuiop",
							"asdfghjkl ",
							"^zxcvbnm ^",
							"   #####  "};

	if (argc != 2) { return; }

	char* input = argv[1];
	int i;
	for (i = 0; input[i] != '\0'; i++) {
		
	}
}
