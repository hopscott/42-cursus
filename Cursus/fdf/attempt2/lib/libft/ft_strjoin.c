/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:30:19 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 18:55:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strjoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*str;
	int				len_s1;
	int				len_s2;
	int				i;
	int				j;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(str));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
