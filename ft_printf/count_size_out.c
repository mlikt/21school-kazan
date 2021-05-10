#include "libftprintf.h"

size_t	count_size_out(int n)
{
	int	count_chr;
	int	clone_n;

	if (n == 0)
		return (1);
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

size_t	count_size_outu(unsigned int n)
{
	int				count_chr;
	unsigned int	clone_n;

	if (n == 0)
		return (1);
	clone_n = n;
	count_chr = 0;
	while (clone_n != 0)
	{
		count_chr++;
		clone_n = clone_n / 10;
	}
	return (count_chr);
}

size_t	count_size_outhex(unsigned long int n)
{
	int					count_chr;
	unsigned long int	clone_n;

	if (n == 0)
		return (1);
	clone_n = n;
	count_chr = 0;
	while (clone_n != 0)
	{
		count_chr++;
		clone_n = clone_n / 16;
	}
	return (count_chr);
}
