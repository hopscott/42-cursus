/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:05:58 by swillis           #+#    #+#             */
/*   Updated: 2022/04/20 17:48:26 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//******************** LINKS ********************//
// https://en.wikipedia.org/wiki/Dining_philosophers_problem
// https://www.cc.gatech.edu/classes/AY2010/cs4210_fall/lectures/04-PthreadsIntro.pdf
//***********************************************//

#include "philo.h"

void	free_table(t_table *table)
{
	int	i;

	if (table->philos)
	{
		i = 0;
		while (i < table->number_of_philosophers)
			free(&table->philos[i++]);
		free(table->philos);
	}
	if (table->forks)
	{
		// i = 0;
		// while (i < table->number_of_philosophers)
		// 	free(&table->forks[i++]);
		free(table->forks);
	}
	free(table);
}

void	start_dinner(t_table *table)
{
	t_reaper	*reaper;
	t_philo		*philo;
	int		seat;
	int		n;

	reaper = table->reaper;
	n = table->number_of_philosophers;
	pthread_join(reaper->tid, NULL);
	seat = 0;
	while (seat < n)
	{
		philo = &table->philos[seat];
		pthread_join(philo->tid, NULL);
		seat++;
	}
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		err;

	if (ac != 5)
		return (1);
	table = init_table(av);
	if (!table)
		return (1);
	if ((table->number_of_philosophers < 1) || (table->time_to_die < 1) \
				|| (table->time_to_eat < 1) || (table->time_to_sleep < 1))
	{
		printf("ERROR - Make sure all inputs are greater than 0");
		free_table(table);
		return (1);
	}
	err = table_setup(table);
	if (err)
	{
		free_table(table);
		return (1);
	}
	start_dinner(table);
	free_table(table);
	return (0);
}
