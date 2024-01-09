/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:07:22 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/09 19:38:53 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_memset(void *b, int c, int len)
{
 char *aux = b;

 while (len > 0 && *aux != '\0')
 {
  *aux = (char)c;
  aux++;
  len--;
 }
}
#include <stdio.h>
int main()
{
 char hola[] = "Hola";
 ft_memset(hola, 'c', 2);
 printf("memset: %s",hola);
}