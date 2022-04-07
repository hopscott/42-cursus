/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:26:35 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 21:13:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_numlen(int n, int baselen)
{
	int		i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	while (nb > 0)
	{
		nb /= baselen;
		i++;
	}
	return (i);
}

int	ft_putbase(int n, char *base)
{
	int		baselen;
	int		digits;
	unsigned int	nb;
	int		i;
	char		*str;

	baselen = ft_strlen(base);
	digits = ft_numlen(n, baselen);
	str = malloc(sizeof(char) * digits + 1);
	if (!str)
		return (0);
	nb = n;
	if (n < 0)
		nb = -n;
	i = digits;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = base[nb % baselen];
		nb /= baselen;
		if (i == 0 && n < 0)
			str[i] = '-';
		i--;
	}
	ft_putstr(str);
	free(str);
	return (digits);
}

int	ft_putvar(const char c, va_list vars)
{
	
	if (c == 'c')
		return (ft_putchar(va_arg(vars, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(vars, char *)));
	else if (c == 'i')
		return (ft_putbase(va_arg(vars, int), "0123456789"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	vars;
	int	i;
	int	len;

	va_start(vars, str);
	len = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_putvar(str[i], vars);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(vars);
	return (len);
}
