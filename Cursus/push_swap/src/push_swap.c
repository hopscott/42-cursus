/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:44 by swillis           #+#    #+#             */
/*   Updated: 2022/01/26 18:57:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
		stack2 = malloc(sizeof(t_node*));
		if (!stack2)
			return (1);
		*stack2 = 0;

		printf("======= START =======\n");
		stack_print(stack);
		stack_print(stack2);
		printf("=====================\n");

		if (stack_size(stack) <= 3)
			run_algo3a(stack);
		else if ((stack_size(stack) > 3) && (stack_size(stack) <= 5))
			run_algo5(stack, stack2);
		else
			run_algo2byBin(stack, stack2);

		printf("======== END ========\n");
		stack_print(stack);
		stack_print(stack2);
		printf("=====================\n");

		free(stack);
		free(stack2);
		// need to run clean stack op on both too - free all elems;
	}
	return (0);
}
