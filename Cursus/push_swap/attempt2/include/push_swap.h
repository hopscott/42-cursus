/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:24:42 by swillis           #+#    #+#             */
/*   Updated: 2022/02/10 17:31:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				val;
	int				bin;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

int		ft_isspace(char c);
int		ft_isdigit(int c);
int		atoi_check(char *str);
int		ft_atoi(const char *str);
int		ft_puterror(void);
char	**ft_freetbl(char **tbl, int pos);
int		ft_wordcount(char const *str, char c);
int		ft_wordlen(char const *str, char c);
char	*ft_fillelem(char const *s, char c, int i, char *elm);
char	**ft_split(char const *s, char c);
int		arrclen(char **arr);
int		arrlen(int ac, char **av);
int		check_array(int *array, int size);
int		*parse_input(int ac, char **av, int len);
t_node	*new_node(int n, int bin);
t_node	*last_node(t_node **stack);
t_node	*copy_node(t_node *elem);
t_node	**stack_init(int *array, int len);
int		stack_size(t_node **stack);
void	stack_push(t_node **stack, t_node *new);
void	stack_pop(t_node **stack);
void	stack_swap(t_node **stack);
void	stack_rotate(t_node **stack);
void	stack_reverse(t_node **stack);
void	stack_print(t_node **stack);
int		stack_ascend(t_node **stack);
t_node	*stack_findmin(t_node **stack);
t_node	*stack_findnextmin(t_node **stack, int min);
t_node	*stack_findmax(t_node **stack);
t_node	*stack_findnextmax(t_node **stack, int max);
int		s_pos(t_node **stack, int target);
int		s_steps(t_node **stack, int target);
int		stacka_gotonum(t_node **stack, int target);
int		stackb_gotonum(t_node **stack, int target);
void	op_sa(t_node **stacka);
void	op_sb(t_node **stackb);
void	op_ss(t_node **stacka, t_node **stackb);
void	op_pa(t_node **stacka, t_node **stackb);
void	op_pb(t_node **stacka, t_node **stackb);
void	op_ra(t_node **stacka);
void	op_rb(t_node **stackb);
void	op_rr(t_node **stacka, t_node **stackb);
void	op_rra(t_node **stacka);
void	op_rrb(t_node **stackb);
void	op_rrr(t_node **stacka, t_node **stackb);
void	run_algo3a(t_node **st);
void	run_algo3b(t_node **st);
void	run_algo5(t_node **st, t_node **st2);
int		ft_sqrt(int nb);
void	stacka_pushbin(t_node **st, t_node **st2, int n);
void	stacka_pushbinmedian(t_node **st, t_node **st2, int n);
void	stackb_insertionbin(t_node **st, t_node **st2, int n);
void	stackb_pushbin(t_node **st, t_node **st2, int n);
void	run_algobins(t_node **st, t_node **st2);
t_node	*bin_nodes(t_node **stack, t_node *elem, int n, int binsize);
int		stack_binning(t_node **stack);
int		stack_median_binning(t_node **stack);
int		stack_binleft(t_node **st, int n);
t_node	*stack_findnextbin(t_node **st, int n);
int		*binarray_sort(int *arr, int nbin);
int		*stack_binarray(t_node **st, int nbin, int n);
int		binarray_findlower(int *arr, int len, int val);
int		binarray_findupper(int *arr, int len, int val);
void	stackb_insertpush(t_node **st, t_node **st2, int nbin, int n);
void	stack_clear(t_node **stack);

#endif
