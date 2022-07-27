/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:33:47 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:33:48 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	nbr_sign(long int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static int	len(int n)
{
	int	save;
	int	i;

	i = 1;
	if (n >= 0)
		save = n;
	else
	{
		i = 2;
		save = -n;
	}
	while (save > 9)
	{
		save /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*save;
	int		n_len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	n_len = len(n);
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	save = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!save)
		return (NULL);
	save[n_len] = '\0';
	while (n_len--)
	{
		save[n_len] = nbr_sign(n % 10) + '0';
		n = nbr_sign(n / 10);
	}
	if (sign == -1)
		save[0] = '-';
	return (save);
}
