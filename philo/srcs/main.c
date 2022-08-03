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
