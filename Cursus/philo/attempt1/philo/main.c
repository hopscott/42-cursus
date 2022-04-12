/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:05:58 by swillis           #+#    #+#             */
/*   Updated: 2022/04/12 22:24:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3
};

typedef struct s_table {
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	struct timeval		start_time;
	struct timeval		current_time;
	int					id;
	int					lphilo;
	int					rphilo;
	int					lfork;
	int					rfork;
	int					*states;
	pthread_t			*tid;
	pthread_mutex_t		*forks;
}	t_table;

unsigned long long	timestamp(t_table *table)
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	diff;

	gettimeofday(&table->current_time, NULL);
	start = table->start_time;
	end = table->current_time;
	diff.tv_sec = end.tv_sec - start.tv_sec ;
	diff.tv_usec = end.tv_usec - start.tv_usec;
	return (1000000 * diff.tv_sec + diff.tv_usec);
}

void	free_table(t_table *table)
{
	if (table->states)
		free(table->states);
	if (table->tid)
		free(table->tid);
	if (table->forks)
		free(table->forks);
	free(table);
}

void	identify_philo_env(t_table *table)
{
	int	id;
	int	n;

	id = table->id;
	n = table->number_of_philosophers;
	table->lphilo = (id + n - 1) % n;
	table->rphilo = (id + 1) % n;
	table->lfork = id;
	table->rfork = (id + 1) % n;
}

void	philo_think(t_table *table)
{
	table->states[table->id] = THINKING;
	printf("%llu\tPhilo %d is thinking\n", timestamp(table), table->id);
}

void	philo_sleep(t_table *table)
{
	table->states[table->id] = SLEEPING;
	printf("%llu\tPhilo %d is sleeping\n", timestamp(table), table->id);
	usleep(table->time_to_sleep);
}

void	fork_test(int philo, int left, int right)
{
	int	pleft;
	int	pright;

	philo = table->id;
	pleft = table->lphilo;
	pright = table->rphilo;
	if ((table->states[philo] == HUNGRY) && \
		(table->states[pleft] != EATING) && (table->states[pright] != EATING))
		return (1);
	else
		return (0);
}

void	philo_eat(t_table *table)
{
	identify_philo_env(table);
	pthread_mutex_lock(&table->forks[table->lfork]);
	table->states[table->id] = HUNGRY;
	fork_test(table);
	printf("%llu\tPhilo %d is eating\n", timestamp(table), table->id);
}

// https://www.thegeekstuff.com/2012/05/c-mutex-examples/
void	*ft_thread(void *ptr)
{
	t_table	*table;

	table = (t_table *)ptr;
	while (1)
	{
		philo_think(table);
		philo_take_forks(table);
		philo_eat(table);
		philo_drop_forks(table);
		philo_sleep(table);
	}
	return (ptr);
}

// https://en.wikipedia.org/wiki/Dining_philosophers_problem
// https://www.cc.gatech.edu/classes/AY2010/cs4210_fall/lectures/04-PthreadsIntro.pdf
int	set_the_table(t_table *table)
{
	int	id;

	id = 0;
	while (id < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[id], NULL))
		{
			free_table(table);
			return (1);
		}
		id++;
	}
	id = 0;
	while (id < table->number_of_philosophers)
	{
		table->id = id;
		printf("%llu\tPhilo %d has joined the table\n", timestamp(table), table->id);
		if (pthread_create(&table->tid[id], NULL, ft_thread, (void *)table))
		{
			free_table(table);
			return (1);
		}
		id++;
	}
	return (0);
}

void	start_dinner(t_table *table)
{
	int	id;

	table->states = malloc(sizeof(int) * table->number_of_philosophers);
	if (!table->states)
		return (free_table(table));
	table->tid = malloc(sizeof(pthread_t) * table->number_of_philosophers);
	if (!table->tid)
		return (free_table(table));
	table->forks = malloc(sizeof(pthread_mutex_t) * \
											table->number_of_philosophers);
	if (!table->forks)
		return (free_table(table));
	if (set_the_table(table))
	{
		printf("ERROR - Setting up table\n");
		return (free_table(table));
	}
	id = 0;
	while (id < table->number_of_philosophers)
	{
		table->id = id;
		pthread_join(table->tid[id], NULL);
		id++;
	}
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac == 5)
	{
		table = malloc(sizeof(t_table));
		if (!table)
			return (1);
		gettimeofday(&table->start_time, NULL);
		table->number_of_philosophers = ft_atoi(av[1]);
		table->time_to_die = ft_atoi(av[2]);
		table->time_to_eat = ft_atoi(av[3]);
		table->time_to_sleep = ft_atoi(av[4]);
		if ((table->number_of_philosophers > 0) && (table->time_to_die > 0) \
					&& (table->time_to_eat > 0) && (table->time_to_sleep > 0))
			start_dinner(table);
		else
			printf("ERROR - Make sure all inputs are greater than 0");
		free_table(table);
	}
	return (0);
}
