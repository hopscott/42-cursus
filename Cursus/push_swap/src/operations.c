/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:22:03 by swillis           #+#    #+#             */
/*   Updated: 2022/01/22 19:12:58 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	op_sa(t_node **stackA)
{
	if (stack_swap(stackA))
		return (1);
	ft_putstr("sa\n");
	return (0);
}

int	op_sb(t_node **stackB)
{
	if (stack_swap(stackB))
		return (1);
	ft_putstr("sb\n");
	return (0);
}

int	op_ss(t_node **stackA, t_node **stackB)
{
	if (stack_swap(stackA))
		return (1);
	if (stack_swap(stackB))
		return (1);
	ft_putstr("ss\n");
	return (0);
}

int	op_pa(t_node **stackA, t_node **stackB)
{
	t_node	*elem;
	int		n;

	if (*stackB)
	{
		elem = *stackB;
		n = elem->val;
		if (stack_push(stackA, n))
			return (1);
		stack_pop(stackB);
	}
	ft_putstr("pa\n");
	return (0);
}

int	op_pb(t_node **stackA, t_node **stackB)
{
	t_node	*elem;
	int		n;

	if (*stackA)
	{
		elem = *stackA;
		n = elem->val;
		if (stack_push(stackB, n))
			return (1);
		stack_pop(stackA);
	}
	ft_putstr("pb\n");
	return (0);
}

int	op_ra(t_node **stackA)
{
	if (stack_rotate(stackA))
		return (1);
	ft_putstr("ra\n");
	return (0);
}

int	op_rb(t_node **stackB)
{
	if (stack_rotate(stackB))
		return (1);
	ft_putstr("rb\n");
	return (0);
}

int	op_rr(t_node **stackA, t_node **stackB)
{
	if (stack_rotate(stackA))
		return (1);
	if (stack_rotate(stackB))
		return (1);
	ft_putstr("rr\n");
	return (0);
}

int	op_rra(t_node **stackA)
{
	if (stack_reverse(stackA))
		return (1);
	ft_putstr("rra\n");
	return (0);
}

int	op_rrb(t_node **stackB)
{
	if (stack_reverse(stackB))
		return (1);
	ft_putstr("rrb\n");
	return (0);
}

int	op_rrr(t_node **stackA, t_node **stackB)
{
	if (stack_reverse(stackA))
		return (1);
	if (stack_reverse(stackB))
		return (1);
	ft_putstr("rrr\n");
	return (0);
}
