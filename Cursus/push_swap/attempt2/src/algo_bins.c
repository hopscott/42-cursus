/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/02/09 21:07:05 by swillis          ###   ########.fr       */
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

int	stack_findbinmed(t_node **st, int n)
{
	t_node	*elem;
	int		*arr;
	int		nbin;
	int		i;
	int		tmp;

	nbin = stack_binleft(st, n);
	if (!nbin)
		return (-1);
	arr = malloc(sizeof(arr) * nbin);
	if (!arr)
		return (-1);
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
	while (i > 1)
	{
		i--;
		if (arr[i - 1] > arr[i])
		{
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
		}
	}
	i = arr[nbin / 2];
	free(arr);
	return (i);
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
		}
		i++;
	}
	return (arr);
}

int	binarray_findlower(int *arr, int len, int val)
{
	int	i;

	i = len - 1;
	while (arr && (i > 0))
	{
		ft_printf(">>> arr[%d] = %d >>> %d\n", i, arr[i], val);
		if (val > arr[i])
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
	int	val;

	nbin = stack_binleft(st2, n);
	ft_printf(">>> nbin = %d\n", nbin);
	if (nbin == 0)
		op_pb(st, st2);
	else if (nbin == 1)
	{
		if ((*st)->val > (*st2)->val)
		{
			op_pb(st, st2);
			op_sb(st2);
		}
		else
			op_pb(st, st2);
	}
	else
	{
		val = (*st)->val;
		arr = stack_binarray(st2, nbin, n);
		lower = binarray_findlower(arr, nbin, val);
		ft_printf(">>> lower = %d\n", lower);
		stackb_gotonum(st2, lower);
		op_pb(st, st2);
		free(arr);
	}
	ft_printf("============\n");
	stack_print(st);
	stack_print(st2);
	ft_printf("============\n");
}

void	stacka_pushbin(t_node **st, t_node **st2, int n)
{
	t_node	*elem;

	elem = stack_findnextbin(st, n);
	while (elem)
	{
		stacka_gotonum(st, elem->val);

		stacka_insertionbin(st, st2, n);

//	t_node	*top;
//	int		med;
//	med = stack_findbinmed(st, n);
//		op_pb(st, st2);
//		top = *st2;
//		if (top->val < med)
//			op_rb(st2);

		elem = stack_findnextbin(st, n);
	}
}

void	run_algobins(t_node **st, t_node **st2)
{
	int	bins;
	int	n;

	bins = stack_binning(st);
	n = 0;
	while (n < bins)
	{
		stacka_pushbin(st, st2, n);
		n++;
	}
	stackb_empty(st, st2);
}
