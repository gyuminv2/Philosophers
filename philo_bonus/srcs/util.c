#include "philo_bonus.h"

long long   get_time(struct timeval cur)
{
    long long   ms;

    ms = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
    return (ms);
}

void print_msg(t_philos *philo, char *msg)
{
    struct timeval cur;
    
    sem_wait(philo->root->play);
    gettimeofday(&cur, NULL);
    printf("%lld %d %s\n", get_time(cur) - get_time(philo->root->start_tm), philo->p_idx, msg);
    sem_post(philo->root->play);
}