/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:04:49 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/12 17:04:49 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;
	int		positive;

	positive = 1;
	len = ft_int_len(n);
	if (n < 0)
	{
		n *= -1;
		positive = 0;
	}
	ret = (char *)malloc(sizeof(char) * len);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[len - 1] = '0' + (n % 10);
		len--;
		n /= 10;
	}
	if (!positive)
		ret[len] = '-';
	return (ret);
}

/*
int main(){
	printf("%s \n",ft_itoa(-3720));
}*/