/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:26:15 by swillis           #+#    #+#             */
/*   Updated: 2022/01/03 14:54:38 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_varcheck(const char *str)
{
	int	i;

	i = 0;
	if ((str && str[i]) && (str[i] == '%'))
	{
		if (str[i + 1] == 'c')
			return (1);
		else if (str[i + 1] == 's')
			return (1);
		else if (str[i + 1] == 'p')
			return (1);
		else if (str[i + 1] == 'd')
			return (1);
		else if (str[i + 1] == 'i')
			return (1);
		else if (str[i + 1] == 'u')
			return (1);
		else if (str[i + 1] == 'x')
			return (1);
		else if (str[i + 1] == 'X')
			return (1);
		else if (str[i + 1] == '%')
			return (1);
	}
	return (0);
}

int	ft_putvar(const char c, va_list vars)
{
	char	*str;
	int		len;

	if (c == 'c')
		str = ft_putchar(va_arg(vars, int));
	else if (c == 's')
		str = ft_putstr(va_arg(vars, char *));
	else if (c == 'p')
		str = ft_putptr(va_arg(vars, unsigned long long), "0123456789abcdef");
	else if (c == 'd')
		str = ft_putbase(va_arg(vars, int), "0123456789");
	else if (c == 'i')
		str = ft_putnbr(va_arg(vars, int));
	else if (c == 'u')
		str = ft_putbase_unsign(va_arg(vars, unsigned int), "0123456789");
	else if (c == 'x')
		str = ft_putbase_unsign(va_arg(vars, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		str = ft_putbase_unsign(va_arg(vars, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		str = ft_putchar('%');
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	vars;
	int		i;
	int		count;

	va_start(vars, str);
	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (ft_varcheck(&str[i]))
		{
			i++;
			count += ft_putvar(str[i], vars);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	count += i;
	va_end(vars);
	return (count);
}
