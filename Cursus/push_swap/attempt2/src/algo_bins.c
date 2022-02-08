/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/02/08 18:47:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*bin_nodes(t_node **stack, t_node *elem, int n, int binsize)
{
	int	i;

	i = 0;
	while (elem && (i < binsize))
	{
		elem->bin = n;
		i++;
		elem = stack_findnextmax(stack, elem->val);
	}
	return (elem);
}

int	stack_binning(t_node **stack)
{
	t_node	*elem;
	int		n;
	int		bins;
	int		binsize;

	bins = ft_sqrt(stack_size(stack)) / 2;
	binsize = stack_size(stack) / bins;
	n = 0;
	elem = stack_findmax(stack);
	while (*stack && n < bins)
	{
		elem = bin_nodes(stack, elem, n, binsize);
		n++;
	}
	binsize = stack_size(stack) % bins;
	elem = bin_nodes(stack, elem, n, binsize);
	return (bins);
}

int	stack_binleft(t_node **st, int n)
{
	t_node	*elem;
	int		i;

	elem = *st;
	i = 0;
	while (elem)
	{
		if (elem->bin == n)
			i++;
		elem = elem->next;
	}
	return (i);
}
	
t_node	*stack_findnextbin(t_node **st, int n)
{
	t_node	*top;
	t_node	*bot;
	int		tsteps;
	int		bsteps;

	if (!stack_binleft(st, n))
		return (0);
	top = *st;
	bot = last_node(st);
	tsteps = 0;
	while (top && (top->bin != n))
	{
		top = top->next;
		tsteps++;
	}
	bsteps = 0;
	while (bot && (bot->bin != n))
	{
		bot = bot->prev;
		bsteps++;
	}
	if (tsteps < bsteps)
		return (top);
	else 
		return (bot);
}

void	stacka_pushbin(t_node **st, t_node **st2, int n)
{
	t_node	*elem;

	elem = stack_findnextbin(st, n);
	while (elem)
	{
		stacka_gotonum(st, elem->val);
		op_pb(st, st2);
		elem = stack_findnextbin(st, n);
	}
}

int	run_algobins(t_node **st, t_node **st2)
{
	int	bins;
	int	n;

	bins = stack_binning(st);
	n = 0;
	while (n <= bins)
	{
		stacka_pushbin(st, st2, n);
		n++;
	}
	stackb_empty(st, st2);
	return (0);
}
