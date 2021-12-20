/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:45:02 by swillis           #+#    #+#             */
/*   Updated: 2021/12/06 17:08:12 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		len;
	int		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	while ((s1[start]) && ft_isset(s1[start], set))
		start++;
	end = ft_strlen((char *)s1) - 1;
	while ((end > start) && ft_isset(s1[end], set))
		end--;
	len = end - start + 2;
	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
