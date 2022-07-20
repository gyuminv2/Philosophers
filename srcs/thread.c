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
		if (die_philo(pho) && eatting == -1)
		{
			pho->input->die_state = 1;
			return (rtn);
		}
        if (pho->input->die_state)
            break;
		sleep_think(pho);
		if (die_philo(pho) && eatting == -1)
		{
			pho->input->die_state = 1;
			return (rtn);
		}
		if (eatting != -1)
			eatting--;
	}
	free(rtn);
	return (ft_strdup(""));
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
	philo->last_meal_tm = get_time();
	printf("%lld phlio[%d] has taken a l_fork\n", \
			get_time() - philo->born_tm, philo->p_idx);
	printf("%lld phlio[%d] has taken a r_fork\n", \
			get_time() - philo->born_tm, philo->p_idx);
	pthread_mutex_lock(&philo->eat_status);
    if (philo->input->die_state)
    {
        printf("3\n");
    }
	printf("%lld phlio[%d] is a eating\n", \
			get_time() - philo->born_tm, philo->p_idx);
	pthread_mutex_unlock(&philo->eat_status);
	usleep(philo->input->eat_time * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleep_think(t_philo *philo)
{
	printf("%lld phlio[%d] is sleeping\n", \
			get_time() - philo->born_tm, philo->p_idx);
	usleep(philo->input->sleep_time * 1000);
	printf("%lld phlio[%d] is thinking\n", \
			get_time() - philo->born_tm, philo->p_idx);
}

int	die_philo(t_philo *philo)
{
	if ((get_time() - philo->last_meal_tm) <= philo->input->die_time)
		return (0);
	philo->die_tm = get_time();
	return (1);
}

int	join_thread(t_philo *philo)
{
	int		i;
	void	*ret;

	i = 0;
	while (i < philo->input->p_num)
	{
		if (pthread_join(philo[i].p_thread, &ret) != 0)
		{
			printf("pthread_join is FAIL\n");
			return (-1);
		}
		if (ft_atoi((char *)ret) != 0)
		{
            pthread_mutex_lock(&philo[ft_atoi((char *)ret) - 1].eat_status);
			printf("%ld phlio[%s] died\n", \
					philo[ft_atoi((char *)ret) - 1].die_tm \
					- philo->start_tm, (char *)ret);
            int i;
            i = 0;
            while (i < philo->input->p_num)
            {
                pthread_mutex_destroy(&philo->n_fork[i]);
                pthread_detach(philo[i].p_thread);
                i++;
            }
            pthread_mutex_unlock(&philo[ft_atoi((char *)ret) - 1].eat_status);
            pthread_mutex_destroy(&(philo->eat_status));
			free(ret);
			return (0);
		}
		i++;
	}
	if (ft_atoi((char *)ret) == 0)
	{
		printf("EVERYONE EAT\n");
		free(ret);
		return (0);
	}
	return (0);
}
