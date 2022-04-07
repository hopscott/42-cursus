#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0 ;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_intlen(int n, char *base)
{
	int		digits;
	unsigned int	nb;

	digits = 0;
	nb = n;
	if (n <= 0)
	{
		nb = -n;
		digits++;
	}
	while (nb > 0)
	{
		nb /= ft_strlen(base);
		digits++;
	}
	return (digits);
}

int	ft_putbase(int n, char *base)
{
	unsigned int	nb;
	int		digits;
	char		*str;
	int		i;

	digits = ft_intlen(n, base);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (0);
	nb = n;
	if (n <= 0)
		nb = -n;
	str[digits] = '\0';
	i = digits - 1;
	while (i >= 0)
	{
		str[i] = base[nb % ft_strlen(base)];
		if (i == 0 && n < 0)
			str[i] = '-';
		nb /= ft_strlen(base);
		i--;
	}
	digits = ft_putstr(str);
	free(str);
	return (digits);
}

int	ft_putvar(const char c, va_list vars)
{
	if (c == '%')
		return (ft_putchar(c));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(vars, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(vars, char *)));
	else if (c == 'd')
		return (ft_putbase(va_arg(vars, int), "0123456789"));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list	vars;
	int	i;
	int	count;

	va_start(vars, str);
	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_putvar(str[i], vars);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(vars);
	return (count);
}
