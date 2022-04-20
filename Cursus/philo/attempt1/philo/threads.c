/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:39:58 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/20 17:37:18 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->tlock);
	if (philo->state == DEAD)
		return (1);
	pthread_mutex_unlock(&philo->tlock);
	return (0);
}

// https://www.thegeekstuff.com/2012/05/c-mutex-examples/
void	*philosophise(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (is_philo_dead(philo))
			break ;
		philo_think(philo);
		if (is_philo_dead(philo))
			break ;
		philo_eat(philo);
		if (is_philo_dead(philo))
			break ;
		philo_sleep(philo);
		if (is_philo_dead(philo))
			break ;
	}
	philo_dies(philo);
	return (ptr);
}

int	check_soul(t_philo *philo)
{
	t_table	*table;
	int	t;

	table = philo->table;
	pthread_mutex_lock(&table->tlock);
	t = table->time_to_die;
	pthread_mutex_unlock(&table->tlock);
	pthread_mutex_lock(&philo->tlock);
	if (philo->time_since_last_eaten > t)
	{
		if (philo->state != DEAD)
		{
			philo->state = DEAD;
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->tlock);
	return (0);
}

void	*collect_souls(void *ptr)
{
	t_reaper	*reaper;
	t_table		*table;
	t_philo		*philo;
	int			i;
	int			n;

	reaper = (t_reaper *)ptr;
	table = reaper->table;
	pthread_mutex_lock(&table->tlock);
	n = table->number_of_philosophers;
	pthread_mutex_unlock(&table->tlock);
	while (1)
	{
		i = 0;
		while (i < n)
		{
			pthread_mutex_lock(&reaper->tlock);
			philo = &table->philos[i];
			reaper->souls += check_soul(philo);
			pthread_mutex_unlock(&reaper->tlock);
			i++;
		}
		pthread_mutex_lock(&reaper->tlock);
		if (reaper->souls == n)
			break ;
		pthread_mutex_unlock(&reaper->tlock);
	}
	return (ptr);
}
