/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:47 by swillis           #+#    #+#             */
/*   Updated: 2021/11/24 22:31:20 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size);

int	main()
{
	printf("********* calloc **********\n");
	printf("---------------------------\n");
	printf("calloc =\t%s\n", calloc(10, sizeof(char)));
	printf("ft_calloc =\t%s\n", ft_calloc(10, sizeof(char)));
	printf("---------------------------\n");
	return (0);
}
