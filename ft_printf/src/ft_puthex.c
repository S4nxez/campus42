/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:24:13 by dansanc3          #+#    #+#             */
/*   Updated: 2024/05/16 19:11:11 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	const char	*converter;

	if (format == 'X')
		converter = "0123456789ABCDEF";
	else
		converter = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex(n / 16, format);
		n %= 16;
	}
	write(1, &(converter[n]), 1);
	return (1);
}
