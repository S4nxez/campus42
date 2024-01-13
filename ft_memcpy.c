/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:08:27 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/10 20:08:27 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *restrict	dest, const void *restrict	src, size_t	n)
{
	const unsigned char	*src_bytes;
	unsigned char		*dest_bytes;
	int					i;

	dest_bytes = dest;
	src_bytes = src;
	i = 0;
	while (i < n)
	{
		dest_bytes[i] = src_bytes[i];
		i++;
	}
	return (dest);
	//esto esta mal hay que arreglarlo
}
