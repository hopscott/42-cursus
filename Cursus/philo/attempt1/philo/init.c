/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:43:13 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/22 16:36:57 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_table *table, int seat)
{
	t_philo *philo;
	int		n;

	philo = &table->philos[seat];
	philo->seat = seat;
	philo->state = THINKING;
	philo->timestamp_last_meal = timestamp(table);
	n = table->number_of_philosophers;
	philo->philo_left = &table->philos[(seat + n - 1) % n];
	philo->philo_right = &table->philos[(seat + 1) % n];
	philo->fork_left = &table->forks[seat];
	philo->fork_right = &table->forks[(seat + 1) % n];
	philo->table = table;
	if (pthread_create(&philo->tid, NULL, philosophise, (void *)philo) != 0)
		return (1);
	return (0);
}

int	init_grimreaper(t_table *table)
{
	t_reaper	*reaper;

	reaper = table->reaper;
	reaper->table = table;
	reaper->souls = 0;
	if (pthread_create(&reaper->tid, NULL, collect_souls, (void *)reaper) != 0)
		return (1);
	return (0);
}

int	table_setup(t_table *table)
{
	int	n;

	n = table->number_of_philosophers;
	table->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!table->forks)
		return (1);
	n = 0;
	while (n < table->number_of_philosophers)
		if (pthread_mutex_init(&table->forks[n++], NULL) != 0)
			return (1);
	table->philos = malloc(sizeof(t_philo) * n);
	if (!table->philos)
		return (1);
	n = 0;
	while (n < table->number_of_philosophers)
		if (init_philo(table, n++) != 0)
			return (1);
	table->reaper = malloc(sizeof(t_reaper));
	if (!table->reaper)
		return (1);
	if (init_grimreaper(table) != 0)
		return (1);
	return (0);
}

int	queue_setup(t_table *table)
{
	int		i;

	i = 0;
	table->queue = ft_lstnew(i);
	if (!table->queue)
		return (1);
	while (i++ < table->number_of_philosophers)
		if (i % 2 == 0)
			ft_lstadd_back(&table->queue, ft_lstnew(i));
	i = 0;
	while (i++ < table->number_of_philosophers)
		if (i % 2 != 0)
			ft_lstadd_back(&table->queue, ft_lstnew(i));
	return (0);
}

t_table	*init_table(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->number_of_philosophers = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->number_of_times_each_philosopher_must_eat = -1;
	if (ac == 6)
		table->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	if (queue_setup(table))
		return (free_table(table));
	if (pthread_mutex_init(&table->tlock, NULL) != 0)
		return (free_table(table));
	if (table_setup(table))
		return (free_table(table));
	gettimeofday(&table->start_time, NULL);
	return (table);
}

