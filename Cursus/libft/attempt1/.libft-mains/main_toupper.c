/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:19 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 16:51:46 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_toupper(int c);

int	main()
{
	printf("********* toupper **********\n");
	printf("---------------------------\n");
	printf("toupper\t=\t\t%c\n", toupper('A'));
	printf("ft_toupper\t=\t%c\n", ft_toupper('A'));
	printf("---------------------------\n");
	printf("toupper\t=\t\t%c\n", toupper('a'));
	printf("ft_toupper\t=\t%c\n", ft_toupper('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("toupper\t=\t\t%c\n", toupper('1'));
	printf("ft_toupper\t=\t%c\n", ft_toupper('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("toupper\t=\t\t%c\n", toupper('?'));
	printf("ft_toupper\t=\t%c\n", ft_toupper('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("toupper\t=\t\t%c\n", toupper('0'));
	printf("ft_toupper\t=\t%c\n", ft_toupper('0'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("toupper\t=\t\t%c\n", toupper(' '));
	printf("ft_toupper\t=\t%c\n", ft_toupper(' '));
	printf("---------------------------\n");
	return (0);
}
