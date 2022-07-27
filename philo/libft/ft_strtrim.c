/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:59 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:35:00 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*save;

	save = 0;
	if (s1 && set)
	{
		first = 0;
		last = ft_strlen(s1);
		while (s1[first] && ft_strchr(set, s1[first]))
			first++;
		while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && last > first)
			last--;
		save = (char *)malloc(sizeof(char) * (last - first + 1));
		if (save)
			ft_strlcpy(save, &s1[first], last - first + 1);
	}
	return (save);
}
