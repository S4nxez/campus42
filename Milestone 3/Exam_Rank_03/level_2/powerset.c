#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int calculate(int *set, int size) {
	int ret = 0;

	for (int i = 0; i < size; i++)
		ret += set[i];
	return (ret);
}

void print(int *set, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0)
			printf("%d", set[i]);
		else
			printf(" %d", set[i]);
	}
	printf("\n");
}

void solve(int *nums, int *subset, int size, int objective, int subsize, int level) {
	
	if (size == level) {
		if (calculate(subset, subsize) == objective)
			print(subset, subsize);
		return ;
	}

	subset[subsize] = nums[level];
	solve(nums, subset, size, objective, subsize + 1, level + 1);
	solve(nums, subset, size, objective, subsize, level + 1);
}

int main(int ac, char **av) {
	int size = ac - 2;
	int *subset = malloc(size * sizeof(int));
	int *nums = malloc(size * sizeof(int));
	int objective = atoi(av[1]);
	for (int i = 0; i < size; i++)
		nums[i] = atoi(av[i + 2]);
	solve(nums, subset, size, objective,0 ,0);
	free(subset);
	free(nums);
}

