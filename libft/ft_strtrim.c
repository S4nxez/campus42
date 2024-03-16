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

int	quit(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ini;
	int		fin;
	int		u;
	char	*ret;

	ini = 0;
	while (quit(s1[ini], set))
		ini++;
	fin = ft_strlen(s1) - 1;
	while (quit(s1[fin], set))
		fin--;
	fin++;
	printf("fin: %d\nini: %d\n\n", fin, ini);
	ret = (char *)malloc(sizeof(char *) * (fin - ini + 1));
	if (!ret)
		return (NULL);
	u = 0;
	while (ini < fin)
	{
		ret[u] = s1[ini];
		ini++;
		u++;
	}
	ret[u] = '\0';
	return (ret);
}

//#include <shlwapi.h>

/*int	main(void)
{
	printf("FT_Strtrim:%s", ft_strtrim("ababbabbbholabaababba", "ab"));
	//	printf("Strtrim:    %s", strtrim(""));
	return (0);
}*/
