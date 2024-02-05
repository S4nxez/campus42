/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:04:08 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/01 20:04:08 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	quit_init(char s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	len;

	i=0;
	len = ft_strlen(s1);
	while (quit_init(s1[i], set))
		i++;
	const char *ret = &s1[i];
	return ((char *)ret);
}

int	quit_init(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

//#include <shlwapi.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("FT_Strtrim: %s", ft_strtrim("ababbabbb hola baba", "ab"));
	//	printf("Strtrim:    %s", strtrim(""));
	return (0);
}
