/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/07/18 18:14:06 by swillis          ###   ########.fr       */
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
	vars->locks = malloc(sizeof(pthread_mutex_t) * vars->n);
	if (!vars->locks)
		return (err_msg("Failed to malloc philo lock mutexes", vars, NULL));
	return (0);
}

int	init_mutexes(t_vars *vars, int i)
{
	if (pthread_mutex_init(&vars->printable, NULL) != 0)
		return (err_msg("Failed init printable mutex", vars, NULL));
	i = -1;
	while (++i < vars->n)
	{
		if (pthread_mutex_init(&vars->fk[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&vars->fk[i]);
			return (err_msg("Failed init fork mutex", vars, &vars->printable));
		}
	}
	i = -1;
	while (++i < vars->n)
	{
		if (pthread_mutex_init(&vars->locks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&vars->locks[i]);
			while (++i < vars->n)
				pthread_mutex_destroy(&vars->fk[i]);
			return (err_msg("Failed init lock mutex", vars, &vars->printable));
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
	if (vars->n == 1)
	{
		vars->philo[i].fk_left = &vars->fk[(i + vars->n) % vars->n];
		vars->philo[i].fk_right = NULL;
	}
	else
	{
		if (i % 2 != 0)
		{
			vars->philo[i].fk_left = &vars->fk[(i + vars->n) % vars->n];
			vars->philo[i].fk_right = &vars->fk[(i + 1) % vars->n];
		}
		else
		{
			vars->philo[i].fk_left = &vars->fk[(i + 1) % vars->n];
			vars->philo[i].fk_right = &vars->fk[(i + vars->n) % vars->n];
		}
	}
}

int	init_philos(t_vars *vars)
{
	int		i;

	i = -1;
	while (++i < vars->n)
	{
		vars->philo[i].vars = vars;
		vars->philo[i].index = i + 1;
		vars->philo[i].state = THINKING;
		vars->philo[i].n_meals = 0;
		vars->philo[i].time_of_last_meal = vars->start;
		allocate_fks(vars, i);
		vars->philo[i].lock = &vars->locks[i];
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
	vars->reaper.souls = 0;
	vars->reaper.fulls = 0;
	vars->reaper.vars = vars;
	if (pthread_create(&vars->th_reap, NULL, &routine_reaper, \
										(void *)&vars->reaper) != 0)
		return (err_msg("Failed to create reaper thread", NULL, NULL));
	return (0);
}
