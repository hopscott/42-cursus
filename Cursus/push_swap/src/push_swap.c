/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/22 19:14:31 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_findNextNextMin(t_node **stack, int m1, int m2)
{
	t_node	*elem;
	int		nmin;

	elem = *stack;
	if ((elem->val == m1) || (elem->val == m1))
		elem = elem->next;
	if ((elem->val == m1) || (elem->val == m1))
		elem = elem->next;
	nmin = elem->val;
	while (elem)
	{
		if ((elem->val < nmin) && (elem->val != m1) && (elem->val != m2))
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
	while (elem && (elem->val != target))
	{
		pos++;
		elem = elem->next;
	}
	return (pos);
}

int	s_steps(t_node **stack, int target)
{
	int		steps;
	int		size;

	size = stack_size(stack);
	steps = s_pos(stack, target);
	if (steps > ((size - 1) / 2))
		steps = size - steps;
	return (steps);
}

int	stackA_gotoNum(t_node **stack, int target)
{
	t_node	*elem;
	int		steps;
	int		size;

	steps = 0;
	elem = *stack;
	size = stack_size(stack);
	while ((size != 0) && (elem->val != target))
	{
		elem = elem->next;
		steps++;
	}
	if (steps <= (size / 2))
		while ((*stack)->val != target)
			op_ra(stack);
	else
		while ((*stack)->val != target)
			op_rra(stack);
	return (0);
}

int	stackB_gotoNum(t_node **stack, int target)
{
	t_node	*elem;
	int		steps;
	int		size;

	steps = 0;
	elem = *stack;
	size = stack_size(stack);
	while ((size != 0) && (elem->val != target))
	{
		elem = elem->next;
		steps++;
	}
	if (steps <= (size / 2))
		while ((*stack)->val != target)
			op_rb(stack);
	else
		while ((*stack)->val != target)
			op_rrb(stack);
	return (0);
}

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

	bot = stack_findMin(st);
	mid = stack_findNextMin(st, bot);
	top = stack_findMax(st);
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

int	run_algo5(t_node **st, t_node **st2)
{
	stackA_gotoNum(st, stack_findMin(st));
	op_pb(st, st2);
	stackA_gotoNum(st, stack_findMin(st));
	op_pb(st, st2);
	run_algo3a(st);
	op_pa(st, st2);
	op_pa(st, st2);
	return (0);
}

//////////////////////////////////////////////////////////////////////

int	run_algo3by3(t_node **st, t_node **st2)
{
	int	m1;
	int	m2;
	int	m3;
	int	i;
	int	arr[3];

	while (stack_size(st) > 3)
	{
		m1 = stack_findMin(st);
		m2 = stack_findNextMin(st, m1);
		m3 = stack_findNextNextMin(st, m1, m2);
		i = 0;
		while (i < 3)
		{
			if ((s_steps(st, m1) <= s_steps(st, m2)) && (s_steps(st, m1) <= s_steps(st, m3)))
			{
				arr[i] = m1;
				m1 = m2;
			}
			else if ((s_steps(st, m2) <= s_steps(st, m1)) && (s_steps(st, m2) <= s_steps(st, m3)))
			{
				arr[i] = m2;
				m2 = m1;
			}
			else if ((s_steps(st, m3) <= s_steps(st, m2)) && (s_steps(st, m3) <= s_steps(st, m1)))
			{
				arr[i] = m3;
				m3 = m1;
			}
			i++;
		}
		i = 0;
		while (i < 3)
		{
			stackA_gotoNum(st, stack_findMin(st));
			op_pb(st, st2);
			i++;
		}
		run_algo3b(st2);
	}
	run_algo3a(st);
	while (stack_size(st2) > 0)
		op_pa(st, st2);
	return (0);
}

//////////////////////////////////////////////////////////////////////

int	main(int ac, char **av)
{
	int		*array;
	t_node	**stack;
	t_node	**stack2;

	if (ac > 1)
	{
		array = parse_input(ac, av);
		if (!array)
			return (ft_puterror());		
		stack = stack_init(array, ac - 1);
		if (!stack)
			return (1);
		stack2 = malloc(sizeof(t_node*));
		if (!stack2)
			return (1);
		*stack2 = 0;

//		printf("============= START =============\n");
//		stack_print(stack);
//		stack_print(stack2);
//		printf("=================================\n");

//		printf("stack size: %d\n", stack_size(stack));

		if (stack_size(stack) <= 3)
			run_algo3a(stack);
		else if ((stack_size(stack) > 3) && (stack_size(stack) <= 5))
			run_algo5(stack, stack2);
		else
			run_algo3by3(stack, stack2);

//		printf("============= END =============\n");
//		stack_print(stack);
//		stack_print(stack2);
//		printf("=================================\n");

		free(stack);
		free(stack2);
		// need to run clean stack op on both too - free all elems;
	}
	return (0);
}
