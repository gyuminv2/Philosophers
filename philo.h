#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>

# define INT_Min -2147483648
# define INT_Max 2147483647

typedef struct	s_fork
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_fork;

typedef struct	s_philo
{
	t_fork			*fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				p_id;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_cnt;
}	t_philo;

typedef struct	s_all
{

}	t_all;

int	check_ac_av(int ac, char *av[]);

#endif
