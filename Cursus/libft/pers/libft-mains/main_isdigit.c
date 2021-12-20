/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:19 by swillis           #+#    #+#             */
/*   Updated: 2021/11/23 19:32:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c);

int	main()
{
	printf("********* ISDIGIT **********\n");
	printf("---------------------------\n");
	printf("isdigit\t=\t\t%d\n", isdigit('A'));
	printf("ft_isdigit\t=\t%d\n", ft_isdigit('A'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isdigit\t=\t\t%d\n", isdigit('a'));
	printf("ft_isdigit\t=\t%d\n", ft_isdigit('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isdigit\t=\t\t%d\n", isdigit('1'));
	printf("ft_isdigit\t=\t%d\n", ft_isdigit('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isdigit\t=\t\t%d\n", isdigit('?'));
	printf("ft_isdigit\t=\t%d\n", ft_isdigit('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isdigit\t=\t\t%d\n", isdigit('0'));
	printf("ft_isdigit\t=\t%d\n", ft_isdigit('0'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isdigit\t=\t\t%d\n", isdigit(' '));
	printf("ft_isdigit\t=\t%d\n", ft_isdigit(' '));
	printf("---------------------------\n");
	return (0);
}
