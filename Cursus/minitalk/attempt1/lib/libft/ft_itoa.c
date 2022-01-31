/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:23:51 by swillis           #+#    #+#             */
/*   Updated: 2021/11/30 13:20:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numlen(int n)
{
	unsigned int	len;
	unsigned int	un;

	len = 0;
	if (n < 0)
	{
		len++;
		un = -n;
	}
	else
		un = n;
	if (un == 0)
		len++;
	while (un > 0)
	{
		len++;
		un /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	un;
	char			*str;

	i = ft_numlen(n);
	str = malloc((ft_numlen(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		un = -n;
	}
	else
		un = n;
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (un > 0)
	{
		str[i--] = '0' + un % 10;
		un /= 10;
	}
	return (str);
}
