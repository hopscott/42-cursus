/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:05:22 by swillis           #+#    #+#             */
/*   Updated: 2021/12/01 15:01:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int				i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((char)str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (((char)str[i] == (char)c) && ((char)c == 0))
		return ((char *)&str[i]);
	return (0);
}
