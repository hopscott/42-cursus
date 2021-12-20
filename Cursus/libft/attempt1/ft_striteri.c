/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:36:01 by swillis           #+#    #+#             */
/*   Updated: 2021/12/01 15:31:11 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	void			(*ptr)(unsigned int, char*);
	unsigned int	i;

	ptr = f;
	i = 0;
	while (s[i])
	{
		(*ptr)(i, &s[i]);
		i++;
	}
}
