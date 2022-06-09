/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/06/09 18:02:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_change(t_philo *philo, int state, char *action)
{
	pthread_mutex_lock(&philo->lock);
	philo->state = state;
	pthread_mutex_lock(philo->printable);
	printf("%llu\tPhilo %d %s\n", timestamp_diff(philo->start), \
			philo->index, action);
	pthread_mutex_unlock(philo->printable);
	pthread_mutex_unlock(&philo->lock);
}

int	goto_think(t_philo *philo)
{
	if (is_alive(philo))
	{
		state_change(philo, THINKING, "is thinking");
		return (1);
	}
	return (0);
}

int	goto_sleep(t_philo *philo)
{
	int	time_to_sleep;

	if (is_alive(philo))
	{
		state_change(philo, SLEEPING, "is sleeping");
		pthread_mutex_lock(&philo->lock);
		time_to_sleep = philo->time_to_sleep;
		pthread_mutex_unlock(&philo->lock);
		usleep(time_to_sleep * 1000);
		return (1);
	}
	return (0);
}

int	goto_eat(t_philo *philo)
{
	int	time_to_eat;

	if (is_alive(philo))
	{
		pthread_mutex_lock(philo->fk_left);
		state_change(philo, HUNGRY, "has taken a fork");
		pthread_mutex_lock(philo->fk_right);
		state_change(philo, EATING, "is eating");
		pthread_mutex_lock(&philo->lock);
		time_to_eat = philo->time_to_eat;
		philo->time_of_last_meal = timestamp_ms();
		pthread_mutex_unlock(&philo->lock);
		usleep(time_to_eat * 1000);
		pthread_mutex_unlock(philo->fk_left);
		pthread_mutex_unlock(philo->fk_right);
		return (1);
	}
	return (0);
}

int	check_soul(t_philo *philo)
{
	int	time_of_last_meal;
	int	time_to_die;

	if (is_alive(philo))
	{
		pthread_mutex_lock(&philo->lock);
		time_of_last_meal = philo->time_of_last_meal;
		time_to_die = philo->time_to_die;
		pthread_mutex_unlock(&philo->lock);
		if ((int)timestamp_diff(time_of_last_meal) > time_to_die)
		{
			state_change(philo, DEAD, "died");
			return (1);
		}
	}
	return (0);
}
