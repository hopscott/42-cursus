#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd);

int	main(int ac, char **av)
{
	char	*line;
	int	fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		while (line)
		{
			printf(">%s<", line);
			line = get_next_line(fd);
		}
	}
	return (0);
}
