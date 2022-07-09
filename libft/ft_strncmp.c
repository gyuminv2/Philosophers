/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:54 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:34:55 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cp1[i] != cp2[i] || !cp1[i] || !cp2[i])
			return (cp1[i] - cp2[i]);
		i++;
	}
	return (0);
}
