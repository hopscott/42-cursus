/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/07/12 16:11:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	eat(t_philo *philo)
{
	int	time_to_eat;

	if (is_alive(philo))
	{
		pthread_mutex_lock(&philo->lock);
		philo->time_of_last_meal = timestamp_ms();
		philo->n_meals += 1;
		time_to_eat = philo->time_to_eat;
		pthread_mutex_unlock(&philo->lock);
		if (is_alive(philo))
			usleep(time_to_eat * 1000);
	}
	pthread_mutex_unlock(philo->fk_left);
	pthread_mutex_unlock(philo->fk_right);
}

int	goto_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fk_left);
	if (is_alive(philo))
	{
		state_change(philo, HUNGRY, "has taken a fork");
		if (philo->fk_right != NULL)
		{
			pthread_mutex_lock(philo->fk_right);
			if (is_alive(philo))
			{
				state_change(philo, EATING, "is eating");
				eat(philo);
				if (is_alive(philo))
					return (1);
				else
					return (0);
			}
			pthread_mutex_unlock(philo->fk_right);
		}
	}
	pthread_mutex_unlock(philo->fk_left);
	return (0);
}

void	check_soul(t_philo *philo, t_reaper *reaper)
{
	int	n_meals_needed;
	int	n_meals;
	int	time_of_last_meal;
	int	time_to_die;

	if (is_alive(philo))
	{
		pthread_mutex_lock(&philo->lock);
		time_of_last_meal = philo->time_of_last_meal;
		time_to_die = philo->time_to_die;
		n_meals = philo->n_meals;
		n_meals_needed = philo->n_meals_needed;
		pthread_mutex_unlock(&philo->lock);
		if ((n_meals_needed != -1) && (n_meals >= n_meals_needed))
		{
			state_change(philo, FULL, "");
			reaper->fulls += 1;
		}
		if ((int)timestamp_diff(time_of_last_meal) > time_to_die)
		{
			state_change(philo, DEAD, "died");
			reaper->souls += 1;
		}
	}
}
