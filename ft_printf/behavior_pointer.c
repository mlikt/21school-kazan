#include "libftprintf.h"
#include <stdio.h>

static	int	minus(t_flags *flags, char *out_s, int ret)
{
	ft_putstr_fd("0x", 1);
	if (flags->point)
		put_zero(flags->point - ret);
	ft_putstr_fd(out_s, 1);
	if (flags->nbr && flags->point >= ret)
		put_space(flags->nbr - flags->point);
	else if (flags->nbr && flags->point <= ret)
		put_space(flags->nbr - ret);
	if (flags->nbr > flags->point && flags->nbr > ret)
		return (flags->nbr);
	if (flags->point > ret)
		return (flags->point);
	return (ret);
}

static	int	zero_not_point(t_flags *flags, char *out_s, int ret)
{
	ft_putstr_fd("0x", 1);
	put_zero(flags->zero - ret);
	ft_putstr_fd(out_s, 1);
	if (flags->zero > ret)
		return (flags->zero);
	return (ret);
}

static	int	rest(t_flags *flags, char *out_s, int ret)
{
	if (flags->nbr && flags->point >= ret)
		put_space(flags->nbr - flags->point);
	else if (flags->nbr && flags->point <= ret)
		put_space(flags->nbr - ret);
	ft_putstr_fd("0x", 1);
	if (flags->point)
		put_zero(flags->point - ret);
	ft_putstr_fd(out_s, 1);
	if (flags->nbr > flags->point && flags->nbr > ret)
		return (flags->nbr);
	if (flags->point > ret)
		return (flags->point);
	return (ret);
}

static	int	exclusion(char *out_s, int ret, t_flags **flags)
{
	if (((*flags)->zero == 0 && (*flags)->zero_on)
		|| ((*flags)->point == 0 && (*flags)->point_on))
	{
		*out_s = 0;
		ret = 2;
		if ((*flags)->minus)
			(*flags)->count_chr = minus(*flags, out_s, ret);
		else if ((*flags)->zero && !(*flags)->point)
			(*flags)->count_chr = zero_not_point(*flags, out_s, ret);
		else
			(*flags)->count_chr = rest(*flags, out_s, ret);
		return (1);
	}
	return (0);
}

int	behavior_pointer(t_flags *flags, unsigned long int out)
{
	unsigned int		ret;
	char				*out_s;

	out_s = ft_hexltoa(out);
	if (!out_s)
		return (0);
	ret = 0;
	ret = count_size_outhex(out) + 2;
	if (out == 0)
	{
		if (exclusion(out_s, ret, &flags))
		{
			free(out_s);
			return (flags->count_chr);
		}
	}
	flags->point += 2;
	if (flags->minus)
		flags->count_chr = minus(flags, out_s, ret);
	else if (flags->zero && !flags->point)
		flags->count_chr = zero_not_point(flags, out_s, ret);
	else
		flags->count_chr = rest(flags, out_s, ret);
	free(out_s);
	return (flags->count_chr);
}
