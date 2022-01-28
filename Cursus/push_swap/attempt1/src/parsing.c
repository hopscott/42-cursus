/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:13:31 by swillis           #+#    #+#             */
/*   Updated: 2022/01/28 15:53:45 by swillis          ###   ########.fr       */
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

int	arrclen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	arrlen(int ac, char **av)
{
	int		i;
	int		len;
	char	**arrc;

	i = 1;
	len = 0;
	while (i < ac)
	{
		arrc = ft_split(av[i], ' ');
		len += arrclen(arrc);
		i++;
	}
	return (len);
}

int	*parse_input(int ac, char **av, int len)
{
	int		i;
	int		j;
	int		x;
	int		*arri;
	char	**arrc;

	arri = malloc(sizeof(int) * len);
	if (!arri)
		return (0);
	i = 0;
	x = 1;
	while (x < ac)
	{
		j = 0;
		arrc = ft_split(av[x], ' ');
		while (j < arrclen(arrc))
		{
			if (atoi_check(arrc[j]))
				return (0);
			arri[i++] = ft_atoi(arrc[j++]);
		}
		x++;
	}
	return (arri);
}
