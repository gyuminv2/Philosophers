#include "philo.h"

void    *play_philo(void *philo)
{
    t_philo *pho;
    
    pho = (t_philo *)philo;
}

int create_thread(t_philo *philo,t_input *input)
{
    int i;
    int create_ret;

    i = 0;
    while (i < input->p_num)
    {
        create_ret = pthread_create(&philo[i].p_thread, NULL, play_philo, (void *)&philo[i]);
        if (create_ret != 0)
        {
            printf("thread create FAIL\n");
            return (-1);
        }
        i++;
    }
    return (0);
}