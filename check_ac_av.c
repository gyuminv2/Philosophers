#include "philo.h"

int	check_ac_av(int ac, char *av[])
{
	int		i;
	int		over;
	char	**split;

	i = 0;
	if (ac != 5 && ac != 6 && ac != 2)
	{
		printf("Error: argv is must 4 or 5\n");
		return (-1);
	}
	else
		i = 1;
	while (av[i])
	{
		over = ft_atoi(av[i]);
		if (!ft_isnum(av[i]))
		{
			printf("Error: no digit\n");
			return (-1);
		}
		if (over < INT_Min || over > INT_Max)
		{
			printf("Error: no int\n");
			return (-1);
		}
		i++;
	}
	if (ac == 2)
		ft_free(av);
}
