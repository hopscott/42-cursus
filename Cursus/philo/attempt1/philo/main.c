/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:05:58 by swillis           #+#    #+#             */
/*   Updated: 2022/04/14 02:07:38 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
}

void	philo_think(t_table *table, int id)
{
	t_philo	*philo;

	philo = &table->philos[id];
	philo->state = THINKING;
	printf("%llu\tPhilo %d is thinking\n", timestamp(table), philo->id);
}

int	fork_test(t_philo *philo)
{
	t_philo	*philo_left;
	t_philo	*philo_right;

	philo_left = philo->philo_left;
	philo_right = philo->philo_right;
	if (philo->state == HUNGRY) 
		if ((philo_left->state != EATING) && (philo_right->state != EATING))
			return (1);
	return (0);
}

void	philo_eat(t_table *table, int id)
{
	t_philo	*philo;

	philo = &table->philos[id];
	pthread_mutex_lock(philo->fork_left);
	philo->state = HUNGRY;
	while (!fork_test(philo))
		usleep(5);
	pthread_mutex_lock(philo->fork_right);
	philo->state = EATING;
	printf("%llu\tPhilo %d is eating\n", timestamp(table), philo->id);
	usleep(table->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	philo_sleep(t_table *table, int id)
{
	t_philo	*philo;

	philo = &table->philos[id];
	philo->state = SLEEPING;
	printf("%llu\tPhilo %d is sleeping\n", timestamp(table), philo->id);
	usleep(table->time_to_sleep);
}

// https://www.thegeekstuff.com/2012/05/c-mutex-examples/
void	*ft_thread(void *ptr)
{
	t_table	*table;
	int		seat;

	table = (t_table *)ptr;
	seat = table->seat;
	while (1)
	{
		philo_think(table, seat);
		philo_eat(table, seat);
		philo_sleep(table, seat);
	}
	return (ptr);
}

void	init_philo(t_table *table, int id)
{
	t_philo *philo;
	int		n;

	philo = &table->philos[id];
	philo->id = id;
	philo->state = THINKING;
	philo->time_since_last_eaten = 0;
	n = table->number_of_philosophers;
	philo->philo_left = &table->philos[(id + n - 1) % n];
	philo->philo_right = &table->philos[(id + 1) % n];
	philo->fork_left = &table->forks[id];
	philo->fork_right = &table->forks[(id + 1) % n];
	pthread_create(&philo->tid, NULL, ft_thread, (void *)table);
}

// https://en.wikipedia.org/wiki/Dining_philosophers_problem
// https://www.cc.gatech.edu/classes/AY2010/cs4210_fall/lectures/04-PthreadsIntro.pdf
// printf("%llu\tPhilo %d has joined the table\n", timestamp(table), table->id);
int	set_the_table(t_table *table)
{
	int	n;

	n = table->number_of_philosophers;
	table->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!table->forks)
		return (1);
	n = 0;
	while (n < table->number_of_philosophers)
	{
		pthread_mutex_init(&table->forks[n], NULL);
		n++;
	}
	n = table->number_of_philosophers;
	table->philos = malloc(sizeof(t_philo) * n);
	if (!table->philos)
		return (1);
	n = 0;
	while (n < table->number_of_philosophers)
	{
		init_philo(table, n);
		n++;
	}
	return (0);
}

void	start_dinner(t_table *table)
{
	t_philo	*philo;
	int		seat;

	if (!set_the_table(table))
	{
		seat = 0;
		while (seat < table->number_of_philosophers)
		{
			table->seat = seat;
			philo = &table->philos[seat];
			pthread_join(philo->tid, NULL);
			seat++;
		}
	}
	else
		printf("ERROR - Setting up table\n");
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
