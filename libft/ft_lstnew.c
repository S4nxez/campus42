/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.C                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:49:54 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/16 21:49:54 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *element;

	element = (t_list*)malloc(sizeof(element));
	if (!element)
		return ;
	element->content = content;
	element->next = NULL;

	return (element);
} 