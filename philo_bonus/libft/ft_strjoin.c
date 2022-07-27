/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:44 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:34:45 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*save;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	save = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!save)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		save[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		save[j++] = s2[i];
		i++;
	}
	save[j] = '\0';
	return (save);
}
