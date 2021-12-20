/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 14:17:24 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n);

int	main()
{
	unsigned char	str1[10] = "123456789";
	unsigned char	str2[10] = "123456789";
	unsigned char	str3[10] = "123456789";
	unsigned char	str4[10] = "123456789";
	unsigned char	str5[10] = "123456789";

	printf("********* memset **********\n");
	printf("---------------------------\n");
	//printf("memset    =\t%s\n", memset(str1, 'a', 5));
	printf("ft_memset =\t%s\n", ft_memset(str1, 'a', 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("memset    =\t%s\n", memset(str2, '0', 11));
	printf("ft_memset =\t%s\n", ft_memset(str2, '0', 11));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("memset    =\t%s\n", memset(str3, ' ', 8));
	printf("ft_memset =\t%s\n", ft_memset(str3, ' ', 8));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("memset    =\t%s\n", memset(str4, '~', 0));
	printf("ft_memset =\t%s\n", ft_memset(str4, '~', 0));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("memset    =\t%s\n", memset(str5, '~', 1));
	printf("ft_memset =\t%s\n", ft_memset(str5, '~', 1));
	printf("---------------------------\n");
	return (0);
}
