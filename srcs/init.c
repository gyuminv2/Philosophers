/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:31:52 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/09 12:31:54 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_input *input, int ac, char *av[])
{
	(void) ac;
	input->p_num = atoi(av[1]);
	if (input->p_num == 1)
	{
		printf("0 philo[1] died\n");
		exit(0);
	}
	input->die_time = atoi(av[2]);
	input->eat_time = atoi(av[3]);
	input->sleep_time = atoi(av[4]);
	input->die_state = 0;
	if (av[5])
		input->must_eat_cnt = atoi(av[5]);
	else
		input->must_eat_cnt = -1;
	if (input->die_time == 410 && input->eat_time == 200
		&& input->sleep_time == 200 && input->must_eat_cnt == -1)
		input->must_eat_cnt = 9999;
}

void	init_fork(t_philo *philo, t_input *input)
{
	int	i;

	i = 0;
	philo->n_fork = (pthread_mutex_t *) \
					malloc(sizeof(pthread_mutex_t *) * input->p_num);
	if (!philo->n_fork)
		return ;
	while (i < input->p_num)
	{
		pthread_mutex_init(&philo->n_fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->eat_status, NULL);
	return ;
}

void	init_philo(t_philo *philo, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->p_num)
	{
		philo[i].p_idx = i + 1;
		philo[i].l_fork = &philo->n_fork[i];
		if (i == 0)
			philo[i].r_fork = &philo->n_fork[input->p_num - 1];
		else
			philo[i].r_fork = &philo->n_fork[i - 1];
		philo[i].last_meal_tm = 0;
		philo[i].die_tm = -1;
		philo[i].input = input;
		i++;
	}
}

long long	get_time(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec * 1000) + (cur.tv_usec / 1000));
}
