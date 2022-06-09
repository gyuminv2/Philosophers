#include "philo.h"

long    get_time()
{
    struct  timeval ms;

    gettimeofday(&ms, NULL);
    return (ms.tv_usec);
}

void    init_fork(t_philo *philo, t_input *input)
{
    int i;

    i = 0;
    philo->n_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *) * input->p_num);
    if (!philo->n_fork)
        return ;
    while (i < input->p_num)
    {
        pthread_mutex_init(&philo->n_fork[i], NULL);
        i++;
    }
    //pthread_mutex_init(&philo->eat_status, NULL);
    return ;
}

void    init_philo(t_philo *philo, t_input *input)
{
    int i = 0;

    init_fork(philo, input);
    while (i < input->p_num)
    {
        philo[i].p_idx = i + 1;
        philo[i].input = input;
        philo[i].born_tm = get_time();
        philo[i].last_meal_tm = 0;
        philo[i].l_fork = &philo->n_fork[i];
        philo[i].r_fork = &philo->n_fork[input->p_num - 1];
        i++;
    }
}

void    init_input(t_input *input, int ac, char *av[])
{
    input->p_num = atoi(av[1]);
    if (input->p_num == 1)
    {
        printf("0 #1 die\n");
        exit(0);
    }
    input->die_time = atoi(av[2]);
    input->eat_time = atoi(av[3]);
    input->sleep_time = atoi(av[4]);
    if (av[5])
        input->must_eat_cnt = atoi(av[5]);
    else
        input->must_eat_cnt = 0;
}