/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:13:31 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:05:59 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	check_array(int *array, int size)
{
	int	i;
	int	j;

	if (!array)
		return (1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == array[j])
				if (i != j)
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_input(int ac, char **av)
{
	int		*array;
	char	*str;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (atoi_check(av[i]))
			return (0);
		i++;
	}
	array = malloc(sizeof(int) * (i - 1));
	if (!array)
		return (0);
	i = 0;
	while (i + 1 < ac)
	{
		str = av[i + 1];
		array[i] = ft_atoi(str);
		i++;
	}
	if (check_array(array, ac - 1))
		return (0);
	return (array);
}
