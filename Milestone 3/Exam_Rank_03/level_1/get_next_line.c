#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

char *ft_strdup() { //TODO
}

char *get_next_line(int fd) {
	char line[100000];
	static char buffer[SIZE];
	char c;
	static int i = 0;
	static int r = 0;
	int y = 0;

	while(1) {

		if (i >= r) {
			r = read(fd,&buffer,SIZE);
			i = 0;
			if (r <= 0)
				break;
		}
		line[y++] = buffer[i++];
		if (line[y - 1] == '\n') 
			break;
	}
	line[y] = '\0';
	return (strdup(line)); //TODO change strdup to custom ft_strdup
}

int main() {
	char *a = get_next_line(1);
	printf("%s", a);
}
