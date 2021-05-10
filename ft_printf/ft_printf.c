#include "libftprintf.h"

void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->point = 0;
	flags->nbr = 0;
	flags->minus = 0;
	flags->zero_on = 0;
	flags->point_on = 0;
	flags->count_chr = 0;
}

void	init_ptrfunc(int (*put_data[8])(char*, va_list))
{
	put_data[0] = &put_dec;
	put_data[1] = &put_udec;
	put_data[2] = &put_character;
	put_data[3] = &put_string;
	put_data[4] = &put_pointer;
	put_data[5] = &put_hexl;
	put_data[6] = &put_hexup;
	put_data[7] = &put_precent;
}

int	get_index_func(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'u')
		return (2);
	if (c == 'c')
		return (3);
	if (c == 's')
		return (4);
	if (c == 'p')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	return (0);
}

int	read_arg(char *s, va_list param)
{
	int	i;
	int	count_chr;

	i = 0;
	count_chr = 0;
	while (s[i])
	{
		if (s[i] == '%')
			count_chr += cycle_for_flags((s + i), &i, param);
		if (s[i] == '%')
			continue ;
		if (s[i] == 0)
			break ;
		count_chr++;
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (count_chr);
}

int	ft_printf(const char *str, ...)
{
	int		count_chr;
	va_list	param;

	count_chr = 0;
	if (!str)
		return (-1);
	va_start(param, str);
	count_chr = read_arg((char *)str, param);
	va_end(param);
	return (count_chr);
}
