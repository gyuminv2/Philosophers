/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:31:57 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/09 12:31:58 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_philo *philo, t_input *input)
{
	int	i;
	int	create_ret;

	philo->start_tm = get_time();
	i = 0;
	while (i < input->p_num)
	{
		philo[i].born_tm = get_time();
		create_ret = pthread_create(&philo[i].p_thread, NULL, \
				play_philo, (void *)&philo[i]);
		if (create_ret != 0)
		{
			printf("thread create FAIL\n");
			return (1);
		}
		i++;
	}
	if (philo->input->die_state)
		return (0);
	return (0);
}

void	*play_philo(void *philo)
{
	t_philo	*pho;
	int		eatting;
	char	*rtn;

	pho = (t_philo *)philo;
	eatting = pho->input->must_eat_cnt;
	rtn = ft_itoa(pho->p_idx);
	while (!pho->input->die_state && eatting)
	{
		eat(pho);
		if (die_philo(pho, eatting))
			return (rtn);
		if (pho->input->die_state)
			break ;
		sleep_think(pho);
		if (die_philo(pho, eatting))
			return (rtn);
		if (eatting != -1)
			eatting--;
	}
	free(rtn);
	return (ft_strdup(""));
}

int	die_philo(t_philo *philo, int eatting)
{
	if ((get_time() - philo->last_meal_tm) <= philo->input->die_time)
		return (0);
	if (eatting != -1)
		return (0);
	philo->die_tm = get_time();
	philo->input->die_state = 1;
	return (1);
}

int	join_thread(t_philo *philo)
{
	int		i;
	void	*ret;

	i = 0;
	while (i < philo->input->p_num)
	{
		if (pthread_join(philo[i++].p_thread, &ret) != 0)
		{
			printf("pthread_join is FAIL\n");
			return (-1);
		}
		if (ft_atoi((char *)ret) != 0)
		{
			d_print_free(philo, ret);
			free(ret);
			return (0);
		}
	}
	if (ft_atoi((char *)ret) == 0)
	{
		printf("EVERYONE EAT\n");
		free(ret);
		return (0);
	}
	return (0);
}

void	d_print_free(t_philo *philo, void *ret)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo[ft_atoi((char *)ret) - 1].eat_status);
	printf("%ld phlio[%s] died\n", \
			philo[ft_atoi((char *)ret) - 1].die_tm \
			- philo->start_tm, (char *)ret);
	while (i < philo->input->p_num)
	{
		pthread_mutex_destroy(&philo->n_fork[i]);
		pthread_detach(philo[i].p_thread);
		i++;
	}
	pthread_mutex_unlock(&philo[ft_atoi((char *)ret) - 1].eat_status);
	pthread_mutex_destroy(&(philo->eat_status));
}
