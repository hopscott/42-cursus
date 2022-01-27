/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:57:03 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:14:31 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

t_node	*last_node(t_node **stack)
{
	t_node	*elem;

	if (*stack)
	{
		elem = *stack;
		while (elem->next)
			elem = elem->next;
		return (elem);
	}
	else
		return (0);
}

int	stack_push(t_node **stack, int n)
{
	t_node	*new;

	new = new_node(n);
	if (!new)
		return (1);
	if (*stack)
	{
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
	return (0);
}

void	stack_pop(t_node **stack)
{
	t_node	*temp;

	if (*stack)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

t_node	**stack_init(int *array, int len)
{
	int		i;
	t_node	**stack;

	i = len - 1;
	if (len > 1)
	{
		stack = malloc(sizeof(t_node *));
		if (!stack)
			return (0);
		*stack = 0;
		while (i >= 0)
		{
			if (stack_push(stack, array[i]))
				return (0);
			i--;
		}
		return (stack);
	}
	else
		return (0);
}
