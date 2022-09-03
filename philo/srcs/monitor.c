#include "philo.h"

void	die_check(t_philos *pho)
{
	struct timeval	cur;

	pthread_mutex_lock(&pho->root->stop_mutex);
	gettimeofday(&cur, NULL);
	if (get_time(cur) - get_time(pho->last_meal_tm) >= \
			pho->root->die_tm)
	{
		pho->root->stop_state = 1;
		pthread_mutex_unlock(&pho->root->stop_mutex);
		pthread_mutex_lock(&pho->root->mutex_status);
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(pho->root->start_tm), pho->p_idx, "is died");
	}
	pthread_mutex_unlock(&pho->root->stop_mutex);
}

void	*monitorring_thread(void *philo)
{
	t_philos		*pho;

	pho = (void *)philo;
	if (pho->root->must_eat_cnt != 0)
	{
		while (1)
		{
			pthread_mutex_unlock(&pho->root->stop_mutex);
			pthread_mutex_lock(&pho->root->stop_mutex);
			// pthread_mutex_lock(&pho->root->mutex_status);
			if (pho->root->philo_num == pho->root->philo_clear)
			{
				pho->root->stop_state = 1;
				pthread_mutex_unlock(&pho->root->stop_mutex);
				// pthread_mutex_unlock(&pho->root->mutex_status);
				break;
			}
		}
		pthread_mutex_unlock(&pho->root->stop_mutex);
		// pthread_mutex_unlock(&pho->root->mutex_status);
	}
	while(1)
	{
		die_check(pho);
		pthread_mutex_unlock(&pho->root->mutex_status);
		pthread_mutex_lock(&pho->root->stop_mutex);
		if (pho->root->stop_state == 1)
		{
			pthread_mutex_unlock(&pho->root->stop_mutex);
			break;
		}
		pthread_mutex_unlock(&pho->root->stop_mutex);
	}
	return (NULL);
}
