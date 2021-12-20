/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 17:08:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int	main()
{
	unsigned char	str1[10] = "123456789";
	unsigned char	str2[10] = "123456789";
	unsigned char	str3[10] = "123456789";
	unsigned char	str4[10] = "123456789";
	unsigned char	str5[10] = "123456789";

	printf("********* strchr **********\n");
	printf("---------------------------\n");
	printf("strchr    =\t%s\n", strchr(str1, 'a'));
	printf("ft_strchr =\t%s\n", ft_strchr(str1, 'a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strchr    =\t%s\n", strchr(str2, '5'));
	printf("ft_strchr =\t%s\n", ft_strchr(str2, '5'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strchr    =\t%s\n", strchr(str3, '9'));
	printf("ft_strchr =\t%s\n", ft_strchr(str3, '9'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strchr    =\t%s\n", strchr(str4, '1'));
	printf("ft_strchr =\t%s\n", ft_strchr(str4, '1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strchr    =\t%s\n", strchr(str5, '~'));
	printf("ft_strchr =\t%s\n", ft_strchr(str5, '~'));
	printf("---------------------------\n");
	return (0);
}
