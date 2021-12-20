/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:12:19 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 16:50:49 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c);

int	main()
{
	printf("********* tolower **********\n");
	printf("---------------------------\n");
	printf("tolower\t=\t\t%c\n", tolower('A'));
	printf("ft_tolower\t=\t%c\n", ft_tolower('A'));
	printf("---------------------------\n");
	printf("tolower\t=\t\t%c\n", tolower('a'));
	printf("ft_tolower\t=\t%c\n", ft_tolower('a'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("tolower\t=\t\t%c\n", tolower('1'));
	printf("ft_tolower\t=\t%c\n", ft_tolower('1'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("tolower\t=\t\t%c\n", tolower('?'));
	printf("ft_tolower\t=\t%c\n", ft_tolower('?'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("tolower\t=\t\t%c\n", tolower('0'));
	printf("ft_tolower\t=\t%c\n", ft_tolower('0'));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("tolower\t=\t\t%c\n", tolower(' '));
	printf("ft_tolower\t=\t%c\n", ft_tolower(' '));
	printf("---------------------------\n");
	return (0);
}
