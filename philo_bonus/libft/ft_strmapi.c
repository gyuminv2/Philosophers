/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:53 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:34:54 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*copy;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (0);
	while (i < len)
	{
		copy[i] = f(i, s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
