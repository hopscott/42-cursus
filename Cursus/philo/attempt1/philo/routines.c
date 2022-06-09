/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:25 by swillis           #+#    #+#             */
/*   Updated: 2022/06/09 18:03:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		is_alive;

	philo = (t_philo *)arg;
	is_alive = 1;
	while (is_alive)
	{
		is_alive = goto_eat(philo);
		if (!is_alive)
			break ;
		is_alive = goto_sleep(philo);
		if (!is_alive)
			break ;
		is_alive = goto_think(philo);
	}
	return (0);
}

void	*routine_kill(void *arg)
{
	t_reaper	*reaper;
	int			i;

	reaper = (t_reaper *)arg;
	while (reaper->souls < reaper->n)
	{
		i = -1;
		while ((++i < reaper->n) && (reaper->souls < reaper->n))
			reaper->souls += check_soul(&reaper->vars->philo[i]);
	}
	return (0);
}
