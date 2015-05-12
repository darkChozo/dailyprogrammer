#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * http://www.reddit.com/r/dailyprogrammer/comments/34rxkc/20150504_challenge_213_easy_pronouncing_hex/
 */

int charToHex(char kar);

int main(int argc, char** argv) {
  const char* ONES[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "a", "bee", "cee", "dee", "e", "eff"};	
  const char* TENS[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "atta", "bibbity", "city", "dickety", "ebbity", "fleventy"};
  const char* TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "ahteen", "beeteen", "ceeteen", "deeteen", "eeteen", "effteen"};
  const char* BITEY = " bitey ";

  char* itr = argv[1];
  int size = strlen(argv[1]), isteen, bitey = 0;
  char output[255]; //too lazy for memory management
  char* outitr = output;
  
  if (itr[0] == '0' && tolower(itr[1]) == 'x') {
    itr += 2;
	size -= 2;
  }
  
  while (size > 0) {
	  if (size % 2) { // low nibble
		if (isteen) {
			strcpy(outitr, TEENS[charToHex(*itr)]);
			outitr += strlen(TEENS[charToHex(*itr)]);
			isteen = 0;
		} else {
		    strcpy(outitr, ONES[charToHex(*itr)]);
			outitr += strlen(ONES[charToHex(*itr)]);
		}
		if (size > 1) {
			strcpy(outitr, BITEY);
			outitr += strlen(BITEY);
		}
	  } else { //high nibble
	    if (charToHex(*itr) != 1) {
		    strcpy(outitr, TENS[charToHex(*itr)]);
			outitr += strlen(TENS[charToHex(*itr)]);
		} else {
			isteen = 1;
		}
		if (!isteen && *(itr + 1) != '0') {
			*outitr = '-';
			outitr++;
		}
	  }
	  size--;
	  itr++;
  }
  printf("%s", output);
}

int charToHex(char kar) {
	int output;
	if (!sscanf(&kar, "%x", &output)) {
	  fprintf(stderr, "oh no, tried to convert a nonhex char");
	  exit(EXIT_FAILURE);
    }
	return output;
}