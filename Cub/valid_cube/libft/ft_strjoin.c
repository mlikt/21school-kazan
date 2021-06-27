/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:00:45 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;

	strjoin = (void *)0;
	if (s1 == (void *)0 || s1 == (void *)0)
		return ((void *)0);
	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)ft_calloc(len + 2, sizeof(char));
	if (strjoin == (void *)0)
		return ((void *)0);
	ft_strlcat(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, len + 1);
	return (strjoin);
}
