/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:30:51 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/09 12:30:51 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0
# define GO 1
# define DIE 1
# define STOP 0
# define NUM_0 0
# define NUM_1 1
# define NUM_2 2

typedef struct s_philos
{
	int				p_idx;
	int				total_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		p_thread;
	struct s_root	*root;
	struct timeval	last_meal_tm;
}	t_philos;

typedef struct s_root
{
	int				philo_num;
	int				die_tm;
	int				eat_tm;
	int				sleep_tm;
	int				must_eat_cnt;
	int				stop_state;
	int				philo_clear;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	*n_fork;
	struct timeval	start_tm;
	t_philos		*philos;
}	t_root;

/**
 *	main.c
 */
int			check_input(int ac, char *av[]);

/**
 *	init.c
 */
int			init(t_root *root, char **av);

/**
 *	thread.c
 */
void		thread_create(t_root *root);
void		thread_join(t_root *root);

/**
 *	philo.c
 */
void		*play_philo(void *philo);
int			stop(t_philos *philo, int flag);

/**
 *	monitor.c
 */
void		*monitorring_thread(void *philo);
void		*monitorring_eating(void *philo);

/**
 *	util.c
 */
void		all_free(t_root *root);
long long	get_time(struct timeval cur);
void		print_msg(t_philos *philo, char *msg);
int			is_stop(t_philos *philo);
void		ft_usleep(int t);

#endif