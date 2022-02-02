/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/02/02 23:31:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_algo(t_node **stack, t_node **stack2)
{
	int	size;

	size = stack_size(stack);
	if (stack_ascend(stack))
		return (0);
	else
	{
		if (size <= 3)
			run_algo3a(stack);
		else if ((size > 3) && (size <= 5))
			run_algo5(stack, stack2);
		else if (size < 50)
			run_algobins(stack, stack2);
		else
			run_algoquicksort(stack, stack2);
	}
	return (0);
}

int	main(int ac, char **av)
{	
	int		len;
	int		*array;
	t_node	**stack;
	t_node	**stack2;

	if (ac > 1)
	{
		len = arrlen(ac, av);
		array = parse_input(ac, av, len);
		if (check_array(array, len))
			return (ft_puterror());
		stack = stack_init(array, len);
		if (!stack)
			return (1);
		stack2 = malloc(sizeof(t_node *));
		if (!stack2)
			return (1);
		*stack2 = 0;
		run_algo(stack, stack2);
		stack_clear(stack);
		stack_clear(stack2);
		free(array);
	}
	return (0);
}
