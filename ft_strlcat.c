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
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	total_size;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	total_size = len_dst + len_src;
	while (dstsize >= total_size - 1)
	{
		ft_memcpy /////entiendo los solucionarios pero no lo se hacer por mi cuenta porque creo que no acabo de entender el enunciado

	}
	return ();
}