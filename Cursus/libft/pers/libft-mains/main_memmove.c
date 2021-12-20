/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 16:00:49 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int	main()
{
	unsigned char	dst1[10] = "123456789";
	unsigned char	dst2[10] = "123456789";
	unsigned char	dst3[10] = "123456789";
	unsigned char	dst4[10] = "123456789";
	unsigned char	dst5[10] = "123456789";
	unsigned char	src1[10] = "abcdefghij";
	unsigned char	src2[10] = "abcdefghij";
	unsigned char	src3[10] = "abcdefghij";
	unsigned char	src4[10] = "abcdefghij";
	unsigned char	src5[10] = "abcdefghij";

	printf("********* memmove **********\n");
	printf("---------------------------\n");
	printf("memmove    =\t%s\n", memmove(dst1, src1, 5));
	printf("ft_memmove =\t%s\n", ft_memmove(dst1, src1, 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memmove    =\t%s\n", memmove(dst2, src2, 10));
	printf("ft_memmove =\t%s\n", ft_memmove(dst2, src2, 10));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memmove    =\t%s\n", memmove(dst3, src3, 8));
	printf("ft_memmove =\t%s\n", ft_memmove(dst3, src3, 8));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memmove    =\t%s\n", memmove(dst4, src4, 0));
	printf("ft_memmove =\t%s\n", ft_memmove(dst4, src4, 0));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("memmove    =\t%s\n", memmove(dst5, src5, 1));
	printf("ft_memmove =\t%s\n", ft_memmove(dst5, src5, 1));
	printf("---------------------------\n");
	return (0);
}
