/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:18:35 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/24 11:55:20 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static	size_t	get_size_ret(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	if (ft_strlen(dst) > ft_strlen(src) && ft_strlen(dst) > dstsize)
		ret = dstsize + ft_strlen(src);
	else if (ft_strlen(dst) < ft_strlen(src) && ft_strlen(dst) > dstsize)
		ret = dstsize + ft_strlen(src);
	else
		ret = ft_strlen(dst) + ft_strlen(src);
	return (ret);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	ret = get_size_ret(dst, src, dstsize);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < (dstsize - 1))
	{
		if (dst[i] == '\0')
		{
			while (i < (dstsize - 1) && src[j] != '\0')
				dst[i++] = src[j++];
			dst[i] = '\0';
			break ;
		}
		i++;
	}
	return (ret);
}
