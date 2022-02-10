/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bins_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:22:00 by swillis           #+#    #+#             */
/*   Updated: 2022/02/10 17:22:19 by swillis          ###   ########.fr       */
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
	n--;
	binsize = stack_size(stack) % bins;
	elem = bin_nodes(stack, elem, n, binsize);
	return (bins);
}

int	stack_median_binning(t_node **stack)
{
	t_node	*elem;
	int		n;
	int		binsize;

	binsize = stack_size(stack);
	n = 0;
	elem = stack_findmax(stack);
	while (*stack && elem != stack_findmin(stack))
	{
		binsize = (binsize / 2) + (binsize % 2);
		elem = bin_nodes(stack, elem, n, binsize);
		n++;
	}
	elem->bin = n - 1;
	return (n);
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
	if (tsteps <= bsteps)
		return (top);
	else
		return (bot);
}
