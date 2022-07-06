#include "philo.h"

int create_thread(t_philo *philo,t_input *input)
{
    int i;
    int create_ret;

    i = 0;
    while (i < input->p_num)
    {
        philo[i].born_tm = get_time();
        create_ret = pthread_create(&philo[i].p_thread, NULL, play_philo, (void *)&philo[i]);
        if (create_ret != 0)
        {
            printf("thread create FAIL\n");
            return (1);
        }
        i++;
    }
    return (0);
}

void    *play_philo(void *philo)
{
    t_philo *pho;
    int     eatting;
    
    pho = (t_philo *)philo;
    eatting = pho->input->must_eat_cnt;

    while (!pho->input->die_state)
    {
        pho->save = ft_itoa(pho->p_idx);
        if (eatting == 0)
            break;
        eat(pho);
        if (die_philo(pho, eatting))
        {
            pho->input->die_state = 1;
            return (pho->save);
        }
        sleep_think(pho);
        if (die_philo(pho, eatting))
        {
            pho->input->die_state = 1;
            return (pho->save);
        }
        free(pho->save);
        if (eatting != 0)
            eatting--;
    }
    return (ft_strdup(""));
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(philo->r_fork);
    printf("%ld phlio[%d] has taken a l_fork\n", get_time() - philo->born_tm, philo->p_idx);
    printf("%ld phlio[%d] has taken a r_fork\n", get_time() - philo->born_tm, philo->p_idx);
    philo->last_meal_tm = get_time();
    pthread_mutex_lock(&philo->eat_status);
    printf("%ld phlio[%d] is a eating\n", get_time() - philo->born_tm, philo->p_idx);
    usleep(philo->input->eat_time * 1000);
    pthread_mutex_unlock(&philo->eat_status);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void    sleep_think(t_philo *philo)
{
    printf("%ld phlio[%d] is sleeping\n", get_time() - philo->born_tm, philo->p_idx);
    usleep(philo->input->sleep_time * 1000);
    printf("%ld phlio[%d] is thinking\n", get_time() - philo->born_tm, philo->p_idx);
}

int     die_philo(t_philo *philo, int eat_cnt)
{
    if (eat_cnt == 0)
        return (1);
    if ((get_time() - philo->last_meal_tm) > philo->input->die_time)
    {
        printf("죽은시간: %ld || %d\n", (get_time() - philo->last_meal_tm), philo->input->die_time);
        philo->die_tm = get_time();
        return (1);
    }
    return (0);
}

int	join_thread(t_philo *philo)
{
	int	i;
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
			printf("%ld phlio[%s] died\n", philo[ft_atoi((char *)ret)-1].die_tm - philo->born_tm, (char *)ret);
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