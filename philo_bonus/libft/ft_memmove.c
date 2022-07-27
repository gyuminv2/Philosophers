/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:17 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:34:17 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		i = len;
		while (i)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return ((void *)dst);
}
