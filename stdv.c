#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/*
 * http://www.reddit.com/r/dailyprogrammer/comments/35l5eo/20150511_challenge_214_easy_calculating_the/
 */

void main(int argc, char** argv) {
  if (argc != 2) return;
  
  long pop[255];
  char* end;
  double mean,stdv = 0;
  int size = 0;
  
  for (long i = strtol(argv[1], &end, 10);
       argv[1] != end;
       i = strtol(argv[1], &end, 10)) {
	argv[1] = end;
	pop[size] = i;
	size++;
  }
  for (int i = 0;i < size;i++) {
	mean += pop[i];
  }
  mean = mean / size;
  
  for (int i = 0;i < size;i++) {
	stdv += pow(pop[i] - mean, 2);
  }
  printf("%f", sqrt(stdv / size));
}
