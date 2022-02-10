/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:04:08 by swillis           #+#    #+#             */
/*   Updated: 2022/02/10 17:34:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		*arr;
	int		nbin;
	int		med;

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

void	stackb_insertionbin(t_node **st, t_node **st2, int n)
{
	int	nbin;
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
		stackb_insertpush(st, st2, nbin, n);
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
	stacka_gotonum(st, (stack_findmin(st))->val);
}
