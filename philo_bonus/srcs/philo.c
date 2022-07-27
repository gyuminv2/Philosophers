#include "philo_bonus.h"

void	eat(t_philos *philo)
{
    sem_wait(philo->root->n_fork);
    print_msg(philo, "has taken a fork");
    sem_wait(philo->root->n_fork);
    print_msg(philo, "has taken a fork");
    sem_wait(philo->status);
    gettimeofday(&philo->last_meal_tm, NULL);
    print_msg(philo, "is eating");
    philo->total_eat++;
    if (philo->total_eat == philo->root->must_eat_cnt)
        sem_post(philo->root->clear_philo);
    usleep(philo->root->eat_tm * 1000);
    sem_post(philo->root->n_fork);
    sem_post(philo->root->n_fork);
    sem_post(philo->status);
}

void	sleep_think(t_philos *philo)
{
    print_msg(philo, "is sleeping");
    usleep(philo->root->sleep_tm * 1000);
    print_msg(philo, "is thinking");
}

void	*play_philo(t_philos *philo)
{
    pthread_t   m_thread;

    pthread_create(&m_thread, NULL, monitorring_die, (void *)philo);
    if (philo->p_idx % 2 != 0)
        usleep(philo->root->eat_tm * 1000);
	while (1)
	{
		eat(philo);
		sleep_think(philo);
	}
    exit(0);
    return (NULL);
}