/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:09 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/11 17:20:10 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_free(t_root *root)
{
	int	status;
	int	i;

	i = 0;
	while (i < root->philo_num)
	{
		waitpid(root->philos[i].pid, &status, 0);
		free(root->philos[i].name);
		i++;
	}
	free(root->philos);
	sem_close(root->play);
	sem_close(root->stop);
	sem_close(root->clear_philo);
	sem_close(root->n_fork);
}

void	fork_play_philos(t_root *root)
{
	int	i;

	i = 0;
	gettimeofday(&root->start_tm, NULL);
	while (i < root->philo_num)
	{
		root->philos[i].last_meal_tm = root->start_tm;
		root->philos[i].pid = fork();
		if (root->philos[i].pid == 0)
		{
			play_philo(&root->philos[i]);
			return ;
		}
		else if (root->philos[i].pid < 0)
		{
			printf("ERROR: FAILED FORK\n");
			exit(TRUE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_root		*root;
	pthread_t	m_thread;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == FALSE)
		return (FALSE);
	if (check_input(ac, av) == FALSE)
		return (FALSE);
	if (init(root, av) == FALSE)
		return (FALSE);
	fork_play_philos(root);
	pthread_create(&m_thread, NULL, monitorring_thread, (void *)root);
	if (root->must_eat_cnt != 0)
		pthread_create(&m_thread, NULL, monitorring_eat, (void *)root);
	wait_free(root);
}
