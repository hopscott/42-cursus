/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/18 19:06:09 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*array;
	t_node	**stack;

	if (ac > 1)
	{
		array = parse_input(ac, av);
		if (!array)
			return (ft_puterror());		
	}
	stack = stack_init(array, ac - 1);
	stack_print(stack);
	stack_swap(stack);
	stack_print(stack);
	stack_rotate(stack);
	stack_print(stack);
	stack_reverse(stack);
	stack_print(stack);
	return (0);
}
