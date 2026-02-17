#include <unistd.h>

int ft_strlen(char *s) {
	int ret = 0;

	while (s[ret])
		ret++;
	return (ret);
}

#include <stdio.h>
int power_of_base(int base, int exponent) {
	int ret = 1;

	while(exponent != 0) {
		ret *= base;
		exponent--;
	}
	return (ret);
}

int is_not_duplicated(int *array, int size) {
	int i = 0;
	int j;
	
	while (i < size) {
		j = i + 1;
		while (j < size) {
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void sort(char *array) {
	char aux;

	for (int i = 0; array[i]; i++) {
		for (int j = 0; array[j]; j++) {
			if (array[i] < array[j]) {
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
			}
		}
	}
}

int main(int ac, char **av) {
	(void)ac;
	int n = ft_strlen(av[1]);
	sort(av[1]);
	int i = 0;
	int array[n];
	while (i < power_of_base(n,n)) {
		int j = 0;
		while (j < n) {
			array[n - j - 1] = i / power_of_base(n, j) % n;
			j++;
		}
		if (is_not_duplicated(array, n)) {
			j = 0;
			while(j < n) {
				write(1, &av[1][array[j]], 1);
				j++;
			}
			write(1, "\n", 1);
		}
		i++;
	}
}
