/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:10:13 by swillis           #+#    #+#             */
/*   Updated: 2022/01/26 20:51:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	run_algo3a(t_node **st)
{
	int		top;
	int		mid;
	int		bot;

	top = stack_findMin(st);
	mid = stack_findNextMin(st, top);
	bot = stack_findMax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sa(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sa(st);
	else if ((s_pos(st, bot) < s_pos(st, mid)) && (s_pos(st, mid) < s_pos(st, top)))
	{
		op_sa(st);
		op_rra(st);
	}
	else if ((s_pos(st, bot) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, mid)))
		op_ra(st);
	else if ((s_pos(st, top) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, mid)))
	{
		op_sa(st);
		op_ra(st);
	}
	else if ((s_pos(st, mid) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, top)))
		op_rra(st);
}

void	run_algo3b(t_node **st)
{
	int		top;
	int		mid;
	int		bot;

	bot = stack_findMin(st);
	mid = stack_findNextMin(st, bot);
	top = stack_findMax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sb(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sb(st);
	else if ((s_pos(st, bot) < s_pos(st, mid)) && (s_pos(st, mid) < s_pos(st, top)))
	{
		op_sb(st);
		op_rrb(st);
	}
	else if ((s_pos(st, bot) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, mid)))
		op_rb(st);
	else if ((s_pos(st, top) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, mid)))
	{
		op_sb(st);
		op_rb(st);
	}
	else if ((s_pos(st, mid) < s_pos(st, bot)) && (s_pos(st, bot) < s_pos(st, top)))
		op_rrb(st);
}

int	run_algo5(t_node **st, t_node **st2)
{
	stackA_gotoNum(st, stack_findMin(st));
	op_pb(st, st2);
	stackA_gotoNum(st, stack_findMin(st));
	op_pb(st, st2);
	run_algo3a(st);
	op_pa(st, st2);
	op_pa(st, st2);
	return (0);
}

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

int	bin_max(t_node **stack, int bins, int binsize, int n)
{
	int	bin;
	int	i;
	int	max;

	max = stack_findMax(stack);
	bin = 0;
	while ((bin < n) && (bin <= bins))
	{
		i = 1;
		while (i < binsize)
		{
			max = stack_findNextMax(stack, max);
			i++;
		}
		bin++;
		max = stack_findNextMax(stack, max);
	}
	return (max);
}

int	bin_min(t_node **stack, int bins, int binsize, int n)
{
	int	bin;
	int	i;
	int	min;

	min = bin_max(stack, bins, binsize, n);
	i = 1;
	while (i < binsize)
	{
		min = stack_findNextMax(stack, min);
		i++;
	}
	return (min);
}

int	stackA_gotoNextBin(t_node **stack, int binmin, int binmax)
{
	t_node	*elem;
	int	fsteps;
	int	ftarget;
	int	bsteps;
	int	btarget;

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
	printf("ft: %d || bt: %d\n", ftarget, btarget);
	fsteps = s_steps(stack, ftarget);
	bsteps = s_steps(stack, btarget);
	if (fsteps <= bsteps)
		stackA_gotoNum(stack, ftarget);
	else
		stackA_gotoNum(stack, btarget);
	return (0);
}

int	stack_exists(t_node **stack, int n)
{
	t_node	*elem;

	elem = *stack;
	while (elem)
		if (elem->val == n)
			return (1);
		elem = elem->next;
	return (0);
}

int	run_algo2byBin(t_node **st, t_node **st2)
{
	int	n;
	int	bins;
	int	binsize;
	int	binmin;
	int	binmax;
	int	count;

	bins = ft_sqrt(stack_size(st)) / 2;
	binsize = stack_size(st);
	binsize /= bins;
	n = 0;
	while (!stack_ascend(st) && (n <= bins))
	{
		binmax = bin_max(st, bins, binsize, n);
		binmin = bin_min(st, bins, binsize, n);
		if (n == bins)
			binsize = stack_size(st) % bins;
		count = 0;
//		///////////////////////////////////////
		printf("%d/%d\n", n, bins);
		printf("bin = %d -> %d\n", binmin, binmax);
		printf("binsize / stacksize = %d/%d\n", binsize, stack_size(st));
		stack_print(st); 
		stack_print(st2);
//		///////////////////////////////////////
		while (stack_size(st) && (count < binsize))
		{
			stackA_gotoNextBin(st, binmin, binmax);
			op_pb(st, st2);
			count++;
		}
		if (n == bins)
			binsize = stack_size(st) / bins;
		if (n > 1)
			stackA_gotoNum(st, bin_min(st, bins, binsize, n - 1));
//		///////////////////////////////////////
		stack_print(st); 
		stack_print(st2);
//		///////////////////////////////////////
		while (stack_size(st2))
		{
			stackB_gotoNum(st2, stack_findMax(st2));
			op_pa(st, st2);
		}
		n++;
	}
	while (!stack_ascend(st))
		stackA_gotoNum(st, stack_findMin(st));
	return (0);
}

//		printf("i = %d/%d\n", i, binsize);
//		stack_print(st);
//		stack_print(st2);
