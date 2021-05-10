#include "libftprintf.h"
#include <stdio.h>

static	int	minus(t_flags *flags, char *out_s, int ret)
{
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
	if (flags->point)
		put_zero(flags->point - ret);
	ft_putstr_fd(out_s, 1);
	if (flags->nbr > flags->point && flags->nbr > ret)
		return (flags->nbr);
	if (flags->point > ret)
		return (flags->point);
	return (ret);
}

int	behavior_precent(t_flags *flags)
{
	unsigned int		ret;
	char				*out_s;

	out_s = "%";
	ret = 1;
	if (flags->minus && flags->zero && !flags->nbr)
		flags->nbr = flags->zero;
	flags->point = 0;
	if (flags->minus && flags->zero && flags->point_on)
		flags->minus = 1;
	if (!flags->minus && flags->zero == 1)
		flags->zero = flags->nbr;
	if (flags->minus)
		flags->count_chr = minus(flags, out_s, ret);
	else if (flags->zero && !flags->minus)
		flags->count_chr = zero_not_point(flags, out_s, ret);
	else
		flags->count_chr = rest(flags, out_s, ret);
	return (flags->count_chr);
}
