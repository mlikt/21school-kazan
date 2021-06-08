/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:56:32 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/25 00:23:27 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = (void *)0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ret = (char *)&s[i];
			return (ret);
		}
		i++;
	}
	if (c == 0)
		ret = (char *)&s[i];
	return (ret);
}
