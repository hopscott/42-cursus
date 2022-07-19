/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 11:15:08 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_vars *vars, int n, int th_reap_running)
{
	int	i;

	if ((vars->n != n) || (!th_reap_running))
	{
		i = -1;
		while (++i < vars->n)
		{
			pthread_mutex_lock(vars->philo[i].lock);
			vars->philo[i].is_alive = 0;
			pthread_mutex_unlock(vars->philo[i].lock);
		}
	}
	if (th_reap_running)
		pthread_join(vars->th_reap, NULL);
	i = -1;
	while (++i < vars->n)
		pthread_join(vars->th[i], NULL);
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n)
	{
		pthread_mutex_destroy(&vars->fk[i]);
		pthread_mutex_destroy(&vars->locks[i]);
	}
	pthread_mutex_destroy(&vars->printable);
	free(vars->fk);
	free(vars->locks);
	free(vars->th);
	free(vars->philo);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		n;

	if (check_args(ac, av) != 0)
		return (1);
	if (init_vars(ac, av, &vars) != 0)
		return (2);
	if (init_mutexes(&vars, 0) != 0)
		return (3);
	n = vars.n;
	init_philos(&vars);
	join_threads(&vars, n, init_reaper(&vars));
	vars.n = n;
	free_vars(&vars);
	return (0);
}
