/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:33:54 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:33:54 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*curr_next;

	curr = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (curr)
	{
		curr_next = curr->next;
		ft_lstdelone(curr, del);
		curr = curr_next;
	}
	*lst = NULL;
}
