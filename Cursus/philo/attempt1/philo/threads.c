/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:39:58 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/21 15:57:43 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// https://www.thegeekstuff.com/2012/05/c-mutex-examples/
void	*philosophise(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while ((philo->state != FULL) && (philo->state != DEAD))
	{
		// philo_eat(philo);
		// if ((philo->state == FULL) || (philo->state == DEAD))
		// 	break ;
		// philo_sleep(philo);
		// if ((philo->state == FULL) || (philo->state == DEAD))
		// 	break ;
		philo_think(philo);
	}
	return (ptr);
}

int	check_soul(t_philo *philo)
{
	t_table				*table;
	unsigned long long	t;

	table = philo->table;
	t = (unsigned long long)table->time_to_die;
	if ((philo->state != FULL) && (philo->state != DEAD))
	{
		if ((timestamp(table) - philo->timestamp_last_meal) > t)
		{
			pthread_mutex_lock(&philo->tlock);
			philo->state = DEAD;
			pthread_mutex_unlock(&philo->tlock);
			printf("%llu\tPhilo %d is dead\n", timestamp(table), philo->seat);
			pthread_mutex_lock(&table->tlock);
			while (table->queue->id != philo->seat)
				queue_rotate(&table->queue);
			ft_lstpop(&table->queue);
			pthread_mutex_unlock(&table->tlock);
			return (1);
		}
	}
	return (0);
}

void	*collect_souls(void *ptr)
{
	t_reaper	*reaper;
	t_table		*table;
	t_philo		*philo;
	int			i;

	reaper = (t_reaper *)ptr;
	table = reaper->table;
	while (reaper->souls != table->number_of_philosophers)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			philo = &table->philos[i];
			reaper->souls += check_soul(philo);
			i++;
		}
	}
	return (ptr);
}
