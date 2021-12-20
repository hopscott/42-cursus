/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:14 by swillis           #+#    #+#             */
/*   Updated: 2021/12/03 15:21:45 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*first;

	if (!lst)
		return (0);
	elem = ft_lstnew((*f)(lst->content));
	if (!elem)
		return (0);
	first = elem;
	lst = lst->next;
	while (lst)
	{
		elem->next = ft_lstnew((*f)(lst->content));
		if (!elem->next)
		{
			ft_lstclear(&first, (*del));
			return (0);
		}
		elem = elem->next;
		lst = lst->next;
	}
	return (first);
}
