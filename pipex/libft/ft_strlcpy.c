/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:54:21 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/25 00:25:55 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 1;
	if (!dst && !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (ft_strlen(src) != 0)
		n = (dstsize - 1);
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
