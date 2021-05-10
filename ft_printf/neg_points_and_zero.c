#include "libftprintf.h"
#include <stdio.h>

char	*ft_strchr_sp(const char *s, int c)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = (void *)0;
	while (break_cycle(s[i]))
	{
		if (s[i] == c)
		{
			ret = (char *)&s[i];
			return (ret);
		}
		i++;
	}
	if (c == 0)
		ret = (char *)&s[i];
	return (ret);
}

void	neg_point(t_flags ***flags)
{
	if (!(*(*flags))->nbr)
		(*(*flags))->nbr = 1;
	else if ((*(*flags))->nbr && !(*(*flags))->minus)
	{
		(*(*flags))->point = 1;
	}
	else
		(*(*flags))->point = 1;
}

void	neg_zero_and_point_on(t_flags ***flags, char ***str)
{
	if ((*(*flags))->zero < 0)
	{
		(*(*flags))->nbr = (*(*flags))->zero * (-1);
		(*(*flags))->minus = 1;
		(*(*flags))->zero = 0;
	}
	if (ft_strchr_sp(*(*str), '.') && !(*(*flags))->nbr)
	{
		(*(*flags))->nbr = (*(*flags))->zero;
	}
}
