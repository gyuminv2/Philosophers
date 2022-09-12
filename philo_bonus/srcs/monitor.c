/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:11 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:20:12 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitorring_thread(void *root)
{
	t_root	*rt;
	int		i;

	rt = (t_root *)root;
	sem_wait(rt->stop);
	i = 0;
	while (i < rt->philo_num)
		kill(rt->philos[i++].pid, SIGTERM);
	return (NULL);
}

void	*monitorring_eat(void *root)
{
	t_root	*rt;
	int		i;

	rt = (t_root *)root;
	i = 0;
	while (i++ < rt->philo_num)
		sem_wait(rt->clear_philo);
	sem_post(rt->stop);
	return (NULL);
}

void	*monitorring_die(void *philo)
{
	t_philos		*pho;
	struct timeval	cur;

	pho = (t_philos *)philo;
	while (1)
	{
		sem_wait(pho->root->play);
		gettimeofday(&cur, NULL);
		if (get_time(cur) - get_time(pho->last_meal_tm) >= pho->root->die_tm)
		{
			printf("%lld %d %s\n", get_time(cur) - \
				get_time(pho->root->start_tm), pho->p_idx, "is died");
			sem_post(pho->root->stop);
			return (NULL);
		}
		sem_post(pho->root->play);
	}
	return (NULL);
}
