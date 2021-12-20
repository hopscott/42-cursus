/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 17:11:28 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int	main()
{
	unsigned char	str1[10] = "123456789";
	unsigned char	str2[10] = "123456789";
	unsigned char	str3[10] = "123456789";
	unsigned char	str4[10] = "123456789";
	unsigned char	str5[10] = "123456789";

	printf("********* strrchr **********\n");
	printf("---------------------------\n");
	printf("strrchr    =\t%s\n", strrchr(str1, 'a'));
	printf("ft_strrchr =\t%s\n", ft_strrchr(str1, 'a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strrchr    =\t%s\n", strrchr(str2, '5'));
	printf("ft_strrchr =\t%s\n", ft_strrchr(str2, '5'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strrchr    =\t%s\n", strrchr(str3, '9'));
	printf("ft_strrchr =\t%s\n", ft_strrchr(str3, '9'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strrchr    =\t%s\n", strrchr(str4, '1'));
	printf("ft_strrchr =\t%s\n", ft_strrchr(str4, '1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strrchr    =\t%s\n", strrchr(str5, '~'));
	printf("ft_strrchr =\t%s\n", ft_strrchr(str5, '~'));
	printf("---------------------------\n");
	return (0);
}
