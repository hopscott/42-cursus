/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:45:02 by swillis           #+#    #+#             */
/*   Updated: 2021/11/30 13:27:08 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	ft_trimlen(char const *s1, char const *set)
{
	int	len;
	int	i;

	i = 0;
	while ((s1[i]) && ft_isset(s1[i], set))
		i++;
	len = i;
	while ((s1[i]) && !ft_isset(s1[i], set))
		i++;
	len = i - len;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc((ft_trimlen(s1, set) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while ((s1[i]) && ft_isset(s1[i], set))
		i++;
	j = 0;
	while ((s1[i]) && !ft_isset(s1[i], set))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
