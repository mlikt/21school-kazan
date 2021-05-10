#include "libftprintf.h"

int	cycle_for_flags(char *s, int *i, va_list param)
{
	int	(*put_data[8])(char*, va_list);
	int	count_chr;
	int	c;
	int	j;

	c = 0;
	j = 0;
	init_ptrfunc(put_data);
	count_chr = 0;
	while (s[j])
	{
		(*i)++;
		j++;
		c = get_index_func(s[j]);
		if (c)
		{
			count_chr += put_data[c - 1]((s + j), param);
			(*i)++;
			break ;
		}
	}	
	return (count_chr);
}

int	put_precent(char *str, va_list param)
{
	int		count_chr;
	t_flags	flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	count_chr = behavior_precent(&flags);
	return (count_chr);
}

int	put_character(char *str, va_list param)
{
	int		out;
	int		count_chr;
	t_flags	flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, int);
	count_chr = behavior_char(&flags, out);
	return (count_chr);
}

int	put_string(char *str, va_list param)
{
	char	*out;
	int		count_chr;
	t_flags	flags;

	count_chr = 0;
	init_flags(&flags);
	read_flags(str, &flags, param);
	out = va_arg(param, char *);
	if (!out)
		out = "(null)";
	count_chr = behavior_string(&flags, out);
	return (count_chr);
}
