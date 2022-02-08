/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:01:18 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:01:28 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
