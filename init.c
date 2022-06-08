#include "philo.h"

void    init_all(t_all *all, int ac, char *av[])
{
    all->philo->p_num = atoi(av[1]);
    all->philo->die_time = atoi(av[2]);
    all->philo->eat_time = atoi(av[3]);
    all->philo->sleep_time = atoi(av[4]);
    if (av[5])
        all->philo->must_eat_cnt = atoi(av[5]);
    else
        all->philo->must_eat_cnt = 0;
    printf("%d\n", all->philo->p_num);
    printf("%d\n", all->philo->die_time);
    printf("%d\n", all->philo->eat_time);
    printf("%d\n", all->philo->sleep_time);
    printf("%d\n", all->philo->must_eat_cnt);
}
