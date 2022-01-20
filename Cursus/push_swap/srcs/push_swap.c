/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/20 15:14:46 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	stack_sortpush(t_node **stack, t_node **stack2, int *ptr)
{
	t_node	*elem;
	t_node	*next;
	int		sets;

	sets = *ptr;
	elem = *stack;
	next = elem->next;
	if (stack_size(stack) > 1)
	{
		if (elem->val > next->val)
			op_sa(stack);
		op_pb(stack, stack2);
		sets--;
	}
	op_pb(stack, stack2);
	*ptr = sets;
	return (0);
}

int run_algo(t_node **stack)
{
	t_node	**stack2;
	int		*tracker;
	int		sets;

	// https://stackoverflow.com/questions/21897184/using-stacks-for-a-non-recursive-mergesort
	stack_print(stack);
	sets = stack_size(stack);
	printf("%d\n", sets);
	*tracker = sets;
	printf("%d\n", *tracker);
	while (*tracker > 1)
	{
		stack_print(stack);
		while (stack_size(stack) > 0)
			stack_sortpush(stack, stack2, tracker);
		while (stack_size(stack2) > 0)
			stack_sortpush(stack2, stack, tracker);
	}
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
		stack_print(stack);
	//	if (run_algo(stack))
	//		return (1);
	}
	return (0);
}
