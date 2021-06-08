/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:21:41 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/24 19:59:56 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get_begin(char	const *s1, char const *set)
{
	char	*begin;
	size_t	i;
	size_t	j;
	size_t	on;

	begin = (void *)0;
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		on = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				on++;
				break ;
			}
			j++;
		}
		if (on == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (begin);
}

static	char	*get_end(char const *s1, char const *set)
{
	char	*end;
	size_t	i;
	size_t	j;
	size_t	on;

	end = (void *)0;
	i = ft_strlen(s1);
	while (i > 0)
	{
		i--;
		j = ft_strlen(set);
		on = 0;
		while (j > 0)
		{
			j--;
			if (s1[i] == set[j])
			{
				on++;
				break ;
			}
		}
		if (on == 0)
			return ((char *)&s1[i]);
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*end;
	char	*strtrim;

	strtrim = (void *)0;
	if (s1 == (void *)0 || set == (void *)0)
		return ((void *)0);
	begin = get_begin(s1, set);
	end = get_end(s1, set);
	if (end == (void *)0 && begin == (void *)0)
		return ((char *)ft_calloc(1, sizeof(char)));
	strtrim = (char *)ft_calloc((end - begin) + 2, sizeof(char));
	if (strtrim == (void *)0)
		return (strtrim);
	ft_strlcpy(strtrim, begin, (end - begin) + 2);
	return (strtrim);
}
