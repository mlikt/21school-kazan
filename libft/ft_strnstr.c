/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:05:26 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/26 22:43:08 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

int main(void)
{
	printf("%s\n", ft_strnstr("aaabcabcd", "aabc", -1));
}
