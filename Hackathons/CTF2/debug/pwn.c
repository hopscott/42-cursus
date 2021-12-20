#include <stdio.h>
#include <stdlib.h>

// gcc -z execstack -z norelro -fno-stack-protector -o pwn pwn.c

int main(void)
{
	printf("gdbserver is listening ....\n");

	FILE* flag = fopen("flag.txt", "r");
	if (!flag)
		exit(EXIT_FAILURE);

   	char 	*buf = NULL;
   	size_t 	len = 0;

   	while (getline(&buf, &len, flag) != -1)
		printf("Debug is the key...\n");

	fclose(flag);
	free(buf);

   	return EXIT_SUCCESS;
}
