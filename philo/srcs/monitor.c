#include "philo.h"

// void	die_check(t_philos *philo)
// {
// 	struct timeval	cur;

// 	pthread_mutex_lock(&philo->root->stop_mutex);
// 	gettimeofday(&cur, NULL);
// 	if (get_time(cur) - get_time(philo->last_meal_tm) >= \
// 			philo->root->die_tm)
// 	{
// 		philo->root->stop_state = 1;
// 		pthread_mutex_unlock(&philo->root->stop_mutex);
// 		pthread_mutex_lock(&philo->root->mutex_status);
// 		printf("%lld %d %s\n", get_time(cur) - \
// 				get_time(philo->root->start_tm), philo->p_idx, "is died");
// 	}
// 	if (philo->root->philo_num == philo->root->philo_clear)
// 		{
// 			philo->root->stop_state = 1;
// 			pthread_mutex_unlock(&philo->root->stop_mutex);
// 		}
// }

int	die_check(t_philos *philo)
{
	struct timeval	cur;

	// pthread_mutex_lock(&philo->root->stop_mutex);
	gettimeofday(&cur, NULL);
	if (get_time(cur) - get_time(philo->last_meal_tm) >= \
			philo->root->die_tm)
	{
		philo->root->stop_state = 1;
		// pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_lock(&philo->root->mutex_status);
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(philo->root->start_tm), philo->p_idx, "is died");
		return (STOP);
	}
	if (philo->root->philo_num == philo->root->philo_clear)
		{
			philo->root->stop_state = 1;
			pthread_mutex_unlock(&philo->root->stop_mutex);
		}
}

void	monitorring_die(t_philos *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->root->stop_mutex);
		// if (philo->root->stop_state == 1)
		// 	break;
		if (die_check(philo) == STOP)
			break;
		pthread_mutex_unlock(&philo->root->stop_mutex);
		// die_check(philo);
		pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_unlock(&philo->root->mutex_status);
	}
}

void	*monitorring_thread(void *philo)
{
	t_philos		*pho;

	pho = (void *)philo;
	monitorring_die(pho);
	pthread_mutex_unlock(&pho->root->stop_mutex);
	return (NULL);
}
