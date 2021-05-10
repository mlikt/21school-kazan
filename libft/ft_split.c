/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:24:37 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/25 19:48:27 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlchr(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static	size_t	count_word(char const *s, char c)
{
	char	*poin_count;
	size_t	count;

	poin_count = (char *)s;
	count = 0;
	while (poin_count)
	{
		if (poin_count[0] != c && poin_count[0] != '\0')
			count++;
		poin_count = ft_strchr(poin_count, c);
		if (poin_count == (void *)0)
			break ;
		poin_count++;
	}
	return (count);
}

static	int	ini_arr(char **arr, size_t *i, char *p, char c)
{
	size_t	ix;

	ix = 0;
	arr[*i] = (char *)ft_calloc(ft_strlchr(p, c) + 1, sizeof(char));
	if (arr[*i] == (void *)0)
	{
		while (arr[ix])
		{
			free(arr[ix]);
			arr[ix] = (void *)0;
			ix++;
		}
		free(arr);
		arr = (void *)0;
		return (1);
	}
	ft_strlcpy(arr[*i], p, ft_strlchr(p, c) + 1);
	(*i)++;
	return (0);
}

static	char	**valid_sc(char const *s)
{
	char	**arr;

	arr = (void *)0;
	if (s == (void *)0 || *s == 0)
	{
		arr = (char **)ft_calloc(1, sizeof(char *));
		if (arr == (void *)0)
			return (arr);
		arr[0] = (void *)0;
		return (arr);
	}
	arr = (char **)ft_calloc(2, sizeof(char *));
	if (arr == (void *)0)
		return (arr);
	arr[0] = ft_strdup(s);
	if (arr[0] == (void *)0)
	{
		free (arr);
		return (arr);
	}
	arr[1] = (void *)0;
	return (arr);
}

char	**ft_split(char	const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**arr;
	char	*p;

	arr = (void *)0;
	p = (char *)s;
	if (s == (void *)0 || *s == 0)
		return (valid_sc(s));
	if (c == '\0' || ft_strchr(s, c) == (void *)0)
		return (valid_sc(s));
	count = count_word(s, c);
	arr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (arr == (void *)0)
		return (arr);
	i = 0;
	while (i < count)
	{
		if (ft_strlchr(p, c) > 0)
			if (ini_arr(arr, &i, p, c))
				return (arr);
		p = ft_strchr(p, c) + 1;
	}
	arr[count] = (void *)0;
	return (arr);
}
