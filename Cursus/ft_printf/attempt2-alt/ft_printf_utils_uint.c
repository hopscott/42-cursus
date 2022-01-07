/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_uint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:24:16 by swillis           #+#    #+#             */
/*   Updated: 2022/01/06 19:57:33 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintlen(unsigned int n, char *base)
{
	unsigned int	baselen;
	int				len;

	baselen = (unsigned int)ft_strlen(base);
	len = 1;
	while (n > baselen)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

void	ft_putuint(unsigned int n, char *base)
{
	unsigned int	baselen;

	baselen = (unsigned int)ft_strlen(base);
	if (n > baselen)
		ft_putuint(n, base);
	ft_putchar_len(base[n % baselen]);
}

int	ft_putuint_len(unsigned int n, char *base)
{
	ft_putuint(n, base);
	return (ft_uintlen(n, base));
}
