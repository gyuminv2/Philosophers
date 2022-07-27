/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:35:01 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:38:41 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*copy;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	copy = (char *)malloc(sizeof(*s) * (len + 1));
	if (!copy)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			copy[j] = s[i];
			j++;
		}
	}
	copy[j] = '\0';
	return (copy);
}
