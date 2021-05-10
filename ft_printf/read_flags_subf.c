#include "libftprintf.h"

int	not_string(char *str)
{
	while (break_cycle(*str))
	{
		str++;
	}
	if (*str == 's')
		return (0);
	return (1);
}

void	init_point(t_flags **flags, char **str, va_list param)
{
	(*str)++;
	if (*(*str) >= 48 && *(*str) <= 57)
		(*flags)->point = read_nbr(&str);
	else if (*(*str) == '*')
	{
		(*flags)->point = va_arg(param, int);
		(*str)++;
	}
	if ((*flags)->point < 0)
	{
		neg_point(&flags);
		if (!not_string(*str))
		{
			(*flags)->point_on = 0;
			(*flags)->point = 1;
			if (!(*flags)->minus)
				(*flags)->minus = 0;
			return ;
		}
		return ;
	}
	(*flags)->point_on = 1;
}

void	star_zero(t_flags ***flags, char ***str, va_list param)
{
	(*(*flags))->zero_on = 1;
	(*(*flags))->zero = va_arg(param, int);
	(*(*str))++;
}

void	init_nbr_or_zero(t_flags **flags, char **str, va_list param)
{
	if (*(*str) == '0')
	{
		(*str)++;
		if (*(*str) >= 48 && *(*str) <= 57)
		{
			(*flags)->zero = read_nbr(&str);
			if ((*flags)->zero == 0)
				(*flags)->zero = 1;
			(*flags)->zero_on = 1;
		}
		if (*(*str) >= 48 && *(*str) <= 57)
			(*str)++;
		if (*(*str) == '*')
			star_zero(&flags, &str, param);
		neg_zero_and_point_on(&flags, &str);
		if ((*flags)->zero == 0)
			(*flags)->zero = 1;
	}
	else if (*(*str) >= 49 && *(*str) <= 57)
	{
		if (*(*str) >= 48 && *(*str) <= 57)
			(*flags)->nbr = read_nbr(&str);
	}
}

void	only_star(t_flags **flags, va_list param, char **str)
{
	(*flags)->nbr = va_arg(param, int);
	if ((*flags)->nbr < 0)
	{
		(*flags)->nbr *= -1;
		(*flags)->minus = 1;
	}
	(*str)++;
}
