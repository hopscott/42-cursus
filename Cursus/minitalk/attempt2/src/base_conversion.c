/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:30:52 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 18:57:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_basefinder(unsigned char c, unsigned char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_space(unsigned char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	atoi_base_check(unsigned char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\r')
			return (0);
		if (base[i] == '\v' || base[i] == '\f' || base[i] == ' ')
			return (0);
		j = 0;
		while (base[j])
		{
			if ((base[j] == base[i]) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(unsigned char *str, unsigned char *base)
{
	int				i;
	int				sign;
	unsigned int	n;
	int				nbr;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (ft_basefinder(str[i], base) != -1))
	{
		n = n * ft_strlen(base) + ft_basefinder(str[i], base);
		i++;
	}
	nbr = n * sign;
	return (nbr);
}

unsigned char	*ft_itoa_base(int n, unsigned char *base)
{
	unsigned char	*str;
	unsigned int	nb;
	int				i;

	str = malloc(sizeof(str) * (ft_finddigits_int(n, ft_strlen(base)) + 1));
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
	return (str);
}
