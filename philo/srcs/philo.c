/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:17:08 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:18:43 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int t)
{
	struct timeval	cur;
	long long		start;

	gettimeofday(&cur, NULL);
	start = get_time(cur);
	while (get_time(cur) < start + t)
	{
		gettimeofday(&cur, NULL);
		usleep(300);
	}
}

int	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (is_stop(philo) == STOP)
		return (STOP);
	pthread_mutex_lock(&philo->root->write_mutex);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	if (is_stop(philo) == STOP)
		return (STOP);
	pthread_mutex_lock(&philo->root->write_mutex);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->root->write_mutex);
	print_msg(philo, "is eating");
	gettimeofday(&philo->last_meal_tm, NULL);
	if (stop(philo, NUM_2) == STOP)
		return (STOP);
	pthread_mutex_lock(&philo->root->stop_mutex);
	philo->total_eat++;
	if (philo->total_eat == philo->root->must_eat_cnt)
	{
		philo->root->philo_clear++;
		if (stop(philo, NUM_1) == STOP)
			return (STOP);
	}
	stop(philo, NUM_0);
	return (GO);
}

int	sleep_think(t_philos *philo)
{
	if (is_stop(philo) == STOP)
		return (STOP);
	pthread_mutex_lock(&philo->root->write_mutex);
	print_msg(philo, "is sleeping");
	pthread_mutex_lock(&philo->root->write_mutex);
	print_msg(philo, "is thinking");
	ft_usleep(philo->root->sleep_tm);
	return (GO);
}

void	*play_philo(void *philo)
{
	t_philos	*pho;

	pho = (t_philos *)philo;
	if (pho->p_idx % 2 != 0)
		ft_usleep(pho->root->eat_tm);
	while (!usleep(300))
	{
		if (eat(pho) == STOP)
			break ;
		if (is_stop(pho) == STOP)
			break ;
		if (sleep_think(pho) == STOP)
			break ;
		if (is_stop(pho) == STOP)
			break ;
	}
	return (NULL);
}
