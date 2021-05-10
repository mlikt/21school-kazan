#include "libftprintf.h"
#include <stdio.h>

int	break_cycle(char c)
{
	if (c == 'd' || c == 's' || c == 'u' || c == 'i' || c == 'c'
		|| c == 'x' || c == 'X' || c == '%' || c == 'p')
		return (0);
	return (1);
}

void	move_to_precent(char **str)
{	
	(*str)--;
	while (*(*str) != '%')
		(*str)--;
	(*str)++;
}

void	read_flags(char *str, t_flags *flags, va_list param)
{
	move_to_precent(&str);
	while (break_cycle(*str))
	{
		if (*str == '.')
			init_point(&flags, &str, param);
		else if (*str >= 48 && *str <= 57)
			init_nbr_or_zero(&flags, &str, param);
		else if (*str == '*')
			only_star(&flags, param, &str);
		else if (*str == '-')
		{
			flags->minus = 1;
			str++;
		}
		else
			str++;
		if (!break_cycle(*str))
			break ;
	}
}
