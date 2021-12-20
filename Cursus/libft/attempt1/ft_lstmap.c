/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:14 by swillis           #+#    #+#             */
/*   Updated: 2021/12/01 17:50:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*(*ptr)(void *);
	void	(*d)(void *);
	t_list	*nlst;
	t_list	**alst;

	ptr = f;
	d = del;
	nlst = ft_lstnew((*ptr)(lst->content));
	if (!lst || !nlst)
	{
		(*d)(nlst);
		return (0);
	}
	alst = &nlst;
	while (lst->next)
	{
		nlst = ft_lstnew((*ptr)(lst->content));
		if (!nlst)
		{
			(*d)(nlst);
			return (0);
		}
		ft_lstadd_back(alst, nlst);
	}
	return (nlst);
}
