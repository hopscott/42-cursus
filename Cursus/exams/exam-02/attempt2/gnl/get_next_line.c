#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	eol_check(char *str)
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

size_t	ft_strlen_eol(char *str)
{
	size_t	i;

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
	size_t	i;

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strndup(char *src, int n)
{
	int	i;
	char	*dst;

	if (n < 1)
		return (NULL);
	dst = malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_concat(char *str, char *buff)
{
	char	*cat;
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;

	l1 = ft_strlen(str);
	l2 = ft_strlen_eol(str);
	if (l1 == 0 || l2 == 0)
		return (str);
	cat = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!cat)
		return (NULL);
	i = 0;
	while (str && str[i] && i < l1)
	{
		cat[i] = str[i];
		i++;
	}
	j = 0;
	while (buff && buff[j] && j < l2)
	{
		cat[i] = buff[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	free(str);
	return (cat);
}

#include <stdio.h>

char	*realign_buffer(char *str, char *buff)
{
	char	*tmp;
	size_t	start;
	size_t	end;
	size_t	i;

	start = ft_strlen_eol(buff);
	end = ft_strlen(buff);
	if (start == 0 && end == 0)
	{
		free(buff);
		free(str);
		return (NULL);
	}
	tmp = ft_strndup(&buff[start], (end - start));
	ft_bzero(buff, (BUFFER_SIZE + 1));
	i = 0;
	while (tmp && tmp[i])
	{
		buff[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	int		rd;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			return (NULL);
	}
	str = ft_strndup(buffer, ft_strlen_eol(buffer));
	while (eol_check(str) == 0 || (rd <= 0))
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
			break;
		str = ft_concat(str, buffer);
	}
	return (realign_buffer(str, buffer));
}
