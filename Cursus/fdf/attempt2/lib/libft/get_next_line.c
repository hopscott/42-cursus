/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:01 by swillis           #+#    #+#             */
/*   Updated: 2022/04/05 14:11:27 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
size_t	bufflen_eol(unsigned char buff[])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buff[i])
	{
		if (buff[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

size_t	check_eol(t_uchar *str)
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

t_uchar	*ft_concat(t_uchar *str, t_uchar buff[])
{
	t_uchar	*cat;
	size_t	slen;
	size_t	blen;
	size_t	i;
	size_t	j;

	slen = ft_strlen(str);
	blen = bufflen_eol(buff);
	cat = malloc(sizeof(cat) * (slen + blen + 1));
	if (!cat)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		cat[i] = str[i];
		i++;
	}
	j = 0;
	while (j < blen)
		cat[i++] = buff[j++];
	cat[i] = '\0';
	free(str);
	return (cat);
}

t_uchar	*ft_realign_buff(t_uchar *s, size_t i, t_uchar buff[])
{
	t_uchar	*tmp;
	size_t	len;

	len = BUFFER_SIZE - i;
	if (len > 0)
	{
		tmp = ft_strndup(&buff[i], len);
		ft_bzero(buff, BUFFER_SIZE);
		i = 0;
		while (tmp && i < len)
		{
			buff[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	return (s);
}

t_uchar	*get_next_line(int fd)
{
	static t_uchar	buffer[BUFFER_SIZE];
	t_uchar			*str;
	int				rd;

	if ((fd < 0) || (fd > 1024))
		return (NULL);
	rd = -1;
	if (bufflen_eol(buffer) == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
	}
	str = ft_strndup(buffer, bufflen_eol(buffer));
	while (!check_eol(str) || rd == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		str = ft_concat(str, buffer);
	}
	return (ft_realign_buff(str, bufflen_eol(buffer), buffer));
}
