/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:19 by swillis           #+#    #+#             */
/*   Updated: 2021/11/23 19:35:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c);

int	main()
{
	printf("********* ISALNUM **********\n");
	printf("---------------------------\n");
	printf("isalnum\t=\t\t%d\n", isalnum('A'));
	printf("ft_isalnum\t=\t%d\n", ft_isalnum('A'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalnum\t=\t\t%d\n", isalnum('a'));
	printf("ft_isalnum\t=\t%d\n", ft_isalnum('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalnum\t=\t\t%d\n", isalnum('1'));
	printf("ft_isalnum\t=\t%d\n", ft_isalnum('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalnum\t=\t\t%d\n", isalnum('?'));
	printf("ft_isalnum\t=\t%d\n", ft_isalnum('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalnum\t=\t\t%d\n", isalnum('0'));
	printf("ft_isalnum\t=\t%d\n", ft_isalnum('0'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isalnum\t=\t\t%d\n", isalnum(' '));
	printf("ft_isalnum\t=\t%d\n", ft_isalnum(' '));
	printf("---------------------------\n");
	return (0);
}
