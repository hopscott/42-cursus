/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:01 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 17:55:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_eolcheck(t_uchar *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_uchar	*ft_concat(t_uchar *str, t_uchar *buffer)
{
	t_uchar	*cat;
	t_uchar	*new;

	cat = ft_strndup(buffer, ft_strlen_eol(buffer));
	new = ft_strjoin_eol(str, cat);
	free(str);
	free(cat);
	return (new);
}

t_uchar	*ft_realign_buff(t_uchar *s, t_uchar buffer[])
{
	t_uchar	*str;
	int		start;
	int		end;
	int		i;

	start = ft_strlen_eol(buffer);
	end = start;
	while (buffer[end])
		end++;
	str = ft_strndup(&buffer[start], (end - start));
	ft_bzero(buffer, BUFFER_SIZE);
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	free(str);
	return (s);
}

t_uchar	*ft_freechar(t_uchar *s)
{
	free(s);
	return (0);
}

t_uchar	*get_next_line(int fd)
{
	static t_uchar	buffer[BUFFER_SIZE];
	t_uchar			*str;
	int				buff_read;

	if ((fd < 0) || (fd > 1024))
		return (0);
	buff_read = -1;
	if (ft_strlen_eol(buffer) == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if ((buff_read == -1) || (buff_read == 0))
			return (0);
	}
	str = ft_strndup(buffer, ft_strlen_eol(buffer));
	while (!ft_eolcheck(str) || buff_read == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if (buff_read == -1)
			return (ft_freechar(str));
		if (buff_read > 0)
			str = ft_concat(str, buffer);
	}
	return (ft_realign_buff(str, buffer));
}
