/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:54 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 18:59:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 42
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen_eol(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	ft_bzero(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strndup(char *src, int n)
{
	char	*str;
	int	i;

	if (!src || n <= 0)
		return (0);
	str = malloc(sizeof(char) * n + 1);
	if (!str)
		return (0);
	i = 0;
	while (src && src[i] && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_eolcheck(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_freestr(char *str)
{
	free(str);
	return (0);
}

char	*ft_concat(char *s, char *b)
{
	char	*new;
	int	len_s;
	int	len_b;
	int	i;
	int	j;

	if (!s || !b)
		return (0);
	len_s = ft_strlen_eol(s);
	len_b = ft_strlen_eol(b);
	new = malloc(sizeof(char) * (len_s + len_b + 1));
	if (!new)
		return (0);
	i = 0;
	while (i < len_s)
	{
		new[i] = s[i];
		i++;
	}
	j = 0;
	while (j < len_b)
	{
		new[i] = b[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(s);
	return (new);
}

char	*realign_buffer(char *buf, int i, char *str)
{
	char	*cpy;
	int	len;

	len = BUFFER_SIZE - i;
	cpy = ft_strndup(&buf[i], len);
	ft_bzero(buf, BUFFER_SIZE);
	i = 0;
	while (i < len)
	{
		buf[i] = cpy[i];
		i++;
	}
	free(cpy);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;
	int		rd;

	if (ft_strlen_eol(buffer) == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			return (0);
	}
	str = ft_strndup(buffer, ft_strlen_eol(buffer));
	while (!ft_eolcheck(str) || rd == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (ft_freestr(str));
		str = ft_concat(str, buffer);
	}
	return (realign_buffer(buffer, ft_strlen_eol(buffer), str));
}
