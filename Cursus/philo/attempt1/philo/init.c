/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/06/09 18:02:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_inputs(int ac, char **av, t_vars *vars)
{
	vars->n = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	vars->num_meals = -1;
	if (ac == 6)
		vars->num_meals = ft_atoi(av[5]);
}

int	init_vars(int ac, char **av, t_vars *vars)
{
	int	i;

	set_inputs(ac, av, vars);
	vars->start = timestamp_ms();
	vars->philo = malloc(sizeof(t_philo) * vars->n);
	if (!vars->philo)
		return (err_msg("Failed to malloc philos"));
	vars->th = malloc(sizeof(pthread_t) * vars->n);
	if (!vars->th)
		return (err_msg("Failed to malloc threads"));
	vars->fk = malloc(sizeof(pthread_mutex_t) * vars->n);
	if (!vars->fk)
		return (err_msg("Failed to malloc fork mutexes"));
	i = -1;
	while (++i < vars->n)
		if (pthread_mutex_init(&vars->fk[i], NULL) != 0)
			return (err_msg("Failed to create fork mutex"));
	if (pthread_mutex_init(&vars->printable, NULL) != 0)
		return (err_msg("Failed to create printable mutex"));
	return (0);
}

void	allocate_fks(t_vars *vars, int i)
{
	vars->philo[i].fk_left = &vars->fk[(i + vars->n) % vars->n];
	vars->philo[i].fk_right = &vars->fk[(i + 1) % vars->n];
	if (i + 1 == vars->n)
	{
		vars->philo[i].fk_left = &vars->fk[(i + 1) % vars->n];
		vars->philo[i].fk_right = &vars->fk[(i + vars->n) % vars->n];
	}
}

int	init_philos(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n)
	{
		vars->philo[i].start = vars->start;
		vars->philo[i].time_of_last_meal = vars->start;
		vars->philo[i].index = i + 1;
		vars->philo[i].state = THINKING;
		vars->philo[i].printable = &vars->printable;
		vars->philo[i].time_to_die = vars->time_to_die;
		vars->philo[i].time_to_eat = vars->time_to_eat;
		vars->philo[i].time_to_sleep = vars->time_to_sleep;
		allocate_fks(&vars, i);
		if (pthread_mutex_init(&vars->philo[i].lock, NULL) != 0)
			return (err_msg("Failed to create philo lock mutex"));
		if (pthread_create(&vars->th[i], NULL, &routine, \
									(void *)&vars->philo[i]) != 0)
			return (err_msg("Failed to create philo thread"));
	}
	return (0);
}

int	init_reaper(t_vars *vars)
{
	vars->reaper.n = vars->n;
	vars->reaper.souls = 0;
	vars->reaper.vars = vars;
	if (pthread_create(&vars.th_kill, NULL, &routine_kill, \
										(void *)&vars->reaper) != 0)
		return (err_msg("Failed to create killer thread"));
	return (0);

}
