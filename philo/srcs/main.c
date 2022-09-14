/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:17:03 by gyumpark          #+#    #+#             */
/*   Updated: 2022/09/14 15:18:51 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_root	*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == FALSE)
		return (FALSE);
	if (check_input(ac, av) == FALSE)
		return (FALSE);
	if (init(root, av) == FALSE)
		return (FALSE);
	thread_create(root);
	thread_join(root);
}
