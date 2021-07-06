/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:51:51 by mlikt             #+#    #+#             */
/*   Updated: 2021/07/05 17:05:29 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	plus_or_minus(const char *str, unsigned int *i)
{
	int				c;
	unsigned int	z;

	c = 1;
	z = (*i) + 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			c = c * (-1);
		if ((*i) >= z)
			break ;
		(*i)++;
	}
	return (c);
}

void	skip_space(const char *str, unsigned int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
	{
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	long int		atoi;
	long int		over;
	unsigned int	i;
	int				c;

	atoi = 0;
	i = 0;
	over = 214748364;
	skip_space(str, &i);
	c = plus_or_minus(str, &i);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((atoi > over && (c == 1))
			|| ((atoi >= over) && (str[i] >= '8') && (c == 1)))
			return (0);
		if ((atoi > over && (c == -1))
			|| ((atoi >= over) && (str[i] >= '9') && (c == -1)))
			return (0);
		atoi = (str[i] - 48) + atoi * 10;
		i++;
	}
	return (atoi * c);
}
