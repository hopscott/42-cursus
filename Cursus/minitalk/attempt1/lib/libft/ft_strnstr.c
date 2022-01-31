/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:55:58 by swillis           #+#    #+#             */
/*   Updated: 2021/12/03 12:28:16 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(find) == 0)
		return ((char *)str);
	while ((str[i] != 0) && (i < len))
	{
		j = 0;
		while ((str[i + j] == find[j]) && (i + j < len))
		{
			if (j == ft_strlen(find) - 1)
			{
				return ((char *)&str[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
