/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:33:44 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/08 17:06:03 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_size(int n)
{	
	size_t	count_chr;
	int		clone_n;

	clone_n = n;
	count_chr = 0;
	while (clone_n != 0)
	{
		count_chr++;
		if (clone_n < 0)
		{
			count_chr++;
			clone_n *= (-1);
		}
		clone_n = clone_n / 10;
	}
	if (n == -2147483648)
	{
		count_chr--;
	}
	return (count_chr);
}

static	void	ifnegative(int *n, size_t *count_chr, char *itoa)
{
	if (*n == -2147483648)
	{
		itoa[*count_chr] = '8';
		*n = (*n) / 10;
		(*count_chr)--;
	}
	itoa[0] = '-';
	*n = (*n) * (-1);
}

static	char	*neg_zero(void)
{
	char	*zero;

	zero = (char *)ft_calloc(2, sizeof(char));
	zero[0] = '0';
	return (zero);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	count_chr;

	count_chr = count_size(n);
	if (n == -0)
		return (neg_zero());
	itoa = (void *)0;
	itoa = (char *)ft_calloc(count_chr + 1, sizeof(char));
	if (itoa == (void *)0)
		return (itoa);
	while (n != 0)
	{
		count_chr--;
		if (n < 0)
			ifnegative(&n, &count_chr, itoa);
		itoa[count_chr] = (n % 10) + '0';
		n = n / 10;
	}
	return (itoa);
}
