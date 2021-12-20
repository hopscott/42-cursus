/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 18:24:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main()
{
	unsigned char	str1[10] = "123456789";
	unsigned char	str2[10] = "123456789";
	unsigned char	str3[10] = "123456789";
	unsigned char	str4[10] = "123456789";
	unsigned char	str5[10] = "123456789";

	printf("********* memchr **********\n");
	printf("---------------------------\n");
	printf("memchr    =\t%s\n", memchr(str1, 'a', 5));
	printf("ft_memchr =\t%s\n", ft_memchr(str1, 'a', 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memchr    =\t%s\n", memchr(str2, '1', 11));
	printf("ft_memchr =\t%s\n", ft_memchr(str2, '1', 11));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memchr    =\t%s\n", memchr(str3, '5', 4));
	printf("ft_memchr =\t%s\n", ft_memchr(str3, '5', 4));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memchr    =\t%s\n", memchr(str4, '5', 6));
	printf("ft_memchr =\t%s\n", ft_memchr(str4, '5', 6));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memchr    =\t%s\n", memchr(str5, '~', 1));
	printf("ft_memchr =\t%s\n", ft_memchr(str5, '~', 1));
	printf("---------------------------\n");
	return (0);
}
