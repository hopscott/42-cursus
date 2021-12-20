/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:23:34 by swillis           #+#    #+#             */
/*   Updated: 2021/12/17 18:43:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	ft_finddigits_int(int n, int len_base)
{
	int				digits;
	unsigned int	nb;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		nb = -n;
		digits++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb /= len_base;
		digits++;
	}
	return (digits);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putbase(int n, char *base)
{
	char			*str;
	unsigned int	nb;
	int				i;

	str = malloc(sizeof(char) * (ft_finddigits_int(n, ft_strlen(base)) + 1));
	if (n < 0)
		nb = -n;
	else
		nb = n;
	i = ft_finddigits_int(n, ft_strlen(base)) - 1;
	while (i >= 0)
	{
		str[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[ft_finddigits_int(n, ft_strlen(base))] = '\0';
	ft_putstr(str);
	free(str);
}
