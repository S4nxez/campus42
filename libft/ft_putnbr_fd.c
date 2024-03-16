/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:45:38 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/14 20:45:38 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nlong;
	char	*printable;
	int		i;

	nlong = n;
	printable = (char *)malloc(sizeof(char) * ft_int_len(nlong));
	if (printable == NULL)
		return ;
	printable = ft_itoa(n);
	i = 0;
	while (printable[i])
	{
		write(fd, &printable[i], 1);
		i++;
	}
	free(printable);
}

/*
int	main(void)
{
	ft_putnbr_fd(-9832, 1);
}
*/