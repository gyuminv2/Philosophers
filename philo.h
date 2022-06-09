#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <sys/time.h>

# define INT_Min -2147483648
# define INT_Max 2147483647

typedef struct s_input
{
	int				p_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_cnt;
	//int				die;
}	t_input;


typedef struct	s_philo
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*n_fork;
	pthread_mutex_t	*eat_status;
	pthread_t		p_thread;
	int				p_idx;
	int				born_tm;
	long			last_meal_tm;
	//int				die_tm;
	t_input			*input;
}	t_philo;

int		check_ac_av(int ac, char *av[]);
void	init_input(t_input *input, int ac, char *av[]);
void	init_philo(t_philo *philo, t_input *input);
int		create_thread(t_philo *philo,t_input *input);
void    init_fork(t_philo *philo, t_input *input);

#endif
