/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:10:10 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 14:00:24 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_av_atoi(int ac, char **av)
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
		if (!str_is_int(str))
			return (3);
		if (ft_atoi(str) < 1)
			return (4);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	err;

	err = check_av_atoi(ac, av);
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
			printf("ERROR - Inputs are not within integer range\n");
		else if (err == 4)
			printf("ERROR - Make sure all inputs are greater than 0\n");
		return (1);
	}
	return (0);
}
