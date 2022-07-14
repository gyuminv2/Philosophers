/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:31:55 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/09 12:31:56 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_input	*input;
	t_philo	*philo;

	if (check_input(ac, av) != 0)
		return (-1);
	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (-1);
	init_input(input, ac, av);
	philo = (t_philo *)malloc(sizeof(t_philo) * input->p_num);
	if (!philo)
		return (-1);
	init_fork(philo, input);
	init_philo(philo, input);
	if (create_thread(philo, input) != 0)
		return (-1);
	if (join_thread(philo) != 0)
		return (-1);
	return (0);
}
