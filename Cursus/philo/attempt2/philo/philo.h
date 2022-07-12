/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/06/29 08:14:31 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

enum {
	DEAD		= -1,
	FULL		= 0,
	THINKING	= 1,
	HUNGRY		= 2,
	EATING		= 3,
	SLEEPING	= 4
};

//******************** STRUCTS ********************//

typedef struct s_philo {
	pthread_mutex_t		lock;
	pthread_mutex_t		*printable;
	unsigned long long	start;
	unsigned long long	time_of_last_meal;
	int					index;
	int					state;
	int					is_alive;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					n_meals_needed;
	int					n_meals;
	pthread_mutex_t		*fk_left;
	pthread_mutex_t		*fk_right;
}	t_philo;

typedef struct s_reaper {
	int					n;
	int					souls;
	int					fulls;
	struct s_vars		*vars;
}	t_reaper;

typedef struct s_vars {
	pthread_mutex_t		lock;
	pthread_t			*th;
	pthread_mutex_t		*fk;
	pthread_t			th_reap;
	pthread_mutex_t		printable;
	int					n;
	unsigned long long	start;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					n_meals_needed;
	t_philo				*philo;
	t_reaper			reaper;
}	t_vars;

//******************** ACTIONS ********************//
int					goto_think(t_philo *philo);
int					goto_sleep(t_philo *philo);
int					goto_eat(t_philo *philo);
void				check_soul(t_philo *philo, t_reaper *reaper);

//******************** CHECKS ********************//
int					check_args(int ac, char **av);

//******************** FT_ATOI ********************//
int					ft_atoi(char *str);

//******************** INIT ********************//
int					init_vars(int ac, char **av, t_vars *vars);
int					init_philos(t_vars *vars);
int					init_reaper(t_vars *vars);

//******************** ROUTINES ********************//
void				*routine(void *arg);
void				*routine_reaper(void *arg);

//******************** UTILS ********************//
int					is_alive(t_philo *philo);
void				state_change(t_philo *philo, int state, char *action);
unsigned long long	timestamp_ms(void);
unsigned long long	timestamp_diff(unsigned long long start);
int					err_msg(char *msg);

#endif
