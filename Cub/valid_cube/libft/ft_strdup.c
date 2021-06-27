/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:25:24 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (void *)0;
	dup = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (dup == (void *)0)
		return (dup);
	ft_memcpy(dup, s1, ft_strlen(s1));
	return (dup);
}
