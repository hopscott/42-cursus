/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/23 20:04:29 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int	main()
{
	printf("********* strlen **********\n");
	printf("---------------------------\n");
	printf("strlen\t\t=\t%lu\n", strlen("123456789"));
	printf("ft_strlen\t=\t%lu\n", ft_strlen("123456789"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strlen\t\t=\t%lu\n", strlen(""));
	printf("ft_strlen\t=\t%lu\n", ft_strlen(""));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strlen\t\t=\t%lu\n", strlen(" "));
	printf("ft_strlen\t=\t%lu\n", ft_strlen(" "));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strlen\t\t=\t%lu\n", strlen("abc\tdef"));
	printf("ft_strlen\t=\t%lu\n", ft_strlen("abc\tdef"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strlen\t\t=\t%lu\n", strlen("123\n456\t"));
	printf("ft_strlen\t=\t%lu\n", ft_strlen("123\n456\t"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("strlen\t\t=\t%lu\n", strlen("\n"));
	printf("ft_strlen\t=\t%lu\n", ft_strlen("\n"));
	printf("---------------------------\n");
	return (0);
}
