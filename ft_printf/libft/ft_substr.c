/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:29:59 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/24 19:59:30 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (void *)0;
	if (s == (void *)0)
		return (substr);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (substr == (void *)0)
		return (substr);
	ft_memcpy(substr, s + start, len);
	return (substr);
}
