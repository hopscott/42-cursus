#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

enum {
	DEAD = -1,
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3
};

typedef struct s_philo {
    pthread_mutex_t     lock;
    pthread_mutex_t     *printable;
    unsigned long long  start;
    unsigned long long  time_of_last_meal;
    int                 index;
    int                 state;
    int                 is_alive;
	int				    time_to_eat;
	int				    time_to_die;
	int				    time_to_sleep;
    pthread_mutex_t     *fk_left;
    pthread_mutex_t     *fk_right;
}	t_philo;

typedef struct s_reaper {
    int                 n;
    int                 souls;
    struct s_vars       *vars;
}	t_reaper;

typedef struct s_vars {
    pthread_t           *th;
    pthread_mutex_t     *fk;
    pthread_t           th_kill;
    pthread_mutex_t     printable;
    int                 n;
    unsigned long long  start;
    int				    time_to_eat;
	int				    time_to_die;
	int				    time_to_sleep;
    t_philo             *philo;
    t_reaper            reaper;
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

int    goto_think(t_philo *philo)
{
    int state;

    pthread_mutex_lock(&philo->lock);
    state = philo->state;
    pthread_mutex_unlock(&philo->lock);
    if (state != DEAD)
    {
        pthread_mutex_lock(&philo->lock);
        if (philo->state == DEAD)
            return (0);
        philo->state = THINKING;
        pthread_mutex_lock(philo->printable);
        printf("%llu %d is thinking\n", timestamp_diff(philo->start), philo->index);
        // printf("%llu\tPhilo %d is thinking\n", timestamp_diff(philo->start), philo->index);
        pthread_mutex_unlock(philo->printable);
        pthread_mutex_unlock(&philo->lock);
        return (1);
    }
    return (0);
}

int    goto_sleep(t_philo *philo)
{
    int state;

    pthread_mutex_lock(&philo->lock);
    state = philo->state;
    pthread_mutex_unlock(&philo->lock);
    if (state != DEAD)
    {
        pthread_mutex_lock(&philo->lock);
        if (philo->state == DEAD)
            return (0);
        philo->state = SLEEPING;
        pthread_mutex_lock(philo->printable);
        printf("%llu %d is sleeping\n", timestamp_diff(philo->start), philo->index);
        // printf("%llu\tPhilo %d is sleeping\n", timestamp_diff(philo->start), philo->index);
        pthread_mutex_unlock(philo->printable);
        pthread_mutex_unlock(&philo->lock);
        usleep(philo->time_to_sleep * 1000);
        return (1);
    }
    return (0);
}

int    goto_eat(t_philo *philo)
{
    int state;

    pthread_mutex_lock(&philo->lock);
    state = philo->state;
    pthread_mutex_unlock(&philo->lock);
    if (state != DEAD)
    {
        pthread_mutex_lock(philo->fk_left);
        pthread_mutex_lock(&philo->lock);
        if (philo->state == DEAD)
            return (0);
        philo->state = HUNGRY;
        pthread_mutex_lock(philo->printable);
        printf("%llu %d has taken a fork\n", timestamp_diff(philo->start), philo->index);
        // printf("%llu\tPhilo %d has taken a fork\n", timestamp_diff(philo->start), philo->index);
        pthread_mutex_unlock(philo->printable);
        pthread_mutex_unlock(&philo->lock);

        pthread_mutex_lock(philo->fk_right);
        pthread_mutex_lock(&philo->lock);
        if (philo->state == DEAD)
            return (0);
        philo->state = EATING;
        pthread_mutex_lock(philo->printable);
        printf("%llu %d is eating\n", timestamp_diff(philo->start), philo->index);
        // printf("%llu\tPhilo %d is eating\n", timestamp_diff(philo->start), philo->index);
        pthread_mutex_unlock(philo->printable);
        pthread_mutex_unlock(&philo->lock);

        pthread_mutex_lock(&philo->lock);
        philo->time_of_last_meal = timestamp_ms();
        pthread_mutex_unlock(&philo->lock);

        usleep(philo->time_to_eat * 1000);

        pthread_mutex_unlock(philo->fk_left);
        pthread_mutex_unlock(philo->fk_right);

        return (1);
    }
    return (0);
}

int    check_soul(t_philo *philo)
{
    int state;
    int time_of_last_meal;
    int time_to_die;

    pthread_mutex_lock(&philo->lock);
    state = philo->state;
    time_of_last_meal = philo->time_of_last_meal;
    time_to_die = philo->time_to_die;
    pthread_mutex_unlock(&philo->lock);
    if (state != DEAD)
    {
        if ((int)timestamp_diff(time_of_last_meal) > time_to_die)
        {
            pthread_mutex_lock(&philo->lock);
            philo->state = DEAD;
            pthread_mutex_lock(philo->printable);
            printf("%llu %d died\n", timestamp_diff(philo->start), philo->index);
            // printf("%llu\tPhilo %d died\n", timestamp_diff(philo->start), philo->index);
            pthread_mutex_unlock(philo->printable);
            pthread_mutex_unlock(&philo->lock);
            return (1);
        }
    }
    return (0);
}

// ============================= ROUTINE =====================================

void    *routine(void *arg)
{
    t_philo *philo;
    int     is_alive;

    philo = (t_philo *)arg;
    is_alive = 1;
    while (is_alive)
    {
        is_alive = goto_eat(philo);
        if (!is_alive)
            break ;
        is_alive = goto_sleep(philo);
        if (!is_alive)
            break ;
        is_alive = goto_think(philo);
    }
    return (0);
}

void    *routine_kill(void *arg)
{
    t_reaper  *reaper;
    int       i;

    reaper = (t_reaper *)arg;
    while (reaper->souls < reaper->n)
    {
        i = -1;
        while ((++i < reaper->n) && (reaper->souls < reaper->n))
            reaper->souls += check_soul(&reaper->vars->philo[i]);
    }
    return (0);
}

// ============================= MAIN =====================================

int main(void)
{
    t_vars  vars;
    int     i;

    // ============= VARS ===============

    vars.n = 10;
    vars.time_to_die = 410;
    vars.time_to_eat = 100;
    vars.time_to_sleep = 400;
    vars.start = timestamp_ms();

    vars.philo = malloc(sizeof(t_philo) * vars.n);
    if (!vars.philo)
        perror("Failed to malloc philos");
    vars.th = malloc(sizeof(pthread_t) * vars.n);
    if (!vars.th)
        perror("Failed to malloc threads");
    vars.fk = malloc(sizeof(pthread_mutex_t) * vars.n);
    if (!vars.fk)
        perror("Failed to malloc fork mutexes");

    i = -1;
    while (++i < vars.n)
        if (pthread_mutex_init(&vars.fk[i], NULL) != 0)
            perror("Failed to create fork mutex");

    if (pthread_mutex_init(&vars.printable, NULL) != 0)
            perror("Failed to create printable mutex");
    

    // =====================================

    i = -1;
    while (++i < vars.n)
    {
        vars.philo[i].start = vars.start;
        vars.philo[i].time_of_last_meal = vars.start;
        vars.philo[i].index = i + 1;
        vars.philo[i].state = THINKING;
        vars.philo[i].printable = &vars.printable;
        vars.philo[i].time_to_die = vars.time_to_die;
        vars.philo[i].time_to_eat = vars.time_to_eat;
        vars.philo[i].time_to_sleep = vars.time_to_sleep;

        vars.philo[i].fk_left = &vars.fk[(i + vars.n) % vars.n];
        vars.philo[i].fk_right = &vars.fk[(i + 1) % vars.n];
        if (i + 1 == vars.n)
        {
            vars.philo[i].fk_left = &vars.fk[(i + 1) % vars.n];
            vars.philo[i].fk_right = &vars.fk[(i + vars.n) % vars.n];
        }

        if (pthread_mutex_init(&vars.philo[i].lock, NULL) != 0)
            perror("Failed to create philo lock mutex");
    
        if (pthread_create(&vars.th[i], NULL, &routine, (void *)&vars.philo[i]) != 0)
            perror("Failed to create philo thread");
    }

    vars.reaper.n = vars.n;
    vars.reaper.souls = 0;
    vars.reaper.vars = &vars;

    if (pthread_create(&vars.th_kill, NULL, &routine_kill, (void *)&vars.reaper) != 0)
        perror("Failed to create killer thread");

    // =====================================

    i = -1;
    while (++i < vars.n)
        if (pthread_join(vars.th[i], NULL) != 0)
            perror("Failed to join thread");

    if (pthread_join(vars.th_kill, NULL) != 0)
        perror("Failed to join killer thread");

    free(vars.th);
    free(vars.fk);
    free(vars.philo);

    // =====================================

    return (0);
}

