/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:01 by swillis           #+#    #+#             */
/*   Updated: 2021/12/15 15:27:28 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_eolcheck(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_freechar(char *s)
{
	free(s);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	int			buff_read;

	if ((fd < 0) || (fd > 1024))
		return (0);
	if (!buffer)
	{
		buffer = calloc(BUFFER_SIZE, sizeof(char));
		if (!buffer)
			return (0);
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if ((buff_read == -1) || (buff_read == 0))
			return (ft_freechar(buffer));
		printf("\n*** buffer: \n%s***", buffer);
		printf("\n--- buff_read: %d", buff_read);
		printf("\n--- pos: %zu", ft_strlen(buffer));
	}
	str = ft_strndup(buffer, ft_strlen(buffer));
	printf("\n*** str: \n%s***", str);
	while (!ft_eolcheck(str)) 
	{
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if ((buff_read == -1) || (buff_read == 0))
			return (ft_freechar(str));
		printf("\n*** buffer: \n%s***", buffer);
		printf("\n--- buff_read: %d", buff_read);
		printf("\n--- pos: %zu", ft_strlen(buffer));
		str = ft_strjoin(str, ft_strndup(buffer, ft_strlen(buffer)));
		printf("\n*** str: \n%s***", str);
	}
	buffer = &buffer[ft_strlen(buffer)];
	printf("\n*** buffer: \n%s***", buffer);
	printf("\n--- buff_read: %d", buff_read);
	printf("\n--- pos: %zu", ft_strlen(buffer));
	return (str);
}
