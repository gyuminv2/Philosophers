#include "philo_bonus.h"

sem_t   *ft_sem_init(char *name, int value)
{
    sem_t   *new;

    new = sem_open(name, O_CREAT | O_EXCL, 0644, value);
    if (new != SEM_FAILED)
        return (new);
    sem_unlink(name);
    new = sem_open(name, O_CREAT | O_EXCL, 0644, value);
    return (new);
}

void    init_input(t_root *root, char **av)
{
    root->philo_num = ft_atoi(av[1]);
    root->die_tm = ft_atoi(av[2]);
    root->eat_tm = ft_atoi(av[3]);
    root->sleep_tm = ft_atoi(av[4]);
    if (av[5])
        root->must_eat_cnt = ft_atoi(av[5]);
    else
        root->must_eat_cnt = 0;
}

int init_philos(t_root   *root)
{
    int i;

    i = 0;
    root->play = ft_sem_init("play", TRUE);
    root->stop = ft_sem_init("stop", FALSE);
    root->clear_philo = ft_sem_init("clear_philo", FALSE);
    root->n_fork = ft_sem_init("n_fork", root->philo_num); // + 1 ???
    root->philos = (t_philos *)malloc(sizeof(t_philos) * root->philo_num);
    if (!root->philos)
        return (FALSE);
    while (i < root->philo_num)
    {
        root->philos[i].p_idx = i + 1;
        root->philos[i].name = ft_itoa(i);
        root->philos[i].status = ft_sem_init(root->philos[i].name, 1);
        root->philos[i].root = root;
        i++;
    }
    return (TRUE);
}

int init(t_root *root, char **av)
{
    init_input(root, av);
    if (init_philos(root) == FALSE)
        return (FALSE);
    return (TRUE);
}