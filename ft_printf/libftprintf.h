/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:19:19 by mlikt             #+#    #+#             */
/*   Updated: 2021/05/03 19:47:37 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define	LIBFTPRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"
typedef struct s_flags
{
	int	zero;
	int	point;
	int	nbr;
	int	minus;
	int	zero_on;
	int	point_on;
	int	count_chr;
}				t_flags;
int		ft_printf(const char *str, ...);
int		read_nbr(char ***str);
void	read_flags(char *str, t_flags *flags, va_list param);
int		behavior_dec(t_flags *flags, int out);
int		put_space(int n);
int		put_zero(int n);
size_t	count_size_out(int n);
char	*ft_strchr_sp(const char *s, int c);
void	init_point(t_flags **flags, char **str, va_list param);
void	init_nbr_or_zero(t_flags **flags, char **str, va_list param);
void	only_star(t_flags **flags, va_list param, char **str);
int		break_cycle(char c);
char	*ft_uitoa(unsigned int n);
size_t	count_size_outu(unsigned int n);
int		behavior_udec(t_flags *flags, unsigned int out);
int		behavior_hexl(t_flags *flags, unsigned int out);
char	*ft_hexltoa(unsigned long int n);
size_t	count_size_outhex(unsigned long int n);
char	*ft_hexuptoa(unsigned int n);
int		behavior_hexup(t_flags *flags, unsigned int out);
int		behavior_pointer(t_flags *flags, unsigned long int out);
int		behavior_precent(t_flags *flags);
int		behavior_char(t_flags *flags, int out);
int		behavior_string(t_flags *flags, char *out_s);
int		put_dec(char *str, va_list param);
int		put_udec(char *str, va_list param);
int		put_hexl(char *str, va_list param);
int		put_hexup(char *str, va_list param);
int		put_pointer(char *str, va_list param);
void	init_flags(t_flags *flags);
int		put_precent(char *str, va_list param);
int		put_character(char *str, va_list param);
int		put_string(char *str, va_list param);
int		cycle_for_flags(char *s, int *i, va_list param);
int		get_index_func(char c);
void	init_ptrfunc(int (*put_data[8])(char*, va_list));
void	neg_zero_and_point_on(t_flags ***flags, char ***str);
void	neg_point(t_flags ***flags);
int		not_string(char *str);
#endif
