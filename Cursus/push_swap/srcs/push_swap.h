/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:42 by swillis           #+#    #+#             */
/*   Updated: 2022/01/18 16:57:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int		val;
	struct	s_node	*next;
}	t_node;

void    ft_putstr(char *str);
int ft_isspace(char c);
int atoi_check(char *str);
int *parse_input(int ac, char **av);
int ft_puterror();

void    stack_push(t_node **stack, t_node *new);
t_node  **stack_init(int *array, int len);

#endif
