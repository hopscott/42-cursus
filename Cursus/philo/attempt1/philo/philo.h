/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/06/09 18:02:26 by swillis          ###   ########.fr       */
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
	DEAD = -1,
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3
};

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
	pthread_mutex_t		*fk_left;
	pthread_mutex_t		*fk_right;
}	t_philo;

typedef struct s_reaper {
	int					n;
	int					souls;
	struct s_vars		*vars;
}	t_reaper;

typedef struct s_vars {
	pthread_t			*th;
	pthread_mutex_t		*fk;
	pthread_t			th_kill;
	pthread_mutex_t		printable;
	int					n;
	unsigned long long	start;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	t_philo				*philo;
	t_reaper			reaper;
}	t_vars;

//******************** LIBFT ********************//


//******************** INIT ********************//


//******************** THREADS ********************//

//******************** TIMING ********************//


//******************** ACTIONS ********************//


#endif
