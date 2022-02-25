/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:53:20 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 18:30:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_eos(unsigned char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if ((len == 0) || (len % 8 != 0))
		return (0);
	i = len - 8;
	while (i < len)
	{
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}
