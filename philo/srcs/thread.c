#include "philo.h"

void	thread_join(t_root *root)
{
	int	i;

	i = 0;
	while (i < root->philo_num)
	{
		pthread_join(root->philos[i].p_thread, NULL);
		pthread_mutex_destroy(&root->mutex_status);
		pthread_mutex_destroy(&root->stop_mutex);
		i++;
	}
	all_free(root);
}

void	thread_create(t_root *root)
{
	int			i;
	pthread_t	m_thread;
	pthread_t	e_thread;

	gettimeofday(&root->start_tm, NULL);
	i = 0;
	while (i < root->philo_num)
	{
		root->philos[i].last_meal_tm = root->start_tm;
		pthread_create(&root->philos[i].p_thread, NULL, \
				play_philo, (void *)&root->philos[i]);
		pthread_create(&m_thread, NULL, monitorring_thread, \
				(void *)&root->philos[i]);
		// if (root->must_eat_cnt != 0)
		// {
		// 	pthread_create(&e_thread, NULL, monitorring_eating, \
		// 			(void *)&root->philos[i]);
		// }
		pthread_detach(m_thread);
		pthread_detach(e_thread);
		i++;
	}
}
