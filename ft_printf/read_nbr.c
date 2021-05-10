#include "libftprintf.h"
#include <stdio.h>

int	read_nbr(char ***str)
{
	int		out;
	char	*substr;
	size_t	size_word;
	char	*str_clone;

	size_word = 0;
	str_clone = *(*str);
	while (*(*(*str)) >= 48 && *(*(*str)) <= 57)
	{	
		size_word++;
		(*(*str))++;
	}
	while (*str_clone == '0' && *(str_clone + 1) == '0')
	{
		if (not_string((*(*str))))
			(*(*str))--;
		str_clone++;
		size_word--;
	}
	substr = ft_substr((str_clone), 0, size_word);
	if (!substr)
		return (0);
	out = ft_atoi(substr);
	free(substr);
	return (out);
}
