/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 17:52:10 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main()
{
	unsigned char	dst1[10] = "123456789";
	unsigned char	dst2[10] = "123456789";
	unsigned char	dst3[10] = "123456789";
	unsigned char	dst4[10] = "123456789";
	unsigned char	dst5[10] = "123456789";
	unsigned char	src1[10] = "12345fghi";
	unsigned char	src2[10] = "12345fghi";
	unsigned char	src3[10] = "abcdefghi";
	unsigned char	src4[10] = "abcdefghi";
	unsigned char	src5[10] = "abcdefghi";

	printf("********* strncmp **********\n");
	printf("---------------------------\n");
	printf("strncmp    =\t%d\n", strncmp(dst1, src1, 5));
	printf("ft_strncmp =\t%d\n", ft_strncmp(dst1, src1, 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strncmp    =\t%d\n", strncmp(dst2, src2, 11));
	printf("ft_strncmp =\t%d\n", ft_strncmp(dst2, src2, 11));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strncmp    =\t%d\n", strncmp(dst3, src3, 8));
	printf("ft_strncmp =\t%d\n", ft_strncmp(dst3, src3, 8));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strncmp    =\t%d\n", strncmp(dst4, src4, 0));
	printf("ft_strncmp =\t%d\n", ft_strncmp(dst4, src4, 0));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strncmp    =\t%d\n", strncmp(dst5, src5, 1));
	printf("ft_strncmp =\t%d\n", ft_strncmp(dst5, src5, 1));
	printf("---------------------------\n");
	return (0);
}
