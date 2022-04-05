/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:09:55 by swillis           #+#    #+#             */
/*   Updated: 2022/04/05 13:21:29 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(unsigned char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

size_t	strlen_eol(unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

t_uchar	*ft_freestr(t_uchar *s)
{
	free(s);
	return (0);
}
