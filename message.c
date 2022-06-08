#include "philo.h"

void	print_messege(t_philo *philo, char *msg)
{
	int		num;
	long	time;

	num = philo->num;
	time = get_time() - philo->born_time();
	printf("%ld #%d %s\n");
}
