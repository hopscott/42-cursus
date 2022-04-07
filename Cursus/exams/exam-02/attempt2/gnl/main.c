
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		printf(">%s<", line);
		while (line)
		{
			line = get_next_line(fd);
			printf(">%s<", line);
		}
		printf(">%s<", line);
	}
}
