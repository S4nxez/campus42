#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b) {
	char aux;
	aux = *b;
	*b = *a;
	*a = aux;
}

void sort(char *s){ //TODO repasar
	for (int i = 0; s[i] != '\0'; i++) {
		for (int o = i + 1; s[o] != '\0'; o++) {
			if (s[i] > s[o])
				swap(&s[i], &s[o]);
		}
	}
}

void print_answer(char *s, int len) {
	write(1, s, len);
	write(1, "\n", 1);
}

void solve(char *s,int level,int len){
	if(level == len) {
		print_answer(s, len);
		return ;
	}
	for (int i = level; i < len; i++) {
		swap(&s[i], &s[level]);
		solve(s, level + 1, len);
		swap(&s[i], &s[level]);	
	}
}

int main(int ac, char **av) {
	(void)ac;
	char *s = strdup(av[1]);
	int n = strlen(av[1]);
	sort(s);
	solve(s, 0, n);
	free(s);
}
