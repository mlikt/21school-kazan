/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:16:45 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

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
