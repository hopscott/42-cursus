/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:02:27 by swillis           #+#    #+#             */
/*   Updated: 2022/01/28 16:29:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_node **stack)
{
	t_node	*elem;
	t_node	*temp;

	elem = *stack;
	while (elem)
	{
		temp = elem->next;
		free(elem);
		elem = temp;
	}
	*stack = 0;
	free(stack);
}
