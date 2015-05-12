#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
 * http://www.reddit.com/r/dailyprogrammer/comments/3206mk/weekly_22_machine_learning/
 *
 * not a real genetic algorithm but it looks entertaining
 */

int fitness(char* target, char* candidate);
void mutate(char* parent, char* child, int mutationChance);

main(int argc, char *argv[]) {
	if (argc != 2) { return; }
	char* input = argv[1];
	int i,bestChild,generation = 0,bestfitness = INT_MAX;

	srand(time(NULL));
	
	const int mutationChance = 20; // % chance of any given mutation happening

	char output[255], children[5][255];
	output[0] = '\0';

	mutate(output, children[0], mutationChance);
	
	while(fitness(input, output) != 0) {
		bestChild = -1;
		for (i = 0;i<5;i++) {
			mutate(output, children[i], mutationChance);
			if (fitness(input, children[i]) < bestfitness) {
				bestfitness = fitness(input,children[i]);
				bestChild = i;
			}
		}
		if (bestChild != -1) {
			strcpy(output, children[bestChild]);
		}
		generation++;
		if (bestChild != -1) {
			printf("Generation #%d: %s Fitness: %d\n", generation, output, bestfitness);
		}
	}

}


int fitness(char* target, char* candidate) {
	int i,score = 0;
	score += abs(strlen(target) - strlen(candidate)) * 200;
	for (i=0;candidate[i] != '\0' && target[i] != '\0'; i++) {
		score += abs(candidate[i] - target[i]);
	}
	return score;
}

void mutate(char* parent, char* child, int mutationChance) {
	int i = 0;
	for (i = 0; parent[i] != '\0'; i++) {
		if (shouldMutate(mutationChance)) {
			if (rand() % 2) {
				child[i]++;
			} else {
				child[i]--;
			}
		} else {
			child[i] = parent[i];
		}
	}
	child[i] = '\0';

	if (shouldMutate(mutationChance)) {
		if (i != 0 && rand() % 2) {
			child[i-1] = '\0';
		} else {
			child[i] = rand() % 95 + 32;
			child[i + 1] = '\0';
		}
	}
}

int shouldMutate(mutationChance) {
	if (rand() % 100 > mutationChance) return 1;
	return 0;
}
