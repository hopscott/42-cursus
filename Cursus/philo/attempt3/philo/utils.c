/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:18 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 13:40:19 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	opti_sleep(int t_ms, t_philo *philo)
{
	int	response_time_ms;
	int	num_iter;
	int	i;

	response_time_ms = 100;
	num_iter = t_ms / response_time_ms;
	i = 0;
	while (is_alive(philo) && (i < num_iter))
	{
		usleep(response_time_ms * 1000);
		i++;
	}
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
