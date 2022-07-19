/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 13:52:45 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	goto_think(t_philo *philo)
{
	int	time_to_think;
	int	time_to_sleep;
	int	time_to_eat;
	int	time_to_die;

	time_to_die = philo->vars->time_to_die;
	time_to_eat = philo->vars->time_to_eat;
	time_to_sleep = philo->vars->time_to_sleep;
	time_to_think = (time_to_die - time_to_eat - time_to_sleep) / 2;
	if (is_alive(philo))
	{
		state_change(philo, THINKING, "is thinking");
		opti_sleep(time_to_think, philo);
	}
	if (is_alive(philo))
		return (1);
	return (0);
}

int	goto_sleep(t_philo *philo)
{
	int	time_to_sleep;

	time_to_sleep = philo->vars->time_to_sleep;
	if (is_alive(philo))
	{
		state_change(philo, SLEEPING, "is sleeping");
		opti_sleep(time_to_sleep, philo);
	}
	if (is_alive(philo))
		return (1);
	return (0);
}

void	eat(t_philo *philo)
{
	int	time_to_eat;

	time_to_eat = philo->vars->time_to_eat;
	if (is_alive(philo))
	{
		pthread_mutex_lock(philo->lock);
		philo->time_of_last_meal = timestamp_ms();
		philo->n_meals += 1;
		pthread_mutex_unlock(philo->lock);
		opti_sleep(time_to_eat, philo);
	}
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
				state_change(philo, HUNGRY, "has taken a fork");
				state_change(philo, EATING, "is eating");
				eat(philo);
			}
			pthread_mutex_unlock(philo->fk_right);
		}
	}
	pthread_mutex_unlock(philo->fk_left);
	if (is_alive(philo))
		return (1);
	return (0);
}

void	check_soul(t_philo *philo, t_reaper *reaper)
{
	int	time_to_die;
	int	n_meals_needed;
	int	time_of_last_meal;
	int	n_meals;

	time_to_die = reaper->vars->time_to_die;
	n_meals_needed = reaper->vars->n_meals_needed;
	if (is_alive(philo))
	{
		pthread_mutex_lock(philo->lock);
		time_of_last_meal = philo->time_of_last_meal;
		n_meals = philo->n_meals;
		pthread_mutex_unlock(philo->lock);
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
