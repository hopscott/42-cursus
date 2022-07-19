/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:36:12 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 13:39:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_philo *philo)
{
	int	is_alive;

	pthread_mutex_lock(philo->lock);
	if (philo->is_alive)
		is_alive = 1;
	else
		is_alive = 0;
	pthread_mutex_unlock(philo->lock);
	return (is_alive);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;
	int		len_src;

	len_src = ft_strlen(src);
	dst = malloc(sizeof(char) * (len_src + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 1;
	while ((i < n) && str1[i - 1] && str2[i - 1])
	{
		if (str1[i - 1] != str2[i - 1])
			return (str1[i - 1] - str2[i - 1]);
		i++;
	}
	return (str1[i - 1] - str2[i - 1]);
}
