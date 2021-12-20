/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:06 by swillis           #+#    #+#             */
/*   Updated: 2021/12/01 15:03:05 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	if (!str)
		return (0);
	i = 0;
	ptr = 0;
	while (str[i] != 0)
	{
		if ((char)str[i] == (char)c)
			ptr = (char *)&str[i];
		i++;
	}
	if (((char)str[i] == (char)c) && ((char)c == 0))
		return ((char *)&str[i]);
	return (ptr);
}
