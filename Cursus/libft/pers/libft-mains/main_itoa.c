/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:00:30 by swillis           #+#    #+#             */
/*   Updated: 2021/11/26 16:17:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n);

int	main()
{
	printf("********* itoa **********\n");
	printf("---------------------------\n");
	printf("ft_itoa = %s\n", ft_itoa(1234));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_itoa = %s\n", ft_itoa(2147483647));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_itoa = %s\n", ft_itoa(-2147483648));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_itoa = %s\n", ft_itoa(0));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_itoa = %s\n", ft_itoa(-1234));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_itoa = %s\n", ft_itoa(42));
	printf("---------------------------\n");
	return (0);	
}
