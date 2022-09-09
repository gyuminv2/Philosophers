#include "philo.h"

int	die_check(t_philos *philo)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->root->stop_mutex);
	gettimeofday(&cur, NULL);
	if (get_time(cur) - get_time(philo->last_meal_tm) >= \
			philo->root->die_tm)
	{
		philo->root->stop_state = 1;
		pthread_mutex_lock(&philo->root->write_mutex);
		pthread_mutex_unlock(&philo->root->stop_mutex);
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(philo->root->start_tm), philo->p_idx, "is died");
		pthread_mutex_unlock(&philo->root->write_mutex);
		return (0);
	}
	if (philo->root->philo_num == philo->root->philo_clear)
		{
			philo->root->stop_state = 1;
			pthread_mutex_unlock(&philo->root->stop_mutex);
			return (0);
		}
	pthread_mutex_unlock(&philo->root->stop_mutex);
	return (1);
}

int	monitorring_die(t_philos *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->root->stop_mutex);
		if (philo->root->stop_state == 1)
		{
			break ;
		}
		pthread_mutex_unlock(&philo->root->stop_mutex);
		if (die_check(philo) == 0)
			break ;
	}
	return (0);
}

void	*monitorring_thread(void *philo)
{
	t_philos		*pho;

	pho = (void *)philo;
	if (monitorring_die(pho) == STOP)
	{
		// pthread_mutex_unlock(&pho->root->write_mutex);
		pthread_mutex_unlock(&pho->root->stop_mutex);
		return (NULL);
	}
		// exit(1);
	/**	프로세스종료
		=thread die 이후에 출력
		=error 정상출력
	*/

	return (NULL);
}
