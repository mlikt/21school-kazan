/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:38:43 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static	size_t	count_size_nbr(int n)
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

static	void	neg_zero_nbr(char *nbr)
{
	nbr[0] = '0';
}

static	void	ifnegative_nbr(int *n, size_t *count_chr, char *nbr)
{
	if (*n == -2147483648)
	{
		nbr[*count_chr] = '8';
		*n = (*n) / 10;
		(*count_chr)--;
	}
	nbr[0] = '-';
	*n = (*n) * (-1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[12];
	size_t	count_chr;

	if (n == -0)
		neg_zero_nbr(nbr);
	count_chr = count_size_nbr(n);
	while (n != 0)
	{
		count_chr--;
		if (n < 0)
			ifnegative_nbr(&n, &count_chr, nbr);
		nbr[count_chr] = (n % 10) + '0';
		n = n / 10;
	}
	write(fd, nbr, ft_strlen(nbr));
}
