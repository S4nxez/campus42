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
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			words_num++;
		}
		else
			i++;
	}
	return (words_num);
}

void	split_words(char const *s, char c, char **ret)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
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
				return ;
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
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ret;

	words = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (ret == NULL)
		return (NULL);
	split_words(s, c, ret);
	return (ret);
}

int	main(void)
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
