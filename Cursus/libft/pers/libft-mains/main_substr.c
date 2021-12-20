/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:04:52 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 23:29:14 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main()
{
	printf("********* substr **********\n");
	printf("---------------------------\n");
	printf("ft_substr =\t%s\n", ft_substr("abcdef", 0, 6));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_substr =\t%s\n", ft_substr("abcdef", 1, 6));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_substr =\t%s\n", ft_substr("abcdef", 4, 6));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_substr =\t%s\n", ft_substr("abcdef", 6, 6));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_substr =\t%s\n", ft_substr("abcdef", 5, 16));
	printf("---------------------------\n");
	return (0);
}
