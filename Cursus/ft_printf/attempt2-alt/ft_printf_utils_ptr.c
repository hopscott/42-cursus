/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:23:34 by swillis           #+#    #+#             */
/*   Updated: 2022/01/06 20:00:49 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulllen(unsigned long long n, char *base)
{
	unsigned long long	baselen;
	int					len;

	baselen = (unsigned long long)ft_strlen(base);
	len = 1;
	while (n > baselen)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

void	ft_putull(unsigned long long n, char *base)
{
	unsigned long long	baselen;

	baselen = (unsigned long long)ft_strlen(base);
	if (n > baselen)
		ft_putull(n / baselen, base);
	ft_putchar_len(base[n % baselen]);
}

int	ft_putptr(unsigned long long add, char *base)
{
	int	len;

	len = ft_putstr_len("0x");
	ft_putull(add, base);
	len += ft_ulllen(add, base);
	return (len);
}
