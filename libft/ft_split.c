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

void	fill_matrix(int j, char const *s, char c, char **ret)
{
	int	k;

	k = 0;
	while (s[k] != '\0' && s[k] != c)
	{
		ret[j][k] = s[k];
		k++;
	}
	ret[j][k] = '\0';
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
			k = i;
			while (s[k] != '\0' && s[k] != c)
				k++;
			ret[j] = (char *)malloc(sizeof(char) * (k - i + 1));
			if (ret[j] == NULL)
				return ;
			fill_matrix(j, &s[i], c, ret);
			i = k;
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

/*int	main(void)
{
	const char	strin[] = " hola   que tal";
	const char	c = ' ';
	char		**spliteado = ft_split(strin , c);
	int			num = count_words(strin, c);
	int			j = 0;

	printf("\nnumero : %d\n", num);
	while (j < num)
	{
		printf("\n%s", spliteado[j]);
		j++;
	}
}
*/