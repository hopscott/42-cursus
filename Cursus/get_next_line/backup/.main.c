//	printf("\n*** buffer: \n%s***", buffer);
//	printf("\n*** str: \n%s***", str);
//	printf("\n--- buff_read: %d", buff_read);
//	printf("\n--- len: %d", len);
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;
	char	*line;

    fd = open("./text.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("\n>>>\n%s>>>", line);
    line = get_next_line(fd);
    printf("\n>>>\n%s>>>", line);
    line = get_next_line(fd);
    printf("\n>>>\n%s>>>", line);
//    while (line)
//	{
//		line = get_next_line(fd);
//		printf("\n>>>\n%s>>>", line);
//	}
    return (0);
}
//	printf("\n*** buffer: \n%s***", buffer);
//	printf("\n*** str: \n%s***", str);
//	printf("\n--- buff_read: %d", buff_read);
//	printf("\n--- len: %d", len);
