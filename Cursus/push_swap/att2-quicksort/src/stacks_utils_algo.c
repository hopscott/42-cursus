/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:14:53 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:15:28 by swillis          ###   ########.fr       */
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
		while (elem)
		{
			if (val > elem->val)
				return (0);
			val = elem->val;
			elem = elem->next;
		}
		return (1);
	}
	return (0);
}

int	stack_findmin(t_node **stack)
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

int	stack_findnextmin(t_node **stack, int min)
{
	t_node	*elem;
	int		nmin;

	elem = *stack;
	nmin = stack_findmax(stack);
	while (elem)
	{
		if ((elem->val < nmin) && (elem->val > min))
			nmin = elem->val;
		elem = elem->next;
	}
	return (nmin);
}

int	stack_findmax(t_node **stack)
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

int	stack_findnextmax(t_node **stack, int max)
{
	t_node	*elem;
	int		nmax;

	elem = *stack;
	nmax = stack_findmin(stack);
	while (elem)
	{
		if ((elem->val > nmax) && (elem->val < max))
			nmax = elem->val;
		elem = elem->next;
	}
	return (nmax);
}
