/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:44:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/15 19:44:55 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	int i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize <= (srcsize + 1))
	{
		while (i < srcsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (i < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}

	return (dstsize);
}

int	main(){ // dale testeo
	char src[] = "hola, mundo!";
	char dst[] = "Que + mundo!";

	char *src_ptr = src;
	char *dst_ptr = dst;

	printf("%s\n", dst);
	ft_strlcpy(dst_ptr, src_ptr, 13);
	printf("%s\n", dst);
}