#include "libftprintf.h"

int	put_dec(char *str, va_list param)
{
	int		out;
	int		count_chr;
	t_flags	flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, int);
	count_chr = behavior_dec(&flags, out);
	return (count_chr);
}

int	put_udec(char *str, va_list param)
{
	unsigned int	out;
	int				count_chr;
	t_flags			flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, unsigned int);
	count_chr = behavior_udec(&flags, out);
	return (count_chr);
}

int	put_hexl(char *str, va_list param)
{
	unsigned int	out;
	int				count_chr;
	t_flags			flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, unsigned int);
	count_chr = behavior_hexl(&flags, out);
	return (count_chr);
}

int	put_hexup(char *str, va_list param)
{
	unsigned int	out;
	int				count_chr;
	t_flags			flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, unsigned int);
	count_chr = behavior_hexup(&flags, out);
	return (count_chr);
}

int	put_pointer(char *str, va_list param)
{
	unsigned long int	out;
	int					count_chr;
	t_flags				flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, unsigned long int);
	count_chr = behavior_pointer(&flags, out);
	return (count_chr);
}
