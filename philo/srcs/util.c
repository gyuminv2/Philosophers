/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:17:13 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/14 15:18:28 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_free(t_root *root)
{
	free(root->philos);
	free(root->n_fork);
	free(root);
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

	gettimeofday(&cur, NULL);
	if (is_stop(philo) == GO)
	{
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(philo->root->start_tm), philo->p_idx, msg);
		pthread_mutex_unlock(&philo->root->write_mutex);
	}
	else
	{
		printf("%lld %d %s\n", get_time(cur) - \
				get_time(philo->root->start_tm), philo->p_idx, msg);
		pthread_mutex_unlock(&philo->root->write_mutex);
	}
}

int	is_stop(t_philos *philo)
{
	pthread_mutex_lock(&philo->root->stop_mutex);
	if (philo->root->stop_state == DIE)
	{
		pthread_mutex_unlock(&philo->root->stop_mutex);
		return (STOP);
	}
	else
	{
		pthread_mutex_unlock(&philo->root->stop_mutex);
		return (GO);
	}
}

int	stop(t_philos *philo, int flag)
{
	if (flag == NUM_0)
	{
		pthread_mutex_unlock(&philo->root->stop_mutex);
		ft_usleep(philo->root->eat_tm);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	if (flag == NUM_1)
	{
		pthread_mutex_unlock(&philo->root->stop_mutex);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (STOP);
	}
	if (is_stop(philo) == STOP)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (STOP);
	}
	return (GO);
}
