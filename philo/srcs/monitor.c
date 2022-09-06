#include "philo.h"

void	die_check(t_philos *philo)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	pthread_mutex_lock(&philo->root->stop_mutex);
	if (get_time(cur) - get_time(philo->last_meal_tm) >= \
			philo->root->die_tm)
	{
		philo->root->stop_state = 1;
		pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_lock(&philo->root->mutex_status);
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(philo->root->start_tm), philo->p_idx, "is died");
	}
	pthread_mutex_unlock(&philo->root->stop_mutex);
}

void	monitorring_eat(t_philos *philo)
{
		while (1)
		{
			pthread_mutex_lock(&philo->root->stop_mutex);
			if (philo->root->philo_num == philo->root->philo_clear)
			{
				philo->root->stop_state = 1;
				pthread_mutex_unlock(&philo->root->stop_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->root->stop_mutex);
		}
}

void	monitorring_die(t_philos *philo)
{
	while (1)
	{
		die_check(philo);
		pthread_mutex_unlock(&philo->root->mutex_status);
		pthread_mutex_lock(&philo->root->stop_mutex);
		if (philo->root->stop_state == 1)
		{
			pthread_mutex_unlock(&philo->root->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->root->stop_mutex);
	}
}

void	*monitorring_eating(void *philo)
{
	t_philos	*pho;

	pho = (void *)philo;
	monitorring_eat(pho);
	return (NULL);
}

void	*monitorring_thread(void *philo)
{
	t_philos		*pho;

	pho = (void *)philo;
							if (pho->root->must_eat_cnt != 0)
							{
								while (1)
								{
									pthread_mutex_lock(&pho->root->stop_mutex);
									if (pho->root->philo_num == pho->root->philo_clear)
									{
										pho->root->stop_state = 1;
										pthread_mutex_unlock(&pho->root->stop_mutex);
										break ;
									}
									pthread_mutex_unlock(&pho->root->stop_mutex);
								}
							}
							while (1)
							{
								die_check(pho);
								pthread_mutex_unlock(&pho->root->mutex_status);
								pthread_mutex_lock(&pho->root->stop_mutex);
								if (pho->root->stop_state == 1)
								{
									pthread_mutex_unlock(&pho->root->stop_mutex);
									break ;
								}
								pthread_mutex_unlock(&pho->root->stop_mutex);
							}
	return (NULL);
}
