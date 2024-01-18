/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:34:50 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/18 17:34:50 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

/*
int	main(void)
{
	char	a[] = "hola que tal";
	char	*a_ptr = a;

	printf ("antes..: %s\n",a_ptr);
	printf ("despues: %s\n",ft_strchr(a_ptr, '\0'));
}*/