/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:25 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 11:15:04 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		is_alive;

	philo = (t_philo *)arg;
	is_alive = 1;
	if (philo->index % 2 == 0)
		usleep((philo->vars->time_to_eat / 2) * 1000);
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

void	*routine_reaper(void *arg)
{
	t_reaper	*reaper;
	int			i;

	reaper = (t_reaper *)arg;
	while ((reaper->fulls < reaper->vars->n) && (reaper->souls < 1))
	{
		i = -1;
		while ((++i < reaper->vars->n) && \
				((reaper->fulls < reaper->vars->n) && (reaper->souls < 1)))
			check_soul(&reaper->vars->philo[i], reaper);
	}
	i = -1;
	while (++i < reaper->vars->n)
	{
		pthread_mutex_lock(reaper->vars->philo[i].lock);
		reaper->vars->philo[i].is_alive = 0;
		pthread_mutex_unlock(reaper->vars->philo[i].lock);
	}
	return (0);
}

	/* ******************* PRINT END ******************************* */
	/* pthread_mutex_lock(&reaper->vars->printable);                 */
	/* printf("%llu END\n", timestamp_diff(reaper->vars->start));    */
	/* pthread_mutex_unlock(&reaper->vars->printable);               */
	/* ************************************************************* */
	/* Make odd/even imbalance so sleep t_2_eat / 2 = wait for forks */
	/* at the start so sure to grab instant vs. sleeping as too long */
	/* ************************************************************* */
	/* Add t_2_think ensure a minimum time							 */
	/* ************************************************************* */
	/* Odd/even forks swap ensure no potential deadlocks (helgrind)	 */
	/* ************************************************************* */
