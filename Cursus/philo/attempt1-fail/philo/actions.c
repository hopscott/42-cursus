/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:42:00 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/21 15:51:52 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&philo->tlock);
	philo->state = THINKING;
	printf("%llu\tPhilo %d is thinking\n", timestamp(table), philo->seat);
	pthread_mutex_unlock(&philo->tlock);
}

int	fork_test(t_philo *philo)
{
	t_philo	*philo_left;
	t_philo	*philo_right;

	philo_left = philo->philo_left;
	philo_right = philo->philo_right;
	if (philo->state == HUNGRY) 
		if ((philo_left->state != EATING) && (philo_right->state != EATING))
			return (1);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	// pthread_mutex_lock(philo->fork_left);
	// pthread_mutex_lock(&philo->tlock);
	// philo->state = HUNGRY;
	// pthread_mutex_unlock(&philo->tlock);
	// while (!fork_test(philo))
	// 	continue ;
	// pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->tlock);
	philo->state = EATING;
	philo->timestamp_last_meal = timestamp(table);
	printf("%llu\tPhilo %d is eating\n", timestamp(table), philo->seat);
	pthread_mutex_unlock(&philo->tlock);
	usleep(table->time_to_eat);
	// pthread_mutex_unlock(philo->fork_left);
	// pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_lock(&philo->tlock);
	philo->times_eaten += 1;
	if (philo->times_eaten == table->number_of_times_each_philosopher_must_eat)
	{
		printf("%llu\tPhilo %d is full\n", timestamp(philo->table), philo->seat);
		philo->state = FULL;
	}
	pthread_mutex_unlock(&philo->tlock);
}

void	philo_sleep(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&philo->tlock);
	philo->state = SLEEPING;
	printf("%llu\tPhilo %d is sleeping\n", timestamp(table), philo->seat);
	pthread_mutex_unlock(&philo->tlock);
	usleep(table->time_to_sleep);
}
