/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bins_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:04:55 by swillis           #+#    #+#             */
/*   Updated: 2022/02/10 17:30:58 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*binarray_sort(int *arr, int nbin)
{
	int	i;
	int	tmp;

	i = 0;
	while (i + 1 < nbin)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

int	*stack_binarray(t_node **st, int nbin, int n)
{
	t_node	*elem;
	int		*arr;
	int		i;

	arr = malloc(sizeof(arr) * nbin);
	if (!arr)
		return (0);
	i = 0;
	elem = *st;
	while (elem && (i < nbin))
	{
		if (elem->bin == n)
		{
			arr[i] = elem->val;
			i++;
		}
		elem = elem->next;
	}
	arr = binarray_sort(arr, nbin);
	return (arr);
}

int	binarray_findlower(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (arr && (i + 1 < len))
	{
		if (arr[i + 1] > val)
			return (arr[i]);
		i++;
	}
	return (arr[i]);
}

int	binarray_findupper(int *arr, int len, int val)
{
	int	i;

	i = len - 1;
	while (arr && (i > 0))
	{
		if (arr[i - 1] < val)
			return (arr[i]);
		i--;
	}
	return (arr[i]);
}

void	stackb_insertpush(t_node **st, t_node **st2, int nbin, int n)
{
	int	*arr;
	int	lower;
	int	upper;
	int	val;

	val = (*st2)->val;
	arr = stack_binarray(st, nbin, n);
	if (!arr)
		return ;
	upper = binarray_findupper(arr, nbin, val);
	lower = binarray_findlower(arr, nbin, val);
	free(arr);
	stacka_gotonum(st, lower);
	op_pa(st, st2);
	if (lower < val)
		op_sa(st);
}
