#include "philo.h"

void	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex_status);
	gettimeofday(&philo->last_meal_tm, NULL);
	pthread_mutex_lock(&philo->root->stop_mutex);
	if (!philo->root->stop_state)
		printf("%lld %d %s\n", get_time(philo->last_meal_tm) - \
			get_time(philo->root->start_tm), philo->p_idx, "is eating");
	philo->total_eat++;
	if (philo->total_eat == philo->root->must_eat_cnt)
		philo->root->philo_clear++;
	pthread_mutex_unlock(&philo->root->stop_mutex);
	usleep(philo->root->eat_tm * 1000);
	pthread_mutex_unlock(&philo->mutex_status);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleep_think(t_philos *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->root->sleep_tm * 1000);
	print_msg(philo, "is thinking");
}

void	*play_philo(void *philo)
{
	t_philos	*pho;

	pho = (t_philos *)philo;
	if (pho->p_idx % 2 != 0)
		usleep(pho->root->eat_tm * 1000);
	while (!pho->root->stop_state)
	{
		eat(pho);
		sleep_think(pho);
	}
	return (NULL);
}
