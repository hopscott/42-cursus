/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:04:36 by swillis           #+#    #+#             */
/*   Updated: 2022/01/25 20:44:48 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_ascend(t_node **stack)
{
	t_node	*elem;
	int		val;

	if (*stack)
	{
		elem = *stack;
		val = elem->val;
		while (elem->next)
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
		if ((elem->val < nmin) && (elem->val > min))
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
