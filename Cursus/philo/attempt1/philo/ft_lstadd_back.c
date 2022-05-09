/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:14 by swillis           #+#    #+#             */
/*   Updated: 2021/12/06 16:28:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

void	ft_lstpop(t_list **lst)
{
	t_list	*elem;
	t_list	*next;

	if (*lst)
	{
		elem = *lst;
		next = elem->next;
		free(elem);
		*lst = next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	queue_rotate(t_list **lst)
{
	t_list	*elem;
	t_list	*new;
	int		id;

	elem = *lst;
	id = elem->id;
	new = ft_lstnew(id);
	ft_lstadd_back(lst, new);
	ft_lstpop(lst);
}
