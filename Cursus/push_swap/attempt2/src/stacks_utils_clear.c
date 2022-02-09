/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:02:27 by swillis           #+#    #+#             */
/*   Updated: 2022/02/09 19:36:34 by swillis          ###   ########.fr       */
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

void	stack_print(t_node **stack)
{
	t_node	*elem;

	if (*stack)
	{
		elem = *stack;
		ft_printf("\nTOP\t%d\t[%d]\n", elem->val, elem->bin);
		elem = elem->next;
		while (elem)
		{
			ft_printf(">\t%d\t[%d]\n", elem->val, elem->bin);
			elem = elem->next;
		}
		ft_printf("BOT\t________\n\n");
	}
	else
	{
		ft_printf("\nTOP\t%c\n", 'X');
		ft_printf("BOT\t________\n\n");
	}
}
