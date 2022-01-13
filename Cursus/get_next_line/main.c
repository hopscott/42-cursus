#include <stdio.h>
#include "get_next_line_bonus.h"

int main(int ac, char **av)
{
	char *str;
	int fd = open(av[1], O_RDONLY);
	int fd2 = open(av[2], O_RDONLY);

	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd2);
		printf("%s", str);
		free(str);
	}
}
