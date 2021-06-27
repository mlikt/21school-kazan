/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:39:39 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*ret;

	i = 0;
	ret = (void *)0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			ret = &((unsigned char *)s)[i];
			return (ret);
		}
		i++;
	}
	return (ret);
}
