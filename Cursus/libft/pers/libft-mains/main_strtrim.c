/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:04:52 by swillis           #+#    #+#             */
/*   Updated: 2021/11/25 13:40:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *s2);

int	main()
{
	printf("********* strtrim **********\n");
	printf("---------------------------\n");
	printf("ft_strtrim =\t|%s|\n", ft_strtrim(" abc ", " "));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strtrim =\t|%s|\n", ft_strtrim("  abc  ", " "));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strtrim =\t|%s|\n", ft_strtrim("+-abc+-", "+-"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strtrim =\t|%s|\n", ft_strtrim("++-+-abc-++-+-", "+-"));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("ft_strtrim =\t|%s|\n", ft_strtrim("", " "));
	printf("---------------------------\n");
	return (0);
}
