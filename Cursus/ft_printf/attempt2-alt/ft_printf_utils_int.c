/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:22:14 by swillis           #+#    #+#             */
/*   Updated: 2022/01/06 19:54:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int n, char *base)
{
	int	baselen;
	int	len;

	baselen = ft_strlen(base);
	len = 1;
	while (n > baselen)
	{
		len++;
		n /= baselen;
	}
	if (n < 0)
		len++;
	return (len);
}

void	ft_putint(int n, char *base)
{
	int				baselen;
	unsigned int	nb;

	baselen = ft_strlen(base);
	nb = n;
	if (n < 0)
	{
		ft_putchar_len('-');
		nb = -n;
	}
	if (n > baselen)
		ft_putint(n / baselen, base);
	ft_putchar_len(base[n % baselen]);
}

int	ft_putint_len(int n, char *base)
{
	ft_putint(n, base);
	return (ft_intlen(n, base));
}
