/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:13:31 by swillis           #+#    #+#             */
/*   Updated: 2022/01/19 14:39:34 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	atoi_check(char *str)
{
	int				i;
	int				sign;
	unsigned int	n;
	int				nb;

	sign = 1;
	i = 0;
	n = 0;
	while (str && str[i] && ft_isspace(str[i]))
		i++;
	if (str && str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			sign *= -1;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]) || (n > 2147483648))
			return (1);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (((sign == +1) && (n > 2147483647)) || ((sign == -1) && (n > 2147483648)))
		return (1);
	return (0);
}

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
	int	*array;
	int	i;

	i = 0;
	while (i++ < ac - 1)
		if (atoi_check(av[i]))
			return (0);
	array = malloc(sizeof(int) * i);
	if (!array)
		return (0);
	i = 0;
	while (i++ < ac - 1)
		array[i - 1] = ft_atoi(av[i]);
	if (check_array(array, ac - 1))
		return (0);
	return (array);
}

int	ft_puterror()
{
	ft_putstr_fd("Error\n", 1);
	return (-1);
}
