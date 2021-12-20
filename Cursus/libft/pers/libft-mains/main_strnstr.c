/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 18:48:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main()
{
	unsigned char	str1[10] = "123456789";
	unsigned char	str2[10] = "123456789";
	unsigned char	str3[10] = "123456789";
	unsigned char	str4[10] = "123456789";
	unsigned char	str5[10] = "123456789";

	printf("********* strnstr **********\n");
	printf("---------------------------\n");
	//printf("strnstr    =\t%s\n", strnstr(str1, "a", 5));
	printf("ft_strnstr =\t%s\n", ft_strnstr(str1, "a", 5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("strnstr    =\t%s\n", strnstr(str2, "567", 9));
	printf("ft_strnstr =\t%s\n", ft_strnstr(str2, "567", 9));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("strnstr    =\t%s\n", strnstr(str3, "9", 9));
	printf("ft_strnstr =\t%s\n", ft_strnstr(str3, "9", 9));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("strnstr    =\t%s\n", strnstr(str4, "123", 9));
	printf("ft_strnstr =\t%s\n", ft_strnstr(str4, "123", 9));
	printf("---------------------------\n");
	printf("---------------------------\n");
	//printf("strnstr    =\t%s\n", strnstr(str5, "", 1));
	printf("ft_strnstr =\t%s\n", ft_strnstr(str5, "", 1));
	printf("---------------------------\n");
	return (0);
}
