/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:25 by swillis           #+#    #+#             */
/*   Updated: 2022/07/12 16:28:00 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		is_alive;

	philo = (t_philo *)arg;
	is_alive = 1;
	if (philo->index % 2 != 0)
		is_alive = goto_eat(philo);
	while (is_alive)
	{
		is_alive = goto_sleep(philo);
		if (!is_alive)
			break ;
		is_alive = goto_think(philo);
		if (!is_alive)
			break ;
		is_alive = goto_eat(philo);
	}
	return (0);
}

void	*routine_reaper(void *arg)
{
	t_reaper	*reaper;
	int			i;

	reaper = (t_reaper *)arg;
	while ((reaper->fulls < reaper->n) && (reaper->souls < 1))
	{
		i = -1;
		while ((++i < reaper->n) && \
				((reaper->fulls < reaper->n) && (reaper->souls < 1)))
			check_soul(&reaper->vars->philo[i], reaper);
	}
	i = -1;
	while (++i < reaper->n)
	{
		state_change(&reaper->vars->philo[i], FULL, "");
	}
	return (0);
}

	/* ******************* PRINT END ******************************* */
	/* pthread_mutex_lock(&reaper->vars->printable);                 */
	/* printf("%llu END\n", timestamp_diff(reaper->vars->start));    */
	/* pthread_mutex_unlock(&reaper->vars->printable);               */
	/* ************************************************************* */
