/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:10:13 by swillis           #+#    #+#             */
/*   Updated: 2022/02/04 00:01:52 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_findmedian(t_node **stack)
{
	int	i;
	int	size;
	int	nb;

	size = stack_size(stack);
	nb = stack_findmin(stack);
	i = 1;
	while (i < size / 2)
	{
		nb = stack_findnextmin(stack, nb);
		i++;
	}
	return (nb);
}

int	stack_findnextmedian(t_node **stack)
{
	int	i;
	int	size;
	int	nb;

	size = stack_size(stack);
	nb = stack_findmin(stack);
	i = 1;
	while (i < size / 4)
	{
		nb = stack_findnextmin(stack, nb);
		i++;
	}
	return (nb);
}

int	stacka_pushmedian(t_node **st, t_node **st2, int med, int nmed)
{
	t_node	*top;
	int	size;
	int	push;

	push = 0;
	size = stack_size(st);
	while (push < (size / 2) )
	{
		top = *st;
		if (top->val >= med)
		{
			op_pb(st, st2);
			if (top->val > nmed)
				op_rrb(st2);
		}
		else
			op_ra(st);
		push++;
	}
	return (0);
}

int	run_algoquicksort(t_node **st, t_node **st2)
{
	int	med;
	int	nmed;

	while (stack_size(st) > 2)
	{
		med = stack_findmedian(st);
		nmed = stack_findnextmedian(st);
		stacka_pushmedian(st, st2, med, nmed);
	}
	run_algo3a(st);
	stackb_empty(st, st2);
	return (0);
}
