/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:16:45 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/25 00:22:13 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	ret = (void *)0;
	i = ft_strlen(s);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
		{
			ret = (char *)&s[i];
			return (ret);
		}
	}
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	return (ret);
}
