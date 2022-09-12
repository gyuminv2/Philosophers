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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <semaphore.h>
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define TRUE 1
# define FALSE 0
# define NUM_0 0
# define NUM_1 1

typedef struct s_philos
{
	int				p_idx;
	int				total_eat;
	char			*name;
	pid_t			pid;
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
	sem_t			*play;
	sem_t			*stop;
	sem_t			*clear_philo;
	sem_t			*n_fork;
	struct timeval	start_tm;
	t_philos		*philos;
}	t_root;

/*
 *	main.c
 */
int			check_input(int ac, char *av[]);

/*
 *	init.c
 */
int			init(t_root *root, char **av);

/*
 *	philo.c
 */
void		play_philo(t_philos *philo);

/*
 *	monitor.c
 */
void		*monitorring_thread(void *root);
void		*monitorring_eat(void *root);
void		*monitorring_die(void *philo);

/*
 *	util.c
 */
long long	get_time(struct timeval cur);
void		print_msg(t_philos *philo, char *msg);

#endif
