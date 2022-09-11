/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:15 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:20:16 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(struct timeval cur)
{
	long long	ms;

	ms = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (ms);
}

void	print_msg(t_philos *philo, char *msg)
{
	struct timeval	cur;

	sem_wait(philo->root->play);
	gettimeofday(&cur, NULL);
	printf("%lld %d %s\n", get_time(cur) - \
		get_time(philo->root->start_tm), philo->p_idx, msg);
	sem_post(philo->root->play);
}
