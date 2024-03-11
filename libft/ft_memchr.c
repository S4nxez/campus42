/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:54:28 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/21 10:38:31 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_aux;
	unsigned char	c_aux;
	size_t			i;

	s_aux = (unsigned char *)s;
	c_aux = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_aux[i] == c_aux)
			return ((void *)&s_aux[i]);
		i++;
	}
	return (NULL);
}
/*
En este caso, es correcto utilizar un puntero auxiliar s_aux para trabajar
con los bytes de la región de memoria y realizar la comparación. Al devolver
(void *)&s_aux[i], estás devolviendo un puntero a la ubicación exacta del
byte que coincidió en la memoria original. El casting a (void *) se utiliza
para que la función pueda manejar cualquier tipo de datos y no está limitada
a un tipo específico.
En resumen, la función ft_memchr está diseñada para ser genérica y trabajar
con cualquier tipo de datos, y la implementación que proporcionaste cumple
con ese objetivo.
*/