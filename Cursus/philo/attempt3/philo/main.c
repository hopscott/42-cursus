/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/07/18 00:28:15 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_vars *vars, int n)
{
	int	i;

	printf("===> A\n");
	if (vars->n != n)
	{
		i = -1;
		printf("===> B\n");
		while (++i < vars->n)
			vars->philo[i].is_alive = 0;
	}
	printf("===> C\n");
	pthread_join(vars->th_reap, NULL);
	printf("===> D\n");
	i = -1;
	while (++i < vars->n)
		pthread_join(vars->th[i], NULL);
	printf("===> E\n");
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n)
	{
		pthread_mutex_destroy(&vars->fk[i]);
		pthread_mutex_destroy(&vars->philo_locks[i]);
	}
	pthread_mutex_destroy(&vars->printable);
	free(vars->th);
	free(vars->fk);
	free(vars->philo);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		n;

	if (check_args(ac, av) != 0)
		return (1);
	printf(">> 1\n");
	if (init_vars(ac, av, &vars) != 0)
		return (2);
	printf(">> 2\n");
	if (init_mutexes(&vars, 0) != 0)
		return (3);
	printf(">> 3\n");
	if (init_reaper(&vars) != 0)
	{
		free_vars(&vars);
		return (4);
	}
	printf(">> 4\n");
	n = vars.n;
	init_philos(&vars);
	printf(">> 5\n");
	join_threads(&vars, n);
	printf(">> 6\n");
	vars.n = n;
	free_vars(&vars);
	return (0);
}
