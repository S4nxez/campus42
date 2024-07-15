/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:04:13 by dansanc3          #+#    #+#             */
/*   Updated: 2024/07/15 17:56:24 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	count++;
	printf("[%d]:%s", count, line);
	line = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	count++;
	printf("[%d]:%s\n", count, line);
	line = NULL;
	close(fd);
	return (0);
}
