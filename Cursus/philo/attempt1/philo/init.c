/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:43:13 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/20 17:45:55 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table, int seat)
{
	t_philo *philo;
	int		n;

	philo = &table->philos[seat];
	philo->seat = seat;
	philo->state = THINKING;
	philo->time_since_last_eaten = 0;
	n = table->number_of_philosophers;
	philo->philo_left = &table->philos[(seat + n - 1) % n];
	philo->philo_right = &table->philos[(seat + 1) % n];
	philo->fork_left = &table->forks[seat];
	philo->fork_right = &table->forks[(seat + 1) % n];
	philo->table = table;
	pthread_create(&philo->tid, NULL, philosophise, (void *)philo);
}

void	init_grimreaper(t_table *table)
{
	t_reaper	*reaper;

	reaper = table->reaper;
	reaper->table = table;
	reaper->souls = 0;
	pthread_mutex_init(&reaper->tlock, NULL);
	pthread_create(&reaper->tid, NULL, collect_souls, (void *)reaper);
}

t_table	*init_table(char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	gettimeofday(&table->start_time, NULL);
	table->number_of_philosophers = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	return (table);
}

int	table_setup(t_table *table)
{
	int	n;

	n = table->number_of_philosophers;
	pthread_mutex_init(&table->tlock, NULL);
	table->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!table->forks)
		return (1);
	n = 0;
	while (n < table->number_of_philosophers)
		pthread_mutex_init(&table->forks[n++], NULL);
	table->philos = malloc(sizeof(t_philo) * n);
	if (!table->philos)
		return (1);
	n = 0;
	while (n < table->number_of_philosophers)
		init_philo(table, n++);
	table->reaper = malloc(sizeof(t_reaper));
	if (!table->reaper)
		return (1);
	init_grimreaper(table);
	return (0);
}
