/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:57:03 by swillis           #+#    #+#             */
/*   Updated: 2022/01/18 16:58:13 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_node	*new_node(int n)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (0);
	elem->val = n;
	elem->next = 0;
	return (elem);
}

void	stack_push(t_node **stack, t_node *new)
{
	if (*stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
	else if (new)
		*stack = new;
}

t_node	**stack_init(int *array, int len)
{
	int	i;
	t_node	**stack;
	t_node	*elem;

	i = len - 1;
	elem = new_node(array[i]);
	*stack = elem;
	while (i >= 0)
	{
		elem = new_node(array[i]);
		stack_push(stack, elem);
		i--;
	}
	return (stack);
}
