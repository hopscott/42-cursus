#include <stdio.h>

int ft_printf(const char *str, ...);

int	main(void)
{
	printf(">ft> %d\n", ft_printf("Hello no.%d%%%c %s\n", -123456789, 'a', "How are you?"));
	printf(">og> %d\n", printf("Hello no.%d%%%c %s\n", -123456789, 'a', "How are you?"));
	return (0);
}
