#include "libftprintf.h"

int 	ft_putstr_range_fd(char *s, int fd, int size)
{
	if (s == (void *)0)
		return (0);
	if (!size)
		return (0);
	write(fd, s, size);
	return (size);
}

static	int	minus(t_flags *flags, char *out_s, int ret)
{
	int	count_chr;

	count_chr = 0;
	if (flags->point < ret && flags->point_on)
		count_chr += ft_putstr_range_fd(out_s, 1, flags->point);
	else
		count_chr += ft_putstr_range_fd(out_s, 1, ret);
	if (flags->point < ret && flags->point_on)
		flags->nbr = flags->nbr + (ret - flags->point);
	if (flags->nbr)
		count_chr += put_space(flags->nbr - ret);
	return (count_chr);
}

static	int	zero_not_point(t_flags *flags, char *out_s, int ret)
{
	int	count_chr;

	count_chr = 0;
	count_chr += put_zero(flags->zero - ret);
	count_chr += ft_putstr_range_fd(out_s, 1, ret);
	if (flags->zero > ret)
		return (flags->zero);
	return (count_chr);
}

static	int	rest(t_flags *flags, char *out_s, int ret)
{
	int	count_chr;

	count_chr = 0;
	if (flags->point < ret && flags->point_on)
		flags->nbr = flags->nbr + (ret - flags->point);
	if (flags->nbr)
		count_chr += put_space(flags->nbr - ret);
	if (flags->point < ret && flags->point_on)
		count_chr += ft_putstr_range_fd(out_s, 1, flags->point);
	else
		count_chr += ft_putstr_range_fd(out_s, 1, ret);
	return (count_chr);
}

int	behavior_string(t_flags *flags, char *out_s)
{
	unsigned int	ret;

	ret = (int)ft_strlen(out_s);
	if (!flags->nbr && !flags->point_on)
		flags->nbr = flags->zero;
	if (flags->minus)
		flags->count_chr = minus(flags, out_s, ret);
	else if (flags->zero && !flags->point_on)
		flags->count_chr = zero_not_point(flags, out_s, ret);
	else
		flags->count_chr = rest(flags, out_s, ret);
	return (flags->count_chr);
}
