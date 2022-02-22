/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:32:56 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 18:54:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char    *ft_strndup(unsigned char *src, size_t n)
{
	unsigned char    *dst;
	size_t  i;

	dst = malloc(sizeof(dst) * (n + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] && (i < n))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
