/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:10:13 by swillis           #+#    #+#             */
/*   Updated: 2022/01/28 16:13:03 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_algo3a(t_node **st)
{
	int		top;
	int		mid;
	int		bot;

	top = stack_findmin(st);
	mid = stack_findnextmin(st, top);
	bot = stack_findmax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sa(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sa(st);
	else if (s_pos(st, bot) < s_pos(st, mid) && s_pos(st, mid) < s_pos(st, top))
	{
		op_sa(st);
		op_rra(st);
	}
	else if (s_pos(st, bot) < s_pos(st, top) && s_pos(st, top) < s_pos(st, mid))
		op_ra(st);
	else if (s_pos(st, top) < s_pos(st, bot) && s_pos(st, bot) < s_pos(st, mid))
	{
		op_sa(st);
		op_ra(st);
	}
	else if (s_pos(st, mid) < s_pos(st, bot) && s_pos(st, bot) < s_pos(st, top))
		op_rra(st);
}

void	run_algo3b(t_node **st)
{
	int		top;
	int		mid;
	int		bot;

	bot = stack_findmin(st);
	mid = stack_findnextmin(st, bot);
	top = stack_findmax(st);
	if ((mid == bot) && (s_pos(st, bot) < s_pos(st, top)))
		op_sb(st);
	if ((s_pos(st, mid) < s_pos(st, top)) && (s_pos(st, top) < s_pos(st, bot)))
		op_sb(st);
	else if (s_pos(st, bot) < s_pos(st, mid) && s_pos(st, mid) < s_pos(st, top))
	{
		op_sb(st);
		op_rrb(st);
	}
	else if (s_pos(st, bot) < s_pos(st, top) && s_pos(st, top) < s_pos(st, mid))
		op_rb(st);
	else if (s_pos(st, top) < s_pos(st, bot) && s_pos(st, bot) < s_pos(st, mid))
	{
		op_sb(st);
		op_rb(st);
	}
	else if (s_pos(st, mid) < s_pos(st, bot) && s_pos(st, bot) < s_pos(st, top))
		op_rrb(st);
}

int	run_algo5(t_node **st, t_node **st2)
{
	stacka_gotonum(st, stack_findmin(st));
	op_pb(st, st2);
	stacka_gotonum(st, stack_findmin(st));
	op_pb(st, st2);
	run_algo3a(st);
	op_pa(st, st2);
	op_pa(st, st2);
	return (0);
}

int	run_algobins(t_node **st, t_node **st2)
{
	int	n;
	int	bins;
	int	binsize;

	bins = ft_sqrt(stack_size(st)) / 2;
	binsize = stack_size(st) / bins;
	n = 0;
	while (!stack_ascend(st) && (n <= bins))
	{
		stacka_pushbin(st, st2, bins, n);
		if (n == bins)
			binsize -= stack_size(st) % bins;
		if (n > 0)
			stacka_gotonum(st, bin_min(st, bins, binsize, n - 1));
		stackb_empty(st, st2);
		n++;
	}
	return (0);
}
