#include "philo.h"

int	check_input(int ac, char *av[])
{
	int		i;
	int		over;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("Error: argv is must 4 or 5\n");
		return (-1);
	}
	while (av[i])
	{
		over = ft_atoi(av[i]);
		if (!ft_isnum(av[i]))
		{
			printf("Error: no digit\n");
			return (-1);
		}
		if (over < INT_MIN || over > INT_MAX)
		{
			printf("Error: no int\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
