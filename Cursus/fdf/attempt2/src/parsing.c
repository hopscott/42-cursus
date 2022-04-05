/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:25:58 by swillis           #+#    #+#             */
/*   Updated: 2022/04/05 14:47:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_elemcount(t_uchar *str)
{
	int	i;
	int	elem;

	i = 0;
	elem = 0;
	while (str && str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			elem++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (elem);
}
