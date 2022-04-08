/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:05:58 by swillis           #+#    #+#             */
/*   Updated: 2022/04/08 15:21:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_table
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	struct timezone		tz;
	struct timeval		start_time;
	struct timeval		current_time;
	pthread_mutex_t		*forks;
	pthread_t			*philos;
	int					id;
}	t_table;

unsigned long long	timestamp(t_table *table)
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	diff;

	gettimeofday(&table->current_time, &table->tz);
	start = table->start_time;
	end = table->current_time;
	diff.tv_sec = end.tv_sec - start.tv_sec ;
	diff.tv_usec = end.tv_usec - start.tv_usec;
	return (1000000 * diff.tv_sec + diff.tv_usec);
}

// https://www.thegeekstuff.com/2012/05/c-mutex-examples/
void	*philo_thread(void *ptr)
{
	t_table	*table;

	table = (t_table *)ptr;
	printf("%llu\tPhilo %d has joined the table\n", timestamp(table), table->id);
	return (ptr);
}

int	free_table(t_table *table)
{
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	return (1);
}

int	set_the_table(t_table *table)
{
	int	id;

	table->forks = malloc(sizeof(table->forks) * table->number_of_philosophers);
	table->philos = malloc(sizeof(pthread_t) * table->number_of_philosophers);
	if (!table->forks || !table->philos)
		return (free_table(table));
	id = 0;
	while (id < table->number_of_philosophers)
	{
		table->id = id;
		if (pthread_mutex_init(&table->forks[id], NULL))
			return (free_table(table));
		if (pthread_create(&table->philos[id], NULL, \
												philo_thread, (void *)table))
			return (free_table(table));
		id++;
	}
	return (0);
}

void	start_dinner(t_table *table)
{
	int	id;

	if (set_the_table(table))
	{
		printf("ERROR - Setting up table\n");
		return ;
	}
	id = 0;
	while (id < table->number_of_philosophers)
	{
		table->id = id;
		pthread_join(table->philos[id], NULL);
		id++;
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	table.number_of_philosophers = -1;
	table.time_to_die = -1;
	table.time_to_eat = -1;
	table.time_to_sleep = -1;
	if (ac == 5)
	{
		gettimeofday(&table.start_time, &table.tz);
		table.number_of_philosophers = ft_atoi((unsigned char *)av[1]);
		table.time_to_die = ft_atoi((unsigned char *)av[2]);
		table.time_to_eat = ft_atoi((unsigned char *)av[3]);
		table.time_to_sleep = ft_atoi((unsigned char *)av[4]);
		if ((table.number_of_philosophers > 0) && (table.time_to_die > 0) \
					&& (table.time_to_eat > 0) && (table.time_to_sleep > 0))
			start_dinner(&table);
		else
			printf("ERROR - Make sure all inputs are greater than 0");
	}
	return (free_table(&table));
}
