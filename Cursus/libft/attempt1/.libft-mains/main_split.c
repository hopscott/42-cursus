/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:41:45 by swillis           #+#    #+#             */
/*   Updated: 2021/11/25 14:53:54 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char const *s, char c);

int	main(int ac, char **av)
{
	int	i;
	char	**tbl;

	(void) ac;
	tbl = ft_split(av[1], av[2][0]);	
	i = 0;
	while (tbl[i])
	{
		printf("%d = %s\n", i, tbl[i]);
		i++;
	}
	return (0);
}
