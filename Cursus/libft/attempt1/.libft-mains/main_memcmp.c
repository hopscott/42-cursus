/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 18:35:25 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main()
{
	unsigned char	dst1[10] = "123456789";
	unsigned char	dst2[10] = "123456789";
	unsigned char	dst3[10] = "123456789";
	unsigned char	dst4[10] = "123456789";
	unsigned char	dst5[10] = "123456789";
	unsigned char	src1[10] = "12345fghi";
	unsigned char	src2[10] = "12345fghi";
	unsigned char	src3[10] = "12345fghi";
	unsigned char	src4[10] = "abcdefghi";
	unsigned char	src5[10] = "abcdefghi";

	printf("********* memcmp **********\n");
	printf("---------------------------\n");
	printf("memcmp    =\t%d\n", memcmp(dst1, src1, 5));
	printf("ft_memcmp =\t%d\n", ft_memcmp(dst1, src1, 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memcmp    =\t%d\n", memcmp(dst2, src2, 9));
	printf("ft_memcmp =\t%d\n", ft_memcmp(dst2, src2, 9));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memcmp    =\t%d\n", memcmp(dst3, src3, 7));
	printf("ft_memcmp =\t%d\n", ft_memcmp(dst3, src3, 7));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memcmp    =\t%d\n", memcmp(dst4, src4, 0));
	printf("ft_memcmp =\t%d\n", ft_memcmp(dst4, src4, 0));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memcmp    =\t%d\n", memcmp(dst5, src5, 1));
	printf("ft_memcmp =\t%d\n", ft_memcmp(dst5, src5, 1));
	printf("---------------------------\n");
	return (0);
}
