/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:42 by swillis           #+#    #+#             */
/*   Updated: 2022/01/27 15:32:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}					t_node;

int		ft_isspace(char c);
int		ft_isdigit(int c);
int		atoi_check(char *str);
int		ft_atoi(const char *str);
int		ft_puterror(void);
int		*parse_input(int ac, char **av);
t_node	*new_node(int n);
t_node	*last_node(t_node **stack);
t_node	**stack_init(int *array, int len);
int		stack_size(t_node **stack);
int		stack_push(t_node **stack, int n);
void	stack_pop(t_node **stack);
int		stack_swap(t_node **stack);
int		stack_rotate(t_node **stack);
int		stack_reverse(t_node **stack);
void	stack_print(t_node **stack);
int		stack_ascend(t_node **stack);
int		stack_findmin(t_node **stack);
int		stack_findnextmin(t_node **stack, int min);
int		stack_findmax(t_node **stack);
int		stack_findnextmax(t_node **stack, int max);
int		s_pos(t_node **stack, int target);
int		s_steps(t_node **stack, int target);
int		stacka_gotonum(t_node **stack, int target);
int		stackb_gotonum(t_node **stack, int target);
int		op_sa(t_node **stacka);
int		op_sb(t_node **stackb);
int		op_ss(t_node **stacka, t_node **stackb);
int		op_pa(t_node **stacka, t_node **stackb);
int		op_pb(t_node **stacka, t_node **stackb);
int		op_ra(t_node **stacka);
int		op_rb(t_node **stackb);
int		op_rr(t_node **stacka, t_node **stackb);
int		op_rra(t_node **stacka);
int		op_rrb(t_node **stackb);
int		op_rrr(t_node **stacka, t_node **stackb);
void	run_algo3a(t_node **st);
void	run_algo3b(t_node **st);
int		run_algo5(t_node **st, t_node **st2);
int		run_algobins(t_node **st, t_node **st2);

#endif
