#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	if (philo->input->die_state)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	philo->last_meal_tm = get_time();
	printf("%lld phlio[%d] has taken a l_fork\n", \
			get_time() - philo->born_tm, philo->p_idx);
	printf("%lld phlio[%d] has taken a r_fork\n", \
			get_time() - philo->born_tm, philo->p_idx);
	pthread_mutex_lock(&philo->eat_status);
	if (philo->input->die_state)
	{
		printf("3\n");
	}
	printf("%lld phlio[%d] is a eating\n", \
			get_time() - philo->born_tm, philo->p_idx);
	pthread_mutex_unlock(&philo->eat_status);
	usleep(philo->input->eat_time * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleep_think(t_philo *philo)
{
	printf("%lld phlio[%d] is sleeping\n", \
			get_time() - philo->born_tm, philo->p_idx);
	usleep(philo->input->sleep_time * 1000);
	printf("%lld phlio[%d] is thinking\n", \
			get_time() - philo->born_tm, philo->p_idx);
}
