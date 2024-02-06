/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:43:44 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/06 10:43:44 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	count_words(char const *s, char c)
{
	int	i;
	int	words_num;

	i = 0;
	words_num = 0;
	printf("\nCount words processing: ");
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			words_num++;
			printf("#");
		}
		else
			i++;
	}
	return (words_num);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ret;
	int		i;
	int		j;
	int		k;

	words = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] != '\0' && s[i] == c)
			{
				k++;
				i++;
			}
			ret[j] = (char *)malloc(sizeof(char) * (k + 1));
			if (ret[j] == NULL)
				return (NULL);
			i -= k;
			k = 0;
			while (s[i] != '\0' && s[i] != c)
			{
				ret[j][k] = s[i];
				i++;
				k++;
			}
			ret[j][k] = '\0';
			j++;
		}else{
			i++;
		}
	}
	return (ret);
}

int	main()
{
	char	**spliteado = ft_split("hola que tal", ' ');
	int		num = count_words("hola que tal", ' ');
	int		j = 0;

	printf("\nnumero : %d\n", num);
	while (j < num)
	{
		printf("\n%s", spliteado[j]);
		j++;
	}
}
