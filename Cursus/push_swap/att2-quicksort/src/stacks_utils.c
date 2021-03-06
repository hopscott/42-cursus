/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:02:27 by swillis           #+#    #+#             */
/*   Updated: 2022/01/25 17:02:33 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	stack_swap(t_node **stack)
{
	t_node	*elem;
	int		size;
	int		n1;
	int		n2;

	size = stack_size(stack);
	if (*stack && size >= 2)
	{
		elem = *stack;
		n2 = elem->val;
		elem = elem->next;
		n1 = elem->val;
		stack_pop(stack);
		stack_pop(stack);
		if (stack_push(stack, n2))
			return (1);
		if (stack_push(stack, n1))
			return (1);
	}
	return (0);
}

int	stack_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*new;
	int		size;

	size = stack_size(stack);
	if (*stack && size > 1)
	{
		first = *stack;
		new = new_node(first->val);
		if (!new)
			return (1);
		last = last_node(stack);
		last->next = new;
		stack_pop(stack);
		return (0);
	}
	else
		return (1);
}

int	stack_reverse(t_node **stack)
{
	t_node	*elem;
	t_node	*last;
	int		size;

	size = stack_size(stack);
	if (*stack && size > 1)
	{
		last = last_node(stack);
		if (stack_push(stack, last->val))
			return (1);
		elem = *stack;
		while (elem->next != last)
			elem = elem->next;
		elem->next = 0;
		free(last);
		return (0);
	}
	else
		return (1);
}

int	stack_size(t_node **stack)
{
	int		i;
	t_node	*elem;

	i = 0;
	if (*stack)
	{
		elem = *stack;
		i = 1;
		while (elem->next)
		{
			i++;
			elem = elem->next;
		}
	}
	return (i);
}

void	stack_print(t_node **stack)
{
	t_node	*elem;

	if (*stack)
	{
		elem = *stack;
		ft_printf("\nTOP\t%d\n", elem->val);
		elem = elem->next;
		while (elem)
		{
			ft_printf(">\t%d\n", elem->val);
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
