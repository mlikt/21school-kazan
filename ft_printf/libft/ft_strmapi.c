/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:24:13 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/21 23:42:33 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	size_t	i;

	i = 0;
	if (s == (void *)0)
		return ((void *)0);
	strmapi = (void *)0;
	strmapi = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (strmapi == (void *)0)
		return (strmapi);
	while (*s)
	{
		strmapi[i] = f(i, *s);
		i++;
		s++;
	}
	return (strmapi);
}
