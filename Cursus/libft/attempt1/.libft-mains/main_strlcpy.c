/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 16:30:33 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size);

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

	printf("********* strlcpy **********\n");
	printf("---------------------------\n");
	printf("strlcpy    =\t%d\n", strlcpy(dst1, src1, sizeof(dst1)));
	//printf("ft_strlcpy =\t%ld\n", ft_strlcpy(dst1, src1, 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	return (0);
}
