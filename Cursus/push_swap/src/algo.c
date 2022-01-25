/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:10:13 by swillis           #+#    #+#             */
/*   Updated: 2022/01/25 20:42:31 by swillis          ###   ########.fr       */
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
		i = 2;
		tot = i * i;
		while ((tot <= nb) && (i <= nb / 2) && (i <= 46341))
		{
			tot = i * i;
			if (tot == nb)
				return (i);
			i++;
		}
		return (i);
	}
	return (0);
}

int	run_algo2byBin(t_node **st, t_node **st2)
{
	int	i;
	int	bins;
	int	binsize;
	int start;
	int next;

	bins = ft_sqrt(stack_size(st)) / 2;
	binsize = stack_size(st);
	if (bins)
		binsize /= bins;
	printf("xxx = %d\n", binsize);
	start = stack_findMin(st);
	while (!stack_ascend(st))
	{
		i = 0;
		printf("i = %d/%d\n", i, binsize);
		stack_print(st);
		stack_print(st2);
		while (stack_size(st) && (i < binsize))
		{
			printf("i = %d/%d\n", i, binsize);
			stack_print(st);
			stack_print(st2);
			if (stack_size(st) > 1)
			{
				next = stack_findNextMin(st, start);
				if (s_steps(st, start) <= s_steps(st, next))
				{
					stackA_gotoNum(st, start);
					op_pb(st, st2);
					stackA_gotoNum(st, next);
					op_pb(st, st2);
				}
				else if (s_steps(st, next) <= s_steps(st, start))
				{
					stackA_gotoNum(st, next);
					op_pb(st, st2);
					stackA_gotoNum(st, start);
					op_pb(st, st2);
				}
				if (stack_size(st) != 0)
				start = stack_findMin(st);
			}
			else
				op_pb(st, st2);
			i += 2;
		}
		start = stack_findMin(st);
		while (stack_size(st2) > 0)
		{
			if (stack_size(st2) > 1)
				stackB_gotoNum(st2, stack_findMax(st2));
			op_pa(st, st2);
		}
	}
	printf("END\n");
	return (0);
}

//			printf("i = %d/%d\n", i, binsize);
//			stack_print(st);
//			stack_print(st2);
