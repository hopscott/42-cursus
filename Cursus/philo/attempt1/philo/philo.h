/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/04/20 17:39:50 by scottwillis      ###   ########.fr       */
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

typedef struct s_reaper {
	pthread_t			tid;
	pthread_mutex_t		tlock;
	int					souls;
	struct s_table		*table;
}	t_reaper;

typedef struct s_philo {
	pthread_t			tid;
	pthread_mutex_t		tlock;
	int					seat;
	int					state;
	int					time_since_last_eaten;
	struct s_philo		*philo_left;
	struct s_philo		*philo_right;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	struct s_table		*table;
}	t_philo;

typedef struct s_table {
	pthread_mutex_t		tlock;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	struct timeval		start_time;
	struct timeval		current_time;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	t_reaper			*reaper;
}	t_table;

//******************** LIBFT ********************//
int	ft_atoi(char *str);

//******************** INIT ********************//
t_table	*init_table(char **av);
void	init_philo(t_table *table, int seat);
void	init_grimreaper(t_table *table);
int		table_setup(t_table *table);

//******************** THREADS ********************//
void	*philosophise(void *ptr);
void	*collect_souls(void *ptr);

//******************** TIMING ********************//
unsigned long long	timestamp(t_table *table);

//******************** ACTIONS ********************//
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_dies(t_philo *philo);

#endif
