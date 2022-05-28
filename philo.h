#ifndef
# define

# include <stdlib.h>
# include <pthread.h>
# include <signal.h>

# include <stdio.h> // remove

typedef struct	s_eat
{

}	t_eat;

typedef struct	s_think
{

}	t_think;

typedef struct	s_die
{
	
}	t_die;

typedef struct	s_philosoper
{
	t_eat	eat;
	t_think	think;
	t_die	die;
}	t_philosoper;

#endif
