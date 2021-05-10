#include "libftprintf.h"

int	put_space(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	put_zero(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
