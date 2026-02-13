#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int invalid(char *s) {
	int opened = 0;
	int closed = 0;

	for (int x = 0; s[x]; x++) {
		if (s[x] == '(')
			opened++;
		else if (s[x] == ')') {
			if (opened > 0)
				opened--;
			else
				closed++;
		}
	}

	return (opened + closed);
}

void solve(char *s, int must_fix, int fixed, int pos) {
	if (must_fix == fixed && !invalid(s)) {
		puts(s);
		return ;
	}

	char c;
	for (int x = pos; s[x]; x++) {
		if (s[x] == '(' || s[x] == ')') {
			c = s[x];
			s[x] = ' ';
			solve(s, must_fix, fixed + 1, x + 1);
			s[x] = c;
		}
	}
}

int main(int ac, char **av) {
	int must_fix;
	
	(void)ac;
	must_fix = invalid(av[1]);
	solve(av[1], must_fix, 0, 0);
}

