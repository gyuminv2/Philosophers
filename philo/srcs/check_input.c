/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:31:50 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/09 12:31:51 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int ac, char *av[])
{
	int		i;
	int		over;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("Error: argv is must 4 or 5\n");
		return (FALSE);
	}
	while (av[i])
	{
		over = ft_atoi(av[i]);
		if (!ft_isnum(av[i]))
		{
			printf("Error: no digit\n");
			return (FALSE);
		}
		if (over < INT_MIN || over > INT_MAX)
		{
			printf("Error: no int\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
