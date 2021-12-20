#include "ft_printf.h"
#include <stdio.h>

/*
int	main()
{
	int	*ptr;
	int	n;

	n = 42;
	ptr = &n;

	printf(">>> char = %c |", 'A');
	ft_printf(" =========== | %c |", 'A');

	printf("\n>>> str = %s |", "hello");
	ft_printf("| %s |", "hello");
	
	printf("\n>>> ptr = %p |", &ptr);
	ft_printf("| %p |", &ptr);

	printf("\n>>> dec = %d |", -2147483647);
	ft_printf("| %d |", -2147483647);

	printf("\n>>> int = %i |", -2147483647);
	ft_printf("| %i |", -2147483647);

	printf("\n>>> udec = %u |", -1);
	ft_printf("| %u |", -1);

	printf("\n>>> hex = %x |", 2147483647);
	ft_printf("| %x |", 2147483647);

	printf("\n>>> HEX = %X |", 2147483647);
	ft_printf("| %X |", 2147483647);

	printf("\n>>> %% = %% |");
	ft_printf("| %% |");

	return (0);
}
*/

int main()
{
    char            c          = 'f';
    char            *s         = "it works dont touch it";
    int                d        = 424242;
    int                i        = 0x4242;
    unsigned int    u         = 3751374819;
    int                x        = -14871304;
    int                X        = 395170124;
    void            *p        = &d;

    ft_printf("return value: %d\n", ft_printf("\033[0;33m===========[ FT ]==========\nchar:\t\t'%c'\nstring:\t\t\"%s\"\npointer:\t%p\ndecimal:\t%d\ninteger:\t%i\nunsigned int:\t%u\nhex:\t\t%x\nHEX:\t\t%X\npercent:\t%%\n", c, s, p, d, i, u, x, X));
    printf("\n");
    printf("return value: %d\n", printf("\033[0;32m===========[ OG ]==========\nchar:\t\t'%c'\nstring:\t\t\"%s\"\npointer:\t%p\ndecimal:\t%d\ninteger:\t%i\nunsigned int:\t%u\nhex:\t\t%x\nHEX:\t\t%X\npercent:\t%%\n", c, s, p, d, i, u, x, X));
}
