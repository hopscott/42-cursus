/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 11:01:21 by scottwillis      ###   ########.fr       */
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

/* ******************* STRUCTS ******************* */

typedef struct s_philo {
	pthread_mutex_t		*lock;
	int					index;
	int					state;
	int					is_alive;
	int					n_meals;
	unsigned long long	time_of_last_meal;
	pthread_mutex_t		*fk_left;
	pthread_mutex_t		*fk_right;
	struct s_vars		*vars;
}	t_philo;

typedef struct s_reaper {
	int					souls;
	int					fulls;
	struct s_vars		*vars;
}	t_reaper;

typedef struct s_vars {
	pthread_mutex_t		printable;
	pthread_mutex_t		*fk;
	pthread_mutex_t		*locks;
	pthread_t			*th;
	pthread_t			th_reap;
	int					n;
	unsigned long long	start;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					n_meals_needed;
	t_philo				*philo;
	t_reaper			reaper;
}	t_vars;

/* ******************* ACTIONS ******************* */
int					goto_think(t_philo *philo);
int					goto_sleep(t_philo *philo);
int					goto_eat(t_philo *philo);
void				check_soul(t_philo *philo, t_reaper *reaper);

/* ******************* CHECKS ******************* */
int					check_args(int ac, char **av);

/* ******************* FT_ATOI ******************* */
int					ft_atoi(char *str);

/* ******************* INIT ******************* */
int					init_vars(int ac, char **av, t_vars *vars);
int					init_mutexes(t_vars *vars, int i);
int					init_philos(t_vars *vars);
int					init_reaper(t_vars *vars);

/* ******************* ROUTINES ******************* */
void				*routine(void *arg);
void				*routine_reaper(void *arg);

/* ******************* UTILS ******************* */
int					is_alive(t_philo *philo);
void				state_change(t_philo *philo, int state, char *action);
unsigned long long	timestamp_ms(void);
unsigned long long	timestamp_diff(unsigned long long start);
int					err_msg(char *msg, t_vars *vars, pthread_mutex_t *mut);

/* ******************* UTILS2 ******************* */
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/* ******************* ISINT ******************* */
int					str_is_int(char *str);

#endif
