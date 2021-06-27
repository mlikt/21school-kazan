/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:56:32 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

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
