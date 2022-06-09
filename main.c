#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_input	*input;

	//if (check_ac_av(ac, av) != 0)
	//	return (-1);
	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (-1);
	init_input(input, ac, av);
	philo = (t_philo *)malloc(sizeof(t_philo) * input->p_num);
	if (!philo)
		return (-1);
	init_fork(philo, input);
	init_philo(philo, input);
	if(create_thread(philo, input))	// 성공시 0
		return (-1);
	int i = 0;
	while (i < input->p_num)
	{
		printf("p_idx: %d\n", philo[i].p_idx);
		printf("born_tm: %d\n", philo[i].born_tm);
		printf("last_meal_tm: %ld\n", philo[i].last_meal_tm);
		if (philo[i].l_fork)
			printf("l_fork: exist\n");
		if (philo[i].r_fork)
			printf("r_fork: exist\n");
		printf("\n");
		i++;
	}
	//launch_threads
	//join_threads
	//free_all(philo);
	return (0);
}
