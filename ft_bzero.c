/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:40:16 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/10 19:40:16 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*aux;

	aux = (unsigned char *)s;
	while (n--)
	{
		*aux = 0;
		aux++;
	}//TESTEA EN MACOS QUE AQUI NO TENGO LA LIBRERIA STRINGS.H
}
