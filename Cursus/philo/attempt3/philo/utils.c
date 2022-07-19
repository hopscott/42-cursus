/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:18 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 11:16:48 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_philo *philo)
{
	int	is_alive;

	pthread_mutex_lock(philo->lock);
	is_alive = philo->is_alive;
	pthread_mutex_unlock(philo->lock);
	if (is_alive)
		return (1);
	return (0);
}

void	state_change(t_philo *philo, int state, char *action)
{
	pthread_mutex_lock(philo->lock);
	philo->state = state;
	if ((state == FULL) || (state == DEAD))
		philo->is_alive = 0;
	pthread_mutex_unlock(philo->lock);
	if (state != FULL)
	{
		pthread_mutex_lock(&philo->vars->printable);
		printf("%llu %d %s\n", timestamp_diff(philo->vars->start), \
				philo->index, action);
		pthread_mutex_unlock(&philo->vars->printable);
	}
}

unsigned long long	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((1000000 * tv.tv_sec) + tv.tv_usec) / 1000);
}

unsigned long long	timestamp_diff(unsigned long long start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((1000000 * tv.tv_sec) + tv.tv_usec) / 1000) - start);
}

int	err_msg(char *msg, t_vars *vars, pthread_mutex_t *mut)
{
	if (vars != NULL)
	{
		if (vars->philo)
			free(vars->philo);
		if (vars->th)
			free(vars->th);
		if (vars->fk)
			free(vars->fk);
		if (vars->locks)
			free(vars->locks);
	}
	if (mut != NULL)
		pthread_mutex_destroy(mut);
	perror(msg);
	return (1);
}
