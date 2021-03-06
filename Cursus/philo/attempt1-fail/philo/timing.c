/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:42:47 by scottwillis       #+#    #+#             */
/*   Updated: 2022/04/21 13:24:07 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	timestamp(t_table *table)
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	diff;

	gettimeofday(&end, NULL);
	start = table->start_time;
	diff.tv_sec = end.tv_sec - start.tv_sec ;
	diff.tv_usec = end.tv_usec - start.tv_usec;
	return (1000000 * diff.tv_sec + diff.tv_usec);
}
