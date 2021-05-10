/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:34:45 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/19 11:22:23 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	out = (void *)0;
	out = malloc(count * size);
	if (out != (void *)0)
	{
		ft_bzero(out, (count * size));
	}
	return (out);
}
