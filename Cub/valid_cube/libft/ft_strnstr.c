/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:05:26 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	m;

	if ((haystack == needle) || (ft_strlen(needle) == 0 && len == 0))
		return ((char *)haystack);
	if (len == 0)
		return ((void *)0);
	m = 0;
	while (m < len && haystack[m] != 0)
	{
		j = 0;
		i = 0;
		while (haystack[m + i] == needle[j] && (m + i) < len)
		{
			if (haystack[m + i] == 0 || needle[j] == 0)
				break ;
			j++;
			i++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i + m - ft_strlen(needle)]);
		m++;
	}
	return ((void *)0);
}
