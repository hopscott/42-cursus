/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:19 by swillis           #+#    #+#             */
/*   Updated: 2021/11/23 19:15:27 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	isalpha(int c);

int	main()
{
	printf("********* ISALPHA **********\n");
	printf("---------------------------\n");
	printf("isalpha\t=\t\t%d\n", isalpha('A'));
	printf("ft_isalpha\t=\t%d\n", isalpha('A'));
	printf("---------------------------\n");
	printf("isalpha\t=\t\t%d\n", isalpha('a'));
	printf("ft_isalpha\t=\t%d\n", isalpha('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalpha\t=\t\t%d\n", isalpha('1'));
	printf("ft_isalpha\t=\t%d\n", isalpha('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalpha\t=\t\t%d\n", isalpha('?'));
	printf("ft_isalpha\t=\t%d\n", isalpha('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalpha\t=\t\t%d\n", isalpha('0'));
	printf("ft_isalpha\t=\t%d\n", isalpha('0'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalpha\t=\t\t%d\n", isalpha(' '));
	printf("ft_isalpha\t=\t%d\n", isalpha(' '));
	printf("---------------------------\n");
	return (0);
}
