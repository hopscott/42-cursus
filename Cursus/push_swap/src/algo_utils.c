/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:08:38 by swillis           #+#    #+#             */
/*   Updated: 2022/01/25 17:08:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
