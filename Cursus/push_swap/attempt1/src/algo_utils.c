/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:08:38 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 14:59:11 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;
	int	tot;

	if (nb == 1)
		return (1);
	if (nb >= 4)
	{
		i = 1;
		tot = i * i;
		while ((tot < nb) && (i <= nb / 2) && (i <= 46341))
		{
			i++;
			tot = i * i;
		}
		return (i);
	}
	return (0);
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

int	stacka_gotonum(t_node **stack, int target)
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

int	stackb_gotonum(t_node **stack, int target)
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
