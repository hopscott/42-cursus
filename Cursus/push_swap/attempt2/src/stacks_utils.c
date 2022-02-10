/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:02:27 by swillis           #+#    #+#             */
/*   Updated: 2022/02/10 15:23:24 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*copy_node(t_node *elem)
{
	t_node	*new;

	new = new_node(elem->val, elem->bin);
	if (!new)
		return (0);
	return (new);
}

void	stack_swap(t_node **stack)
{
	t_node	*top;
	t_node	*n1;
	t_node	*n2;
	int		size;

	size = stack_size(stack);
	if (size > 1)
	{
		top = *stack;
		n1 = copy_node(top);
		if (!n1)
			return ;
		n2 = copy_node(top->next);
		if (!n2)
			return ;
		stack_pop(stack);
		stack_pop(stack);
		stack_push(stack, n1);
		stack_push(stack, n2);
	}
}

void	stack_rotate(t_node **stack)
{
	t_node	*top;
	t_node	*last;
	t_node	*cpy;
	int		size;

	size = stack_size(stack);
	if (size > 1)
	{
		top = *stack;
		cpy = copy_node(top);
		if (!cpy)
			return ;
		last = last_node(stack);
		last->next = cpy;
		cpy->prev = last;
		stack_pop(stack);
	}
}

void	stack_reverse(t_node **stack)
{
	t_node	*cpy;
	t_node	*elem;
	t_node	*last;
	int		size;

	size = stack_size(stack);
	if (size > 1)
	{
		last = last_node(stack);
		cpy = copy_node(last);
		if (!cpy)
			return ;
		elem = last->prev;
		elem->next = 0;
		stack_push(stack, cpy);
		free(last);
	}
}

int	stack_size(t_node **stack)
{
	int		i;
	t_node	*top;
	t_node	*elem;

	i = 0;
	top = *stack;
	if (top)
	{
		elem = top;
		i = 1;
		while (elem->next)
		{
			i++;
			elem = elem->next;
		}
	}
	return (i);
}
