/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:45:26 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/21 10:38:14 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;
	size_t			i;

	s1_aux = (unsigned char) *s1;
	s2_aux = (unsigned char) *s2;
	i = 0;
	while (i < n)
	{
		if (s1_aux[i] != s2_aux[i])
			return (s1_aux[i] - s2_aux[i]);
		i++;
	}
	return (0);
}

/*
Tener en cuenta lineas 20 y 21 donde está el asterisco

Estamos comparando bloques de memoria, y al tratar los punteros
como unsigned char, estamos asegurando que cada elemento que leemos
sea interpretado como un byte sin signo, es decir, un valor entre 0 y
255.

Si tratamos los punteros como punteros a int (como en la versión original
ft_memcmp), cada elemento se interpretará como un entero de mayor tamaño,
posiblemente 4 bytes o más, dependiendo de la arquitectura. Esto podría
llevar a comparaciones incorrectas y desbordamientos si los bloques de
memoria contienen datos no enteros.

Entonces, al usar unsigned char, nos aseguramos de que cada elemento se
trate como un byte individual, evitando problemas de interpretación y
desbordamiento, y garantizando una comparación segura y correcta de
bloques de memoria.
*/