/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/21 17:56:35 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////

int	stack_ascend(t_node **stack)
{
	t_node	*elem;
	int		val;

	if (*stack)
	{
		elem = *stack;
		val = elem->val;
		while (elem)
		{
			elem = elem->next;
			if (val > elem->val)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	stack_findMin(t_node **stack)
{
	t_node	*elem;
	int		min;

	elem = *stack;
	min = elem->val;
	while (elem)
	{
		if (elem->val < min)
			min = elem->val;
		elem = elem->next;
	}
	return (min);
}

int	stack_gotoMin(t_node **stack, char t)
{
	t_node	*elem;
	int		min;
	int		steps;
	int		size;

	steps = 0;
	elem = *stack;
	size = stack_size(stack);
	min = stack_findMin(stack);
	while ((size != 0) && (elem->val != min))
	{
		steps++;
		elem = elem->next;
	}
	if (steps < (size / 2))
		while ((*stack)->val != min)
		{
			if (t == 'a')
				op_ra(stack);
			else
				op_rb(stack);
		}
	else
		while ((*stack)->val != min)
		{
			if (t == 'a')
				op_rra(stack);
			else
				op_rrb(stack);
		}
	return (0);
}

//////////////////////////////////////////////////////////////////////

int	run_selectionSort(t_node **stack)
{
	t_node	**stack2;

	printf("============= START =============\n");
	stack_print(stack);
	printf("=================================\n");
	*stack2 = 0;
	while (stack_size(stack) != 0)
	{
		stack_gotoMin(stack, 'a');
		op_pb(stack, stack2);
	}
	while (stack_size(stack2) != 0)
		op_pa(stack, stack2);
	printf("============= END =============\n");
	stack_print(stack);
	printf("=================================\n");
	return (0);	
}

//////////////////////////////////////////////////////////////////////
/*
void	stack_sortpush(t_node **stack, t_node **stack2, int flag)
{
	t_node	*elem;
	t_node	*next;

	elem = *stack;
	next = elem->next;
	if (stack_size(stack) > 1)
	{
		if (flag && (elem->val < next->val))
			op_sa(stack);
		if (!flag && (elem->val > next->val))
			op_sa(stack);
		op_pb(stack, stack2);
	}
	op_pb(stack, stack2);
	stack_print(stack);
}

int run_mergeSort(t_node **stack)
{
	t_node	**stack2;
	
	// https://stackoverflow.com/questions/21897184/using-stacks-for-a-non-recursive-mergesort
	printf("============= START =============\n");
	stack_print(stack);
	printf("=================================\n");
	*stack2 = 0;
	while (!stack_ascend(stack))
	{
//		printf("============ STACK A ==================\n");
		while (stack_size(stack) > 0)
			stack_sortpush(stack, stack2, 1);
//		printf("============ STACK B ==================\n");
		while (stack_size(stack2) > 0)
			stack_sortpush(stack2, stack, 0);
	}
	printf("============= END =============\n");
	stack_print(stack);
	printf("=================================\n");
	return (0);
}
*/
//////////////////////////////////////////////////////////////////////

int	run_algo3(t_node **stack)
{
	t_node	*elem;

	elem = *stack;
	return (0);
}

//////////////////////////////////////////////////////////////////////

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
//		if (run_mergeSort(stack))
		if (run_selectionSort(stack))
			return (1);
	}
	return (0);
}
