/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_bins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:43:16 by swillis           #+#    #+#             */
/*   Updated: 2022/02/01 15:08:05 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bin_max(t_node **stack, int bins, int binsize, int n)
{
	int	bin;
	int	i;
	int	max;

	max = stack_findmax(stack);
	bin = 0;
	while ((bin < n) && (bin <= bins))
	{
		i = 1;
		while (i < binsize)
		{
			max = stack_findnextmax(stack, max);
			i++;
		}
		bin++;
		max = stack_findnextmax(stack, max);
	}
	return (max);
}

int	bin_min(t_node **stack, int bins, int binsize, int n)
{
	int	i;
	int	min;

	min = bin_max(stack, bins, binsize, n);
	i = 1;
	while (i < binsize)
	{
		min = stack_findnextmax(stack, min);
		i++;
	}
	return (min);
}

int	stacka_gotonextbin(t_node **stack, int binmin, int binmax)
{
	t_node	*elem;
	int		fsteps;
	int		ftarget;
	int		bsteps;
	int		btarget;

	elem = *stack;
	while (elem && ((elem->val < binmin) || (elem->val > binmax)))
		elem = elem->next;
	ftarget = elem->val;
	while (elem)
	{
		if ((elem->val >= binmin) && (elem->val <= binmax))
			btarget = elem->val;
		elem = elem->next;
	}
	fsteps = s_steps(stack, ftarget);
	bsteps = s_steps(stack, btarget);
	if (fsteps <= bsteps)
		stacka_gotonum(stack, ftarget);
	else
		stacka_gotonum(stack, btarget);
	return (0);
}

int	stacka_pushbin(t_node **st, t_node **st2, int bins, int n)
{
	int	binsize;
	int	binmin;
	int	binmax;
	int	count;

	binsize = stack_size(st) / bins;
	binmax = bin_max(st, bins, binsize, n);
	if (n + 1 == bins)
		binsize += stack_size(st) % bins;
	binmin = bin_min(st, bins, binsize, n);
	count = 0;
	while (stack_size(st) && (count < binsize))
	{
		stacka_gotonextbin(st, binmin, binmax);
		op_pb(st, st2);
		count++;
	}
	return (0);
}

int	stackb_empty(t_node **st, t_node **st2)
{
	while (stack_size(st2))
	{
		stackb_gotonum(st2, stack_findmax(st2));
		op_pa(st, st2);
	}
	return (0);
}
