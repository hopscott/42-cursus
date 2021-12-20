/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:04:52 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 23:43:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	main()
{
	printf("********* strjoin **********\n");
	printf("---------------------------\n");
	printf("ft_strjoin =\t%s\n", ft_strjoin("abc", "123"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strjoin =\t%s\n", ft_strjoin("", "123"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strjoin =\t%s\n", ft_strjoin("abc", ""));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strjoin =\t%s\n", ft_strjoin("", ""));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strjoin =\t%s\n", ft_strjoin("~", "-"));
	printf("---------------------------\n");
	return (0);
}
