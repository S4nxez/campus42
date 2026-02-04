#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int ft_strncmp(char *s1,char *s2, int len)
{
	int count = 0;
	while (count < len && s1[count] == s2[count])
		count++;
	if (count == len)
		return 1;
	return 0;
}

int main(int ac, char **argv)
{
	char *buff = malloc(1000000);
	char *cp_av = argv[1];
	int x = 0;
	int len = strlen(argv[1]);
	char c;
	int r=read(0, &c, 1);
	(void) ac;

	while (r>0) {
		buff[x++]=c;
		r = read(0,&c,1);
	}
	buff[x] = '\0';
	x = 0;
	while (buff[x] != '\0') {
		if (ft_strncmp(&buff[x], cp_av, len)) {
			for (int y = 0; y < len; y++)
				write(1,"*",1);
			x += len;
		}
		else {
			write(1, &buff[x], 1);
			x++;
		}
	}
	free(buff);
}


