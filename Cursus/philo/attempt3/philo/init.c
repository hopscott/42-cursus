/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/07/18 00:18:08 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_vars(int ac, char **av, t_vars *vars)
{
	vars->n = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	vars->n_meals_needed = -1;
	if (ac == 6)
		vars->n_meals_needed = ft_atoi(av[5]);
	vars->start = timestamp_ms();
	vars->philo = malloc(sizeof(t_philo) * vars->n);
	if (!vars->philo)
		return (err_msg("Failed to malloc philos", NULL, NULL));
	vars->th = malloc(sizeof(pthread_t) * vars->n);
	if (!vars->th)
		return (err_msg("Failed to malloc threads", vars, NULL));
	vars->fk = malloc(sizeof(pthread_mutex_t) * vars->n);
	if (!vars->fk)
		return (err_msg("Failed to malloc fork mutexes", vars, NULL));
	vars->philo_locks = malloc(sizeof(pthread_mutex_t) * vars->n);
	if (!vars->philo_locks)
		return (err_msg("Failed to malloc philo lock mutexes", vars, NULL));
	return (0);
}

int	init_mutexes(t_vars *vars, int i)
{
	if (pthread_mutex_init(&vars->printable, NULL) != 0)
		return (err_msg("Failed to create printable mutex", vars, NULL));
	i = -1;
	while (++i < vars->n)
	{
		if (pthread_mutex_init(&vars->fk[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&vars->fk[i]);
			return (err_msg("Failed on fork mutex", vars, &vars->printable));
		}
	}
	i = -1;
	while (++i < vars->n)
	{
		if (pthread_mutex_init(&vars->philo_locks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&vars->philo_locks[i]);
			while (++i < vars->n)
				pthread_mutex_destroy(&vars->fk[i]);
			return (err_msg("Failed on ph_lk mutex", vars, &vars->printable));
		}
	}
	return (0);
}

/* -------------------------------------------------------------	*/
/* 					FORK ALLOCATION									*/
/* -------------------------------------------------------------	*/
/* Swapping forks for last philo only prevents deadlock	-> removed 	*/
/* if (i == vars->n - 1)											*/
/* {																*/
/* 	vars->philo[i].fk_left = &vars->fk[(i + 1) % vars->n];			*/
/* 	vars->philo[i].fk_right = &vars->fk[(i + vars->n) % vars->n];	*/
/* }																*/
/* -------------------------------------------------------------	*/
/* Used odd/even index order of routine to create asymmetry instead	*/
/* If only one philo assign right fork to NULL 						*/
/* -------------------------------------------------------------	*/
void	allocate_fks(t_vars *vars, int i)
{
	t_philo	philo;

	philo = vars->philo[i];
	philo.fk_left = &vars->fk[(i + vars->n) % vars->n];
	if (vars->n == 1)
		philo.fk_right = NULL;
	else
		philo.fk_right = &vars->fk[(i + 1) % vars->n];
}

int	init_philos(t_vars *vars)
{
	int		i;
	t_philo	philo;

	i = -1;
	while (++i < vars->n)
	{
		philo = vars->philo[i];
		philo.index = i + 1;
		philo.state = THINKING;
		philo.n_meals = 0;
		philo.time_of_last_meal = vars->start;
		allocate_fks(vars, i);
		philo.lock = vars->philo_locks[i];
		if (pthread_create(&vars->th[i], NULL, &routine, \
									(void *)&vars->philo[i]) != 0)
		{
			vars->n = i;
			return (err_msg("Failed to create philo thread", NULL, NULL));
		}
	}	
	return (0);
}

int	init_reaper(t_vars *vars)
{
	vars->reaper.n = vars->n;
	vars->reaper.souls = 0;
	vars->reaper.fulls = 0;
	vars->reaper.vars = vars;
	if (pthread_create(&vars->th_reap, NULL, &routine_reaper, \
										(void *)&vars->reaper) != 0)
		return (err_msg("Failed to create reaper thread", NULL, NULL));
	return (0);
}
