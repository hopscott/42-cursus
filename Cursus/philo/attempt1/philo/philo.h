/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/04/14 02:01:28 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>


enum {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3,
	DEAD = -1
};

typedef struct s_philo {
	int					id;
	pthread_t			tid;
	int					state;
	int					time_since_last_eaten;
	struct s_philo		*philo_left;
	struct s_philo		*philo_right;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
}	t_philo;

typedef struct s_table {
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	struct timeval		start_time;
	struct timeval		current_time;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	int					seat;
}	t_table;

int	ft_atoi(char *str);

#endif
