/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:28:10 by swillis           #+#    #+#             */
/*   Updated: 2021/11/25 16:49:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

char	*ft_strmapi(char const *s, int (*f)(int));

int	main()
{
	printf("toupper: %s -> %s\n", "abc", ft_strmapi("abc", toupper));
	return (0);
}

/*
#include <stdlib.h>

unsigned int	ft_strlen(char const *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, int (*f)(int))
{
	int		(*ptr)(int);
	unsigned int	i;
	char		*str;

	ptr = f;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while (s[i])
	{
		str[i] = (*ptr)(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>
#include <ctype.h>

char	*ft_strmapi(char const *s, int (*f)(int));

int	main()
{
	printf("toupper: %s -> %s\n", "abc", ft_strmapi("abc", toupper));
	return (0);
}
*/
