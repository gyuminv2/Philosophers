/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:16:59 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:17:01 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_root *root, char **av)
{
	root->philo_num = ft_atoi(av[1]);
	root->die_tm = ft_atoi(av[2]);
	root->eat_tm = ft_atoi(av[3]);
	if (root->philo_num == 1)
	{
		usleep(root->eat_tm * 1000);
		printf("%d 1 has a fork\n", root->eat_tm);
		usleep(root->die_tm * 1000);
		printf("%d 1 is died\n", root->die_tm);
		exit(TRUE);
	}
	root->sleep_tm = ft_atoi(av[4]);
	if (av[5])
		root->must_eat_cnt = ft_atoi(av[5]);
	else
		root->must_eat_cnt = 0;
}

int	init_mem(t_root *root)
{
	root->philos = (t_philos *)malloc(sizeof(t_philos) * root->philo_num);
	root->n_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* root->philo_num);
	if (!root->philos || !root->n_fork)
		return (FALSE);
	return (TRUE);
}

int	init_philos(t_root *root)
{
	int	i;

	i = 0;
	pthread_mutex_init(&root->stop_mutex, NULL);
	pthread_mutex_init(&root->write_mutex, NULL);
	pthread_mutex_init(&root->die_mutex, NULL);
	while (i < root->philo_num)
	{
		root->philos[i].p_idx = i + 1;
		pthread_mutex_init(&root->n_fork[i], NULL);
		if (i == 0)
			root->philos[i].l_fork = &root->n_fork[root->philo_num - 1];
		else
			root->philos[i].l_fork = &root->n_fork[i - 1];
		root->philos[i].r_fork = &root->n_fork[i];
		root->philos[i].root = root;
		i++;
	}
	return (TRUE);
}

int	init(t_root *root, char **av)
{
	init_input(root, av);
	if (init_mem(root) == FALSE)
		return (FALSE);
	if (init_philos(root) == FALSE)
		return (FALSE);
	return (TRUE);
}
