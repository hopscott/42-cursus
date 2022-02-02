/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:01:07 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:01:13 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
