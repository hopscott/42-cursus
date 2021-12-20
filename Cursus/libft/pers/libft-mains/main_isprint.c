/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/23 19:43:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c);

int	main()
{
	printf("********* isprint **********\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint('A'));
	printf("ft_isprint\t=\t%d\n", ft_isprint('A'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint('a'));
	printf("ft_isprint\t=\t%d\n", ft_isprint('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint('1'));
	printf("ft_isprint\t=\t%d\n", ft_isprint('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint('?'));
	printf("ft_isprint\t=\t%d\n", ft_isprint('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint(200));
	printf("ft_isprint\t=\t%d\n", ft_isprint(200));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint(-127));
	printf("ft_isprint\t=\t%d\n", ft_isprint(-127));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint(127));
	printf("ft_isprint\t=\t%d\n", ft_isprint(127));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("isprint\t=\t\t%d\n", isprint(' '));
	printf("ft_isprint\t=\t%d\n", ft_isprint(' '));
	printf("---------------------------\n");
	return (0);
}
