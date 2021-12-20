/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 14:34:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n);

int	main()
{
	unsigned char	str1[10] = "123456789";
	unsigned char	str2[10] = "123456789";
	unsigned char	str3[10] = "123456789";
	unsigned char	str4[10] = "123456789";
	unsigned char	str5[10] = "123456789";

	printf("********* bzero **********\n");
	printf("---------------------------\n");
	//bzero(str1, 5);
	ft_bzero(str1, 5);
	printf("%s\n", str1);
	printf("---------------------------\n");
	printf("---------------------------\n");
	//bzero(str2, 1);
	ft_bzero(str2, 1);
	printf("%s\n", str2);
	printf("---------------------------\n");
	printf("---------------------------\n");
	//bzero(str3, 8);
	ft_bzero(str3, 8);
	printf("%s\n", str3);
	printf("---------------------------\n");
	printf("---------------------------\n");
	//bzero(str4, 0);
	ft_bzero(str4, 0);
	printf("%s\n", str4);
	printf("---------------------------\n");
	printf("---------------------------\n");
	//bzero(str5, 10);
	ft_bzero(str5, 10);
	printf("%s\n", str5);
	printf("---------------------------\n");
	return (0);
}
