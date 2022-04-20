/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:42:00 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/20 17:46:05 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&philo->tlock);
	philo->state = THINKING;
	pthread_mutex_lock(&table->tlock);
	printf("%llu\tPhilo %d is thinking\n", timestamp(table), philo->seat);
	pthread_mutex_unlock(&table->tlock);
	pthread_mutex_unlock(&philo->tlock);
}

int	fork_test(t_philo *philo)
{
	t_philo	*philo_left;
	t_philo	*philo_right;

	philo_left = philo->philo_left;
	philo_right = philo->philo_right;
	pthread_mutex_lock(&philo_left->tlock);
	pthread_mutex_lock(&philo_right->tlock);
	if (philo->state == HUNGRY) 
		if ((philo_left->state != EATING) && (philo_right->state != EATING))
			return (1);
	pthread_mutex_unlock(&philo_left->tlock);
	pthread_mutex_unlock(&philo_right->tlock);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&philo->tlock);
	pthread_mutex_lock(philo->fork_left);
	philo->state = HUNGRY;
	while (1)
		if (fork_test(philo))
			break ;
	pthread_mutex_lock(philo->fork_right);
	philo->state = EATING;
	pthread_mutex_lock(&table->tlock);
	printf("%llu\tPhilo %d is eating\n", timestamp(table), philo->seat);
	usleep(table->time_to_eat);
	pthread_mutex_unlock(&table->tlock);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(&philo->tlock);
}

void	philo_sleep(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	pthread_mutex_lock(&philo->tlock);
	philo->state = SLEEPING;
	pthread_mutex_lock(&table->tlock);
	printf("%llu\tPhilo %d is sleeping\n", timestamp(table), philo->seat);
	usleep(table->time_to_sleep);
	pthread_mutex_unlock(&table->tlock);
	pthread_mutex_unlock(&philo->tlock);
}

void	philo_dies(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&philo->tlock);
	pthread_mutex_lock(&table->tlock);
	printf("%llu\tPhilo %d is dead\n", timestamp(table), philo->seat);
	pthread_mutex_unlock(&table->tlock);
	pthread_mutex_unlock(&philo->tlock);
}
