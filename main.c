#include "philo.h"

int	main(int ac, char *av[])
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!all)
		return (-1);
	//if (check_ac_av(ac, av) != 0)
	//	return (-1);
	init_all(all, ac, av);
	//launch_threads
	//join_threads
	//free_all(all);
	return (0);
}
