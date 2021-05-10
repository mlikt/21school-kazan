#include "libftprintf.h"

static	size_t	count_size(unsigned int n)
{	
	size_t				count_chr;
	unsigned int		clone_n;

	clone_n = n;
	count_chr = 0;
	while (clone_n != 0)
	{
		count_chr++;
		clone_n = clone_n / 16;
	}
	return (count_chr);
}

static	char	*neg_zero(void)
{
	char	*zero;

	zero = (char *)ft_calloc(2, sizeof(char));
	zero[0] = '0';
	return (zero);
}

char	*ft_hexuptoa(unsigned int n)
{
	char	*uitoa;
	size_t	count_chr;
	char	*alphafit;
	size_t	c;

	alphafit = "0123456789ABCDEF";
	count_chr = count_size(n);
	if (n == 0)
		return (neg_zero());
	uitoa = (void *)0;
	uitoa = (char *)ft_calloc(count_chr + 1, sizeof(char));
	if (uitoa == (void *)0)
		return (uitoa);
	while (n != 0)
	{
		count_chr--;
		c = n % 16;
		uitoa[count_chr] = alphafit[c];
		n = n / 16;
	}
	return (uitoa);
}
