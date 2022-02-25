/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:50:55 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 19:49:08 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*ft_strbase(int n, unsigned char *base)
{
	unsigned char	*str;
	unsigned int	nb;
	int				digits;
	int				i;

	digits = ft_finddigits_int(n, ft_strlen(base));
	str = malloc(sizeof(str) * (digits + 1));
	if (!str)
		return (0);
	nb = n;
	if (n < 0)
		nb = -n;
	str[digits] = '\0';
	i = digits - 1;
	while (i >= 0)
	{
		if ((i == 0) && (n < 0))
			str[i--] = '-';
		else
			str[i--] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	return (str);
}

unsigned char	*ft_itobinoct(unsigned char c)
{
	unsigned char	*str;

	str = ft_strbase((int)c, (unsigned char *)"01" );
	while (ft_strlen(str) < 8)
		str = ft_strjoin((unsigned char *)"0", str);
	return (str);
}

unsigned char	*ft_convert_base(unsigned char *nbr, unsigned char *b_from, \
														unsigned char *b_to)
{
	int				n;
	unsigned char	*str;

	if (!atoi_base_check(b_from) || !atoi_base_check(b_to))
		return (NULL);
	n = ft_atoi_base(nbr, b_from);
	str = ft_itoa_base(n, b_to);
	return (str);
}

unsigned char	ft_binocttochar(unsigned char *bin)
{
	unsigned char	*trim;
	unsigned char	c;

	trim = malloc(sizeof(trim) * 9);
	if (!trim)
		return (0);
	ft_strlcpy(trim, bin, 9);
	c = ft_atoi(ft_convert_base(trim, (unsigned char *)"01", \
										(unsigned char *)"0123456789"));
	free(trim);
	return (c);
}

unsigned char	*ft_bintostr(unsigned char *bin)
{
	unsigned char	*str;
	int				len;
	int				i;
	int				j;

	len = ft_strlen(bin) / 8;
	str = malloc(sizeof(str) * len);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i * 8;
		str[i] = ft_binocttochar(&bin[j]);
		i++;
	}
	return (str);
}
