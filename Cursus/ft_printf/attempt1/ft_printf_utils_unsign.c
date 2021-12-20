/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:23:34 by swillis           #+#    #+#             */
/*   Updated: 2021/12/17 20:27:16 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_finddigits_unsign(unsigned int n, int len_base)
{
	int	digits;
	
	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		n /= (unsigned int)len_base;
		digits++;
	}
	return (digits);
}

void	ft_putbase_unsign(unsigned int n, char *base)
{
	char	*str;
	int		i;
	int		digits;
	int		lenbase;

	lenbase = ft_strlen(base);
	digits = ft_finddigits_unsign(n, lenbase);
	str = malloc(sizeof(char) * (digits + 1));
	i = digits - 1;
	while (i >= 0)
	{
		str[i] = base[n % (unsigned int)lenbase];
		n /= (unsigned int)lenbase;
		i--;
	}
	str[digits] = '\0';
	ft_putstr(str);
	free(str);
}
