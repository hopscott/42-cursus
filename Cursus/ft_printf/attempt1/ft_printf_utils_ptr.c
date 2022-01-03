/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:23:34 by swillis           #+#    #+#             */
/*   Updated: 2022/01/03 15:18:52 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_finddigits_ull(unsigned long long add, int len_base)
{
	int	digits;

	if (add == 0)
		return (1);
	digits = 0;
	while (add > 0)
	{
		add /= (unsigned long long)len_base;
		digits++;
	}
	return (digits);
}

int	ft_putptr(unsigned long long add, char *base)
{
	char	*str;
	int		i;
	int		digits;
	int		lenbase;

	lenbase = ft_strlen(base);
	digits = ft_finddigits_ull(add, lenbase);
	str = malloc(sizeof(char) * (digits + 1));
	i = digits - 1;
	while (i >= 0)
	{
		str[i] = base[add % (unsigned long long)lenbase];
		add /= (unsigned long long)lenbase;
		i--;
	}
	str[digits] = '\0';
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
	return (2 + digits);
}
