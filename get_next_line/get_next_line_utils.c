/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:43:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/01 18:28:29 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_copy;

	c_copy = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_copy)
			return ((char *)&s[i]);
		i++;
	}
	if (c_copy == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *a)
{
	size_t	ret;

	ret = 0;
	while (a[ret] != '\0')
		ret++;
	return (ret);
}

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	const unsigned char	*src_bytes;
	unsigned char		*dst_bytes;
	size_t				i;

	dst_bytes = dst;
	src_bytes = src;
	if (!dst_bytes && !src_bytes)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_bytes[i] = src_bytes[i];
		i++;
	}
	return (dst);
}
