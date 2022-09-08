#include "philo.h"

void	all_free(t_root *root)
{
	// int	i;

	// i = 0;
	// while (i < root->philo_num)
	// {
	// 	pthread_mutex_destroy(&root->n_fork[i]);
	// 	i++;
	// }
	free(root->philos);
	free(root->n_fork);
}

long long	get_time(struct timeval cur)
{
	long long	ms;

	ms = (cur.tv_sec * 1000) + (cur.tv_usec * 0.001);
	return (ms);
}

void	print_msg(t_philos *philo, char *msg)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->root->stop_mutex);
	gettimeofday(&cur, NULL);
	// if (philo->root->stop_state == 0)
	// {
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(philo->root->start_tm), philo->p_idx, msg);
	// }
	pthread_mutex_unlock(&philo->root->stop_mutex);
}
