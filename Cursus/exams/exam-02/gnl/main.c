/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:43:33 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 18:53:41 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *get_next_line(int fd);

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*path;
	char	*line;
	int	fd;
	int	i;

	if (ac = 2)
	{
		path = av[1];
		fd = open(path, O_RDONLY);
		line = get_next_line(fd);
		i = 1;
		printf(">%d> %s", i, line);
		while (line)
		{
			line = get_next_line(fd);
			i++;
			printf(">%d> %s", i, line);
		}
	}
	return (0);
}
