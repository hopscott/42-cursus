#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char status[2] = "KO";
    char buff[32];

    puts("Give me your name, and I'll check if your status is OK");
    gets(buff);
	printf("buff = %s\n", buff);
	printf("status = %s\n", status);
    if (strncmp(status, "OK", 2) == 0)
        system("cat flag.txt");
    else
        puts("Try again. Bye.");
}
