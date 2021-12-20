/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:26:31 by swillis           #+#    #+#             */
/*   Updated: 2021/12/15 18:28:11 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_concat(char *str, char *buffer)
{
	char	*cat;

	cat = ft_strndup(buffer, ft_strlen(buffer));
	str = ft_strjoin(str, cat);
	free(cat);
	return (str);
}

void	ft_realign_buff(char buffer[])
{
	char	*str;
	int		start;
	int		end;
	int		i;

	start = ft_strlen(buffer);
	end = start;
	while (buffer[end])
		end++;
	str = ft_strndup(&buffer[start], (end - start));
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	free(str);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE];
	char		*str;
	int			buff_read;

	if ((fd < 0) || (fd > 1024))
		return (0);
	if (ft_strlen(buffer[fd]) == 0)
	{
		buff_read = read(fd, buffer[fd], BUFFER_SIZE);
		if ((buff_read == -1) || (buff_read == 0))
			return (0);
	}
	str = ft_strndup(buffer[fd], ft_strlen(buffer[fd]));
	while (!ft_eolcheck(str))
	{
		buff_read = read(fd, buffer[fd], BUFFER_SIZE);
		if ((buff_read == -1) || (buff_read == 0))
			return (ft_freechar(str));
		str = ft_concat(str, buffer[fd]);
	}
	ft_realign_buff(buffer[fd]);
	return (str);
}
