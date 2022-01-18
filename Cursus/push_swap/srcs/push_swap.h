/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:42 by swillis           #+#    #+#             */
/*   Updated: 2022/01/18 18:45:37 by swillis          ###   ########.fr       */
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

int ft_isspace(char c);
int atoi_check(char *str);
int *parse_input(int ac, char **av);
int ft_puterror();

t_node  *new_node(int n);
t_node  *last_node(t_node **stack);
t_node  **stack_init(int *array, int len);
int stack_size(t_node **stack);
void    stack_push(t_node **stack, int n);
void    stack_pop(t_node **stack);
void    stack_swap(t_node **stack);
void    stack_rotate(t_node **stack);
void    stack_print(t_node **stack);

#endif
