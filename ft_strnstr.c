/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:40:02 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/26 16:44:31 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnst(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;
	size_t	j;

	len_needle = ft_strlen(needle);
	i = 0;
	j = 0;
	if (len_needle == 0)
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i += j - 1;
		j = 0;
		i++;
	}//darle un buen repaso a esto que lo he hecho a medias y con pinzas
	return (NULL);
}
