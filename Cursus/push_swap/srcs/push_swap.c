/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/18 15:27:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
		
void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

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
		if (!ft_isdigit(str[i]))
			return (1);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (((sign == +1) && (n > INT_MAX)) || ((sign == -1) && (n > -INT_MIN)))
		return (1);
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
	i = 0;
	while (i++ < ac - 1)
		array[i - 1] = ft_atoi(av[i]);
	return (array);
}

int	ft_puterror()
{
	ft_putstr("Error\n");
	return (-1);
}

int	main(int ac, char **av)
{
	int	*array;

	if (ac > 1)
	{
		array = parse_input(ac, av);
		if (!array)
			return (ft_puterror());		
	}
	while (ac-- > 1)
		printf("array[%d] = %d\n", ac - 1, array[ac - 1]);
	return (0);
}
