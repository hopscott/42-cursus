/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:34:54 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_algo(t_node **stack, t_node **stack2)
{
	int	size;

	size = stack_size(stack);
	if (size <= 3)
		run_algo3a(stack);
	else if ((size > 3) && (size <= 5))
		run_algo5(stack, stack2);
	else
		run_algobins(stack, stack2);
	return (0);
}

int	main(int ac, char **av)
{
	int		*array;
	t_node	**stack;
	t_node	**stack2;

	if (ac > 1)
	{
		array = parse_input(ac, av);
		if (!array)
			return (ft_puterror());
		stack = stack_init(array, ac - 1);
		if (!stack)
			return (1);
		stack2 = malloc(sizeof(t_node *));
		if (!stack2)
			return (1);
		*stack2 = 0;
		run_algo(stack, stack2);
		free(stack);
		free(stack2);
	}
	return (0);
}
//		printf("======= START =======\n");
//		stack_print(stack);
//		stack_print(stack2);
//		printf("=====================\n");
//		printf("======== END ========\n");
//		stack_print(stack);
//		stack_print(stack2);
//		printf("=====================\n");
// need to run clean stack op on both too - free all elems;
