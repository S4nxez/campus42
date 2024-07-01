/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:04:56 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/01 18:56:05 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*ret;

	ret = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (ret);
}

static char	*read_from_file(char *basin_buffer, int fd)
{
	int			bytes_read;
	char		*cup_buffer;
	static int	count = 1;

	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(cup_buffer), NULL);
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basin_buffer);
}
char	*extract_line(char *basin_buffer)
{
	char	*ret;
	size_t	count;

	count = 0;
	while(basin_buffer[count] != '\n')
		count++;
	ret = ft_calloc(count, sizeof(char));
	ft_memcpy(ret, basin_buffer, count);
	return (ret);
}
char	*obtain_remaining(char *basin_buffer)
{
	char	*ret;
	int		count;
	int		count2;

	count = 0;
	while(basin_buffer[count] != '\n')
		count++;
	count2 = 0;
	while(basin_buffer[count] != '\0')
	{
		count2++;
		count++;
	}
	ret = ft_calloc(count2, sizeof(char));
	ft_memcpy(ret, basin_buffer + (count - count2), count2);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}
