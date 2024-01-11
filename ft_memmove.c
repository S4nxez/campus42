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

void	*memmove(void *dst, const void *src, size_t len)
{
	char	*dst_bytes;
	char	*src_bytes;

	src_bytes = src;
	dst_bytes = dst;
	while (len--)
	{
		dst_bytes = src_bytes;
	}
	return (dst);
}