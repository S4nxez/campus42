/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:54:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/18 16:54:55 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	total_size;
	int		i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	total_size = len_dst + len_src;
	if (total_size >= dstsize)
		return (total_size);
	i = len_dst;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (total_size);
}

/*
#include <stdio.h>

int main()
{
	char dest[50] = "Hello, ";
	char *src = "World!";

	size_t dest_size = 50;
	size_t new_len = ft_strlcat(dest, src, dest_size);

	printf("New string: %s\n", dest);
	printf("New length: %zu\n", new_len);

	return 0;
}*/