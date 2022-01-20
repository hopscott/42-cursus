/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/20 15:50:24 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	stack_sortpush(t_node **stack, t_node **stack2, int sets)
{
	t_node	*elem;
	t_node	*next;

	elem = *stack;
	next = elem->next;
	if (stack_size(stack) > 1)
	{
		if (elem->val < next->val)
			op_sa(stack);
		op_pb(stack, stack2);
		sets--;
	}
	op_pb(stack, stack2);
	stack_print(stack);
	return (sets);
}

int run_algo(t_node **stack)
{
	t_node	**stack2;
	int		sets;
	
	// https://stackoverflow.com/questions/21897184/using-stacks-for-a-non-recursive-mergesort
	printf("============= START =============\n");
	stack_print(stack);
	printf("=================================\n");
	*stack2 = 0;
	sets = stack_size(stack);
	while (sets > 1)
	{
		printf("============ STACK A ==================\n");
		while (stack_size(stack) > 0)
			sets = stack_sortpush(stack, stack2, sets);
		printf("============ STACK B ==================\n");
		while (stack_size(stack2) > 0)
			sets = stack_sortpush(stack2, stack, sets);
	}
	printf("============= END =============\n");
	stack_print(stack);
	printf("=================================\n");
	return (0);
}

int	main(int ac, char **av)
{
	int		*array;
	t_node	**stack;

	if (ac > 1)
	{
		array = parse_input(ac, av);
		if (!array)
			return (ft_puterror());		
		stack = stack_init(array, ac - 1);
		if (!stack)
			return (1);
		if (run_algo(stack))
			return (1);
	}
	return (0);
}
