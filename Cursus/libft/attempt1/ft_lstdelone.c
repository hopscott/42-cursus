/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:14 by swillis           #+#    #+#             */
/*   Updated: 2021/12/02 12:16:33 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	void	(*ptr)(void *);

	ptr = del;
	if (lst)
	{
		(*ptr)(lst->content);
		free(lst->content);
		lst->content = NULL;
	}
}
