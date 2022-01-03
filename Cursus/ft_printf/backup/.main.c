#include "ft_printf.h"
#include <stdio.h>

int	main()
{
//	ft_printf("5. >>>");
//	printf("**%d**", printf(" %c %c %c ", '0', 0, '1'));
//	ft_printf("|");
//	printf(" %c %c %c ", '0', 0, '1');


//	ft_printf("8. >>>");
//	ft_printf("count: %d", ft_printf(" %c %c %c ", '2', '1', 0));
//	ft_printf("|");
//	printf(" %c %c %c ", '2', '1', 0);

//	printf("count: %d", printf(" NULL %s NULL ", NULL));

//	printf("count: %d", printf(" %p %p ", 0, 0));

//	printf("count: %d", ft_printf(" %d ", 0));

//	printf("count: %d", printf(" %c %c %c ", '0', 0, '1'));

	printf("|count: %d|", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));

	return (0);
}
