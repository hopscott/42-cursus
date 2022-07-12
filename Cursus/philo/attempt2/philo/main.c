/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/06/29 08:24:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n)
		if (pthread_join(vars->th[i], NULL) != 0)
			return (err_msg("Failed to join thread"));
	if (pthread_join(vars->th_reap, NULL) != 0)
		return (err_msg("Failed to join reaper thread"));
	return (0);
}

int	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n)
	{
		pthread_mutex_destroy(&vars->fk[i]);
		pthread_mutex_destroy(&vars->philo[i].lock);
	}
	pthread_mutex_destroy(&vars->lock);
	pthread_mutex_destroy(&vars->printable);
	free(vars->th);
	free(vars->fk);
	free(vars->philo);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		err;

	err = check_args(ac, av);
	if (err)
		return (1);
	err = init_vars(ac, av, &vars);
	if (!err)
		err = init_philos(&vars);
	if (!err)
		err = init_reaper(&vars);
	if (!err)
		err = join_threads(&vars);
	free_vars(&vars);
	return (err);
}
