#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct s_philo {
    unsigned long long  start;
    int                 index;
	int				    time_to_eat;
	int				    time_to_die;
	int				    time_to_sleep;
    pthread_mutex_t     *printable;
}	t_philo;

typedef struct s_vars {
    int                 n;
    unsigned long long  start;
    int				    time_to_eat;
	int				    time_to_die;
	int				    time_to_sleep;
    t_philo             *philo;
    pthread_t           *th;
    pthread_mutex_t     printable;
}	t_vars;

// ============================== TIME =================================

unsigned long long	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((1000000 * tv.tv_sec) + tv.tv_usec) / 1000);
}

unsigned long long	timestamp_diff(unsigned long long start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((1000000 * tv.tv_sec) + tv.tv_usec) / 1000) - start);
}

// ============================= ACTIONS =====================================

void    goto_sleep(t_philo *philo)
{
    pthread_mutex_lock(philo->printable);
    printf("%llu\t\tPhilo %d is sleeping\n", timestamp_diff(philo->start), philo->index);
    pthread_mutex_unlock(philo->printable);
    usleep(philo->time_to_sleep);
}

// ============================= ROUTINE =====================================

void    *routine(void *arg)
{
    t_philo philo;

    philo = *(t_philo *)arg;

    while (1)
    {
        goto_sleep(&philo);
    }
    return (0);
}

// ============================= MAIN =====================================

int main(void)
{
    t_vars  vars;
    int     i;

    // ============= VARS ===============

    vars.n = 5;
    vars.time_to_die = 500;
    vars.time_to_eat = 200;
    vars.time_to_sleep = 200;
    vars.start = timestamp_ms();
    vars.philo = malloc(sizeof(t_philo) * vars.n);
    if (!vars.philo)
        perror("Failed to malloc philos");
    vars.th = malloc(sizeof(pthread_t) * vars.n);
    if (!vars.th)
        perror("Failed to malloc threads");

    if (pthread_mutex_init(&vars.printable, NULL) != 0)
            perror("Failed to create printable mutex");
    

    // =====================================

    i = -1;
    while (++i < vars.n)
    {
        vars.philo[i].start = vars.start;
        vars.philo[i].index = i;
        vars.philo[i].printable = &vars.printable;
    
        if (pthread_create(&vars.th[i], NULL, &routine, (void *)&vars.philo[i]) != 0)
            perror("Failed to create thread");
    }

    // =====================================

    i = -1;
    while (++i < vars.n)
        if (pthread_join(vars.th[i], NULL) != 0)
            perror("Failed to join thread");


    free(vars.th);
    free(vars.philo);

    // =====================================

    return (0);
}

