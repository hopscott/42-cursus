/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/21 18:58:39 by swillis          ###   ########.fr       */
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

int	stack_findNextMin(t_node **stack, int min)
{
	t_node	*elem;
	int		nmin;

	elem = *stack;
	if (elem->val == min)
		elem = elem->next;
	nmin = elem->val;
	while (elem)
	{
		if ((elem->val < nmin) && (elem->val != min))
			nmin = elem->val;
		elem = elem->next;
	}
	return (nmin);
}

int	stack_findMax(t_node **stack)
{
	t_node	*elem;
	int		max;

	elem = *stack;
	max = elem->val;
	while (elem)
	{
		if (elem->val > max)
			max = elem->val;
		elem = elem->next;
	}
	return (max);
}

int	s_pos(t_node **stack, int target)
{
	t_node	*elem;
	int		pos;

	elem = *stack;
	pos = 0;
	while (elem->val != target)
	{
		pos++;
		elem = elem->next;
	}
	return (pos);
}

int	stack_gotoNum(t_node **stack, int target, char t)
{
	t_node	*elem;
	int		steps;
	int		size;

	steps = 0;
	elem = *stack;
	size = stack_size(stack);
	while ((size != 0) && (elem->val != target))
	{
		steps++;
		elem = elem->next;
	}
	if (steps < (size / 2))
		while ((*stack)->val != target)
		{
			if (t == 'a')
				op_ra(stack);
			else
				op_rb(stack);
		}
	else
		while ((*stack)->val != target)
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
		stack_gotoNum(stack, stack_findMin(stack), 'a');
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

void	run_algo3a(t_node **st)
{
	int		top;
	int		mid;
	int		bot;

	top = stack_findMin(st);
	mid = stack_findNextMin(st, top);
	bot = stack_findMax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sa(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sa(st);
	else if ((s_pos(st, bot) < s_pos(st, mid)) && (s_pos(st, mid) < s_pos(st, top)))
	{
		op_sa(st);
		op_rra(st);
	}
	else if ((s_pos(st, bot) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, mid)))
		op_ra(st);
	else if ((s_pos(st, top) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, mid)))
	{
		op_sa(st);
		op_ra(st);
	}
	else if ((s_pos(st, mid) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, top)))
		op_rra(st);
}

//////////////////////////////////////////////////////////////////////

void	run_algo3b(t_node **st)
{
	int		top;
	int		mid;
	int		bot;

	top = stack_findMin(st);
	mid = stack_findNextMin(st, top);
	bot = stack_findMax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sb(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sb(st);
	else if ((s_pos(st, bot) < s_pos(st, mid)) && (s_pos(st, mid) < s_pos(st, top)))
	{
		op_sb(st);
		op_rrb(st);
	}
	else if ((s_pos(st, bot) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, mid)))
		op_rb(st);
	else if ((s_pos(st, top) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, mid)))
	{
		op_sb(st);
		op_rb(st);
	}
	else if ((s_pos(st, mid) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, top)))
		op_rrb(st);
}

//////////////////////////////////////////////////////////////////////

void	run_algo5(t_node **st)
{

	int		top;
	int		mid;
	int		bot;

	top = stack_findMin(st);
	mid = stack_findNextMin(st, top);
	bot = stack_findMax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sa(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sa(st);
	else if ((s_pos(st, bot) < s_pos(st, mid)) && (s_pos(st, mid) < s_pos(st, top)))
	{
		op_sa(st);
		op_rra(st);
	}
	else if ((s_pos(st, bot) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, mid)))
		op_ra(st);
	else if ((s_pos(st, top) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, mid)))
	{
		op_sa(st);
		op_ra(st);
	}
	else if ((s_pos(st, mid) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, top)))
		op_rra(st);
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
//		if (run_selectionSort(stack))

		printf("============= START =============\n");
		stack_print(stack);
		printf("=================================\n");

		printf("stack size: %d\n", stack_size(stack));
		if (stack_size(stack) <= 3)
			run_algo3a(stack);
		else if ((stack_size(stack) > 3) && (stack_size(stack) <= 5))
			run_algo5(stack);

		printf("============= END =============\n");
		stack_print(stack);
		printf("=================================\n");

	}
	return (0);
}
