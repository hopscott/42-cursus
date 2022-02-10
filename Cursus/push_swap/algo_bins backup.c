/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/02/10 16:42:09 by swillis          ###   ########.fr       */
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

int	*stack_binarray(t_node **st, int nbin, int n)
{
	t_node	*elem;
	int		*arr;
	int		i;
	int		tmp;

	arr = malloc(sizeof(arr) * nbin);
	if (!arr)
		return (0);
	i = 0;
	elem = *st;
	while (elem && (i < nbin))
	{
		if (elem->bin == n)
		{
			arr[i] = elem->val;
			i++;
		}
		elem = elem->next;
	}
	i = 0;
	while (i + 1 < nbin)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

int	binarray_findlower(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (arr && (i + 1 < len))
	{
		if (arr[i + 1] > val)
			return (arr[i]);
		i++;
	}
	return (arr[i]);
}


int	binarray_findupper(int *arr, int len, int val)
{
	int	i;

	i = len - 1;
	while (arr && (i > 0))
	{
		if (arr[i - 1] < val)
			return (arr[i]);
		i--;
	}
	return (arr[i]);
}

void	stacka_insertionbin(t_node **st, t_node **st2, int n)
{
	int	nbin;
	int	*arr;
	int	lower;
	int	upper;
	int	val;

	nbin = stack_binleft(st2, n);
	if (nbin == 0)
		op_pb(st, st2);
	else if (nbin == 1)
	{
		val = (*st2)->val;
		op_pb(st, st2);
		if ((*st2)->val > val)
			op_sb(st2);
	}
	else
	{
		val = (*st)->val;
		arr = stack_binarray(st2, nbin, n);
		if (!arr)
			return ;
		upper = binarray_findupper(arr, nbin, val); 
		lower = binarray_findlower(arr, nbin, val); 
		free(arr);
		if (val < lower)
			stackb_gotonum(st2, upper);
		else if ((lower < val) && (val < upper))
			stackb_gotonum(st2, lower);
		else if (upper < val)
			stackb_gotonum(st2, upper);
		op_pb(st, st2);
	}
}

void	stackb_insertionbin(t_node **st, t_node **st2, int n)
{
	int	nbin;
	int	*arr;
	int	lower;
	int	upper;
	int	val;

	nbin = stack_binleft(st, n);
	if (nbin == 0)
		op_pa(st, st2);
	else if (nbin == 1)
	{
		val = (*st)->val;
		op_pa(st, st2);
		if ((*st)->val > val)
			op_sa(st);
	}
	else
	{
		val = (*st2)->val;
		arr = stack_binarray(st, nbin, n);
		if (!arr)
			return ;
		upper = binarray_findupper(arr, nbin, val); 
		lower = binarray_findlower(arr, nbin, val); 
		free(arr);
		stacka_gotonum(st, lower);
		op_pa(st, st2);
		if (lower < val)
			op_sa(st);
	}
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

void	stacka_pushbinmedian(t_node **st, t_node **st2, int n)
{
	t_node	*elem;
	int	*arr;
	int	nbin;
	int	med;

	nbin = stack_binleft(st, n);
	arr = stack_binarray(st, nbin, n);
	if (!arr)
		return ;
	med = arr[nbin / 2];
	free(arr);
	elem = stack_findnextbin(st, n);
	while (elem)
	{
		stacka_gotonum(st, elem->val);
		op_pb(st, st2);
		if ((stack_size(st2) > 1) && ((*st2)->val < med))
			op_rb(st2);
		elem = stack_findnextbin(st, n);
	}
}

void	stackb_pushbin(t_node **st, t_node **st2, int n)
{
	t_node	*elem;

	elem = stack_findnextbin(st2, n);
	while (elem)
	{
		stackb_gotonum(st2, elem->val);
		stackb_insertionbin(st, st2, n);
		elem = stack_findnextbin(st2, n);
	}
}

void	stackb_empty(t_node **st, t_node **st2)
{
	while (stack_size(st2))
	{
		stackb_gotonum(st2, (stack_findmax(st2))->val);
		op_pa(st, st2);
	}
}

void	run_algobins(t_node **st, t_node **st2)
{
	int	bins;
	int	n;

	bins = stack_binning(st);
	n = bins - 1;
	while (n >= 0)
	{
		stacka_pushbinmedian(st, st2, n);
		n--;
	}
	n = 0;
	while (n < bins)
	{
		stackb_pushbin(st, st2, n);
		stacka_gotonum(st, (stack_findmin(st))->val);
		n++;
	}
}