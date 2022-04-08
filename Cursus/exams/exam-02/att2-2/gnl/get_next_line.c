#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	check_eol(char *str)
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

int	bufflen_eol(char buff[])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buff[i])
	{
		if (buff[i] == '\n')
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

char	*ft_strndup(char *str, int n)
{
	int	i;
	char	*dup;

	if (n < 1)
		return (NULL);
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_concat(char *s, char *b, int n)
{
	char	*cat;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(s);
	if (n < 1)
		return (s);
	cat = malloc(sizeof(char) * (len + n + 1));
	if (!cat)
		return (s);
	i = 0;
	while (i < len)
	{
		cat[i] = s[i];
		i++;
	}
	j = 0;
	while (j < n)
		cat[i++] = b[j++];
	cat[i] = '\0';
	free(s);
	return (cat);
}

char	*realign_buffer(char *str, char buff[], int n)
{
	char	*tmp;
	int	i;
	int	len;

	len = BUFFER_SIZE - n;
	tmp = ft_strndup(&buff[n], len);
	ft_bzero(buff, BUFFER_SIZE);
	i = 0;
	while (i < len)
	{
		buff[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;
	int		rd;

	if (fd < 0 || fd > 1024)
		return (NULL);
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
		if (rd < 0)
		{
			free(str);
			return (NULL);
		}
		if (rd == 0)
			break;
		str = ft_concat(str, buffer, bufflen_eol(buffer));
	}
	return (realign_buffer(str, buffer, bufflen_eol(buffer)));
}
