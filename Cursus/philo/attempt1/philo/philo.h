/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/04/22 16:35:49 by scottwillis      ###   ########.fr       */
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
	THINKING = 1,
	HUNGRY = 2,
	EATING = 3,
	SLEEPING = 4,
	FULL = 0,
	DEAD = -1
};

typedef struct s_list
{
	int				id;
	struct s_list	*next;
}	t_list;

typedef struct s_reaper {
	pthread_t			tid;
	int					souls;
	struct s_table		*table;
}	t_reaper;

typedef struct s_philo {
	pthread_t			tid;
	pthread_mutex_t		tlock;
	int					seat;
	int					state;
	int					times_eaten;
	unsigned long long	timestamp_last_meal;
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
	int					number_of_times_each_philosopher_must_eat;
	struct timeval		start_time;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	t_reaper			*reaper;
	t_list				*queue;
}	t_table;

//******************** LIBFT ********************//
int	ft_atoi(char *str);

//******************** INIT ********************//
t_table	*init_table(int ac, char **av);

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

//******************** LIST ********************//
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstpop(t_list **lst);
void		queue_rotate(t_list **lst);

//******************** MAIN ********************//
t_table	*free_table(t_table *table);

#endif
