/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:32:20 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/11 17:44:20 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest_bytes;
	const char	*aux_ptr;

	dest_bytes = (char *)dst;
	aux_ptr = (const char *)src;
	while (len--)
	{
		dest_bytes = aux_ptr;
		aux_ptr++;
		dest_bytes++;
	}
	return (dst);
}
int main()
{
	char source[] = "Hello, World!";
	char destination[5];
	char *src_ptr = source;
	char *dst_ptr = destination;

	// Using the standard library memmove for comparison
	memmove(dst_ptr, src_ptr, 5);
	printf("Standard memmove: %s\n", destination);

	char source2[] = "Hello, World!";
	char destination2[5];
	char *src_ptr2 = source2;
	char *dst_ptr2 = destination2;
	// Using custom memmove implementation
	ft_memmove(dst_ptr2, src_ptr2, 5);
	printf("Custom memmove: %s\n", destination2);

	return (0);
}