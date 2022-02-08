/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:01:07 by swillis           #+#    #+#             */
/*   Updated: 2022/02/08 17:10:16 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_node **stackA)
{
	stack_reverse(stackA);
	ft_putstr("rra\n");
}

void	op_rrb(t_node **stackB)
{
	stack_reverse(stackB);
	ft_putstr("rrb\n");
}

void	op_rrr(t_node **stackA, t_node **stackB)
{
	stack_reverse(stackA);
	stack_reverse(stackB);
	ft_putstr("rrr\n");
}
