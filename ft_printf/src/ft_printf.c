/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:32:39 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/31 20:32:39 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*format == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*format == 'u')
				ft_putnbr_fd(va_arg(args, unsigned int), 1);
			else
				format -= 2;
			format++;
		}
		write(1, format, 1);
		format++;
		ret++;
	}
	va_end(args);
	return (ret);
}

/*
int	main(void)
{
	ft_printf("hola %s %s %d %c \n", "mundo", "!", 12, '.');
	return (0);
}
*/