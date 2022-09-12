/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:17:05 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:18:14 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die_check(t_philos *philo)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->root->write_mutex);
	pthread_mutex_lock(&philo->root->stop_mutex);
	gettimeofday(&cur, NULL);
	if (get_time(cur) - get_time(philo->last_meal_tm) >= \
			philo->root->die_tm)
	{
		philo->root->stop_state = DIE;
		pthread_mutex_unlock(&philo->root->stop_mutex);
		usleep(300);
		pthread_mutex_lock(&philo->root->die_mutex);
		print_msg(philo, "is died");
		return (STOP);
	}
	if (philo->root->philo_num == philo->root->philo_clear)
	{
		philo->root->stop_state = DIE;
		pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_unlock(&philo->root->write_mutex);
		return (STOP);
	}
	pthread_mutex_unlock(&philo->root->stop_mutex);
	pthread_mutex_unlock(&philo->root->write_mutex);
	return (GO);
}

int	monitorring_die(t_philos *philo)
{
	if (is_stop(philo) == STOP)
	{
		return (STOP);
	}
	if (die_check(philo) == STOP)
	{
		return (STOP);
	}
	return (GO);
}

void	*monitorring_thread(void *philo)
{
	t_philos		*pho;

	pho = (t_philos *)philo;
	while (!usleep(300))
	{
		if (monitorring_die(pho) == STOP)
		{
			break ;
		}
	}
	return (NULL);
}
