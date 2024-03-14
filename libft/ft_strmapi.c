/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:39:18 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/14 18:39:18 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*ret;

	len = ft_strlen(s) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	i = 0;
	while (i != len)
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
#include <stdio.h>

char ft_toupper2(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

int main()
{
    char const *s = "Hello, World!";
    char *result = ft_strmapi(s, ft_toupper2);

    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}*/