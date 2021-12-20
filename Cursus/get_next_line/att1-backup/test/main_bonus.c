#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
    int fd1;
    int fd2;
    int fd3;
	char	*line;

    fd1 = open("test/test1.txt", O_RDONLY);
    fd2 = open("test/test2.txt", O_RDONLY);
    fd3 = open("test/test3.txt", O_RDONLY);
    printf("\n>>>\n%s>>>", get_next_line(fd1));
    printf("\n>>>\n%s>>>", get_next_line(fd2));
    printf("\n>>>\n%s>>>", get_next_line(fd3));
    printf("\n>>>\n%s>>>", get_next_line(fd1));
    printf("\n>>>\n%s>>>", get_next_line(fd2));
    printf("\n>>>\n%s>>>", get_next_line(fd3));
    printf("\n>>>\n%s>>>", get_next_line(fd1));
    printf("\n>>>\n%s>>>", get_next_line(fd2));
    printf("\n>>>\n%s>>>", get_next_line(fd3));
    printf("\n>>>\n%s>>>", get_next_line(fd1));
    printf("\n>>>\n%s>>>", get_next_line(fd2));
    printf("\n>>>\n%s>>>", get_next_line(fd3));
    return (0);
}
