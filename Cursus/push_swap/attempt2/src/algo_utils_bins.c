/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_bins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:43:16 by swillis           #+#    #+#             */
/*   Updated: 2022/02/08 18:35:38 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackb_empty(t_node **st, t_node **st2)
{
	while (stack_size(st2))
	{
		stackb_gotonum(st2, (stack_findmax(st2))->val);
		op_pa(st, st2);
	}
}
