/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:17:11 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:17:12 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_join(t_root *root)
{
	int	i;

	i = 0;
	while (i < root->philo_num)
	{
		pthread_join(root->philos[i].p_thread, NULL);
		i++;
	}
	all_free(root);
}

void	thread_create(t_root *root)
{
	int			i;
	pthread_t	m_thread;

	i = 0;
	gettimeofday(&root->start_tm, NULL);
	while (i < root->philo_num)
	{
		root->philos[i].last_meal_tm = root->start_tm;
		pthread_create(&root->philos[i].p_thread, NULL, \
				play_philo, (void *)&root->philos[i]);
		pthread_create(&m_thread, NULL, monitorring_thread, \
				(void *)&root->philos[i]);
		i++;
		pthread_detach(m_thread);
	}
}
