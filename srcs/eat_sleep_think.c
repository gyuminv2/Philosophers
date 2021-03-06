/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:22:12 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/22 12:14:12 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(10);
}

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
	printf("%lld phlio[%d] has taken a l_fork\n", \
			get_time() - philo->born_tm, philo->p_idx);
	printf("%lld phlio[%d] has taken a r_fork\n", \
			get_time() - philo->born_tm, philo->p_idx);
	pthread_mutex_lock(&philo->eat_status);
	printf("%lld phlio[%d] is a eating\n", \
			get_time() - philo->born_tm, philo->p_idx);
	philo->last_meal_tm = get_time();
	pthread_mutex_unlock(&philo->eat_status);
	ft_usleep(philo->input->eat_time);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleep_think(t_philo *philo)
{
	printf("%lld phlio[%d] is sleeping\n", \
			get_time() - philo->born_tm, philo->p_idx);
	ft_usleep(philo->input->sleep_time);
	printf("%lld phlio[%d] is thinking\n", \
			get_time() - philo->born_tm, philo->p_idx);
	usleep(1000 * 11);
}
