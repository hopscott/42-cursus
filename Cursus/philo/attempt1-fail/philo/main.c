/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:05:58 by swillis           #+#    #+#             */
/*   Updated: 2022/04/22 16:43:18 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//******************** LINKS ********************//
// https://en.wikipedia.org/wiki/Dining_philosophers_problem
// https://www.cc.gatech.edu/classes/AY2010/cs4210_fall/lectures/04-PthreadsIntro.pdf
//***********************************************//

#include "philo.h"

int	free_table(t_table *table)
{
	t_philo	philo;
	int		i;

	if (table->philos)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			philo = table->philos[i++];
			pthread_mutex_destroy(&philo.tlock);
		}
		free(table->philos);
	}
	if (table->forks)
	{
		i = 0;
		while (i < table->number_of_philosophers)
			pthread_mutex_destroy(&table->forks[i++]);
		free(table->forks);
	}
	if (table->reaper)
		free(table->reaper);
	free(table);
	return (1);
}

int	check_args(int ac, char **av)
{
	char	*str;
	int		i;
	int		j;

	if ((ac < 5) || (ac > 6))
		return (1);
	i = 1;
	while (i < ac)
	{
		str = av[i++];
		j = 0;
		while (str && str[j])
		{
			if ((str[j] < '0' || str[j] > '9') && \
				(str[j] != '-' && str[j] != '+'))
				return (2);
			j++;
		}
		if (ft_atoi(str) < 1)
			return (3);
	}
	return (0);
}

int	start_dinner(t_table *table)
{
	t_reaper	*reaper;
	t_philo		*philo;
	int			seat;
	int			n;

	gettimeofday(&table->start_time, NULL);
	reaper = table->reaper;
	n = table->number_of_philosophers;
	seat = 0;
	while (seat < n)
	{
		philo = &table->philos[seat];
		if (pthread_join(philo->tid, NULL) != 0)
			return (1);
		seat++;
	}
	if (pthread_join(reaper->tid, NULL) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		err;

	err = check_args(ac, av);
	if (err)
	{
		if (err == 1)
		{
			printf("Define \t-> number_of_philosophers\n \t-> time_to_die\n");
			printf("\t-> time_to_eat\n \t-> time_to_sleep\n");
			printf("\t-> (+ number_of_times_each_philosopher_must_eat)\n");
		}
		else if (err == 2)
			printf("ERROR - Inputs contain non-digit characters\n");
		else if (err == 3)
			printf("ERROR - Make sure all inputs are greater than 0\n");
		return (1);
	}
	table = init_table(ac, av);
	if (!table)
		return (1);
	err = start_dinner(table);
	free_table(table);
	return (err);
}
