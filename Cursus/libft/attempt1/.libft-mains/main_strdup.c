/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 22:44:16 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strdup(const char *s);

int	main()
{
	printf("********* strdup **********\n");
	printf("---------------------------\n");
	printf("strdup =\t%s\n", strdup("abcdef"));
	printf("ft_strdup =\t%s\n", ft_strdup("abcdef"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strdup =\t%s\n", strdup("a"));
	printf("ft_strdup =\t%s\n", ft_strdup("a"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strdup =\t%s\n", strdup(""));
	printf("ft_strdup =\t%s\n", ft_strdup(""));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strdup =\t%s\n", strdup("a\tb\nc"));
	printf("ft_strdup =\t%s\n", ft_strdup("a\tb\nc"));
	printf("---------------------------\n");
	return (0);
}
