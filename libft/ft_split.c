/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:34:34 by gyumpark          #+#    #+#             */
/*   Updated: 2022/03/18 17:34:35 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**str_free_all(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	str_char_meet(char c, char ch)
{
	if (ch == c)
		return (0);
	if (c == '\0')
		return (0);
	return (1);
}

static void	same_sc(char *to, char const *from, char c)
{
	int	i;

	i = 0;
	while (str_char_meet(from[i], c) == 1)
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

static int	count_meet(char const *str, char c, int *j)
{
	int	i;
	int	met;

	i = 0;
	met = 0;
	if (*j == 0)
	{
		while (str_char_meet(str[i], c) == 1)
			i++;
		*j = i;
		return (*j);
	}
	while (str[i])
	{
		if (str_char_meet(str[i], c) == 1 && str_char_meet(str[i + 1], c) == 0)
			met++;
		i++;
	}
	return (met);
}

char	**ft_split(char const *s, char c)
{
	char	**save;
	int		i;
	int		space;

	space = -1;
	save = (char **)malloc(sizeof(char *) * (count_meet(s, c, &space) + 1));
	if (!save)
		return (NULL);
	save[count_meet(s, c, &space)] = 0;
	while (*s)
	{
		if (str_char_meet(*s, c) == 0)
			s++;
		else
		{
			i = 0;
			i = count_meet(s, c, &i);
			save[space + 1] = (char *)malloc(sizeof(char) * (i + 1));
			if (!save)
				return (str_free_all(save));
			same_sc(save[space + 1], s, c);
			s += i, space++;
		}
	}
	return (save);
}
