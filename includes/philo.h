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

typedef struct s_input
{
	int				p_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_cnt;
	int				die_state;
}	t_input;

typedef struct s_philo
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*n_fork;
	pthread_mutex_t	eat_status;
	pthread_t		p_thread;
	int				p_idx;
	long			start_tm;
	long			born_tm;
	long			last_meal_tm;
	long			die_tm;
	t_input			*input;
}	t_philo;

/*
 *	main.c
 */
int			check_input(int ac, char *av[]);

/*
 *	init.c
 */
void		init_input(t_input *input, int ac, char *av[]);
void		init_philo(t_philo *philo, t_input *input);
void		init_fork(t_philo *philo, t_input *input);
long long	get_time(void);

/*
 *	thread.c
 */
int			create_thread(t_philo *philo, t_input *input);
void		*play_philo(void *philo);
void		eat(t_philo *philo);
int			die_philo(t_philo *philo);
void		sleep_think(t_philo *philo);
int			join_thread(t_philo *philo);

#endif
