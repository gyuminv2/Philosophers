#include "philo.h"

int	stop(t_philos *philo, int flag)
{
	if (philo->root->stop_state == 1)
	{
		pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_unlock(&philo->root->mutex_status);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (STOP);
	}
	if (flag == NUM_1)
	{
		pthread_mutex_unlock(&philo->root->must_eat_mutex);
		pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_unlock(&philo->root->mutex_status);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (STOP);
	}
	return (GO);
}

void	ft_usleep(int t)
{
	struct timeval	cur;
	long long		start;

	gettimeofday(&cur, NULL);
	start = get_time(cur);
	while (get_time(cur) < start + t)
	{
		gettimeofday(&cur, NULL);
		usleep(200);
	}
}

int	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->root->mutex_status);
	gettimeofday(&philo->last_meal_tm, NULL);
	pthread_mutex_lock(&philo->root->stop_mutex);
	if (stop(philo, NUM_0) == STOP)
		return (STOP);
	printf("%lld %d %s\n", get_time(philo->last_meal_tm) - \
			get_time(philo->root->start_tm), philo->p_idx, "is eating");
	philo->total_eat++;
	if (philo->total_eat == philo->root->must_eat_cnt)
	{
		pthread_mutex_lock(&philo->root->must_eat_mutex);
		philo->root->philo_clear++;
		if (stop(philo, NUM_1) == STOP)
			return (STOP);
		// pthread_mutex_unlock(&philo->root->stop_mutex);
		// pthread_mutex_unlock(&philo->root->mutex_status);
		// pthread_mutex_unlock(philo->l_fork);
		// pthread_mutex_unlock(philo->r_fork);
	}
	pthread_mutex_unlock(&philo->root->stop_mutex);
	pthread_mutex_unlock(&philo->root->mutex_status);
	ft_usleep(philo->root->eat_tm);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (SUCCESS);
}

void	sleep_think(t_philos *philo)
{
	print_msg(philo, "is sleeping");
	print_msg(philo, "is thinking");
	ft_usleep(philo->root->sleep_tm);
}

void	*play_philo(void *philo)
{
	t_philos	*pho;

	pho = (t_philos *)philo;
	if (pho->p_idx % 2 != 0)
		ft_usleep(pho->root->eat_tm);
	while (1)
	{
		if (eat(pho) == FAIL)
			break;
		sleep_think(pho);
		// pthread_mutex_lock(&pho->root->stop_mutex);
		// if (pho->root->stop_state == 1)
		// {
		// 	pthread_mutex_unlock(&pho->root->stop_mutex);
		// 	break ;
		// }
		// pthread_mutex_unlock(&pho->root->stop_mutex);
	}
	return (NULL);
}
