/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/23 19:40:53 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c);

int	main()
{
	printf("********* ISASCII **********\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii('A'));
	printf("ft_isascii\t=\t%d\n", ft_isascii('A'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii('a'));
	printf("ft_isascii\t=\t%d\n", ft_isascii('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii('1'));
	printf("ft_isascii\t=\t%d\n", ft_isascii('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii('?'));
	printf("ft_isascii\t=\t%d\n", ft_isascii('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii(200));
	printf("ft_isascii\t=\t%d\n", ft_isascii(200));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii(-127));
	printf("ft_isascii\t=\t%d\n", ft_isascii(-127));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isascii\t=\t\t%d\n", isascii(127));
	printf("ft_isascii\t=\t%d\n", ft_isascii(127));
	printf("---------------------------\n");
	return (0);
}
