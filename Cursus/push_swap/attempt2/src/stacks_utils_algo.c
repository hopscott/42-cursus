/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:14:53 by swillis           #+#    #+#             */
/*   Updated: 2022/02/09 19:41:13 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_ascend(t_node **stack)
{
	t_node	*top;
	t_node	*elem;
	int		val;

	top = *stack;
	if (top)
	{
		elem = top;
		while (elem->next)
		{
			val = elem->val;
			elem = elem->next;
			if (val > elem->val)
				return (0);
		}
		return (1);
	}
	return (0);
}

t_node	*stack_findmin(t_node **stack)
{
	t_node	*elem;
	t_node	*m;
	int		min;

	elem = *stack;
	m = elem;
	min = elem->val;
	while (elem)
	{
		if (elem->val < min)
		{
			m = elem;
			min = elem->val;
		}
		elem = elem->next;
	}
	return (m);
}

t_node	*stack_findnextmin(t_node **stack, int min)
{
	t_node	*elem;
	t_node	*m;
	int		nmin;

	elem = *stack;
	m = stack_findmax(stack);
	nmin = m->val;
	while (elem)
	{
		if ((elem->val < nmin) && (elem->val > min))
		{
			m = elem;
			nmin = elem->val;
		}
		elem = elem->next;
	}
	return (m);
}

t_node	*stack_findmax(t_node **stack)
{
	t_node	*elem;
	t_node	*m;
	int		max;

	elem = *stack;
	m = elem;
	max = elem->val;
	while (elem)
	{
		if (elem->val > max)
		{
			m = elem;
			max = elem->val;
		}
		elem = elem->next;
	}
	return (m);
}

t_node	*stack_findnextmax(t_node **stack, int max)
{
	t_node	*elem;
	t_node	*m;
	int		nmax;

	elem = *stack;
	m = stack_findmin(stack);
	nmax = m->val;
	while (elem)
	{
		if ((elem->val > nmax) && (elem->val < max))
		{
			m = elem;
			nmax = elem->val;
		}
		elem = elem->next;
	}
	return (m);
}
