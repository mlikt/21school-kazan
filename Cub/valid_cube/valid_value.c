#include "../header/valid_map.h"
void	count_commas(char **str)
{
	int	i;
	int	commas;
	int	size;
	int	j;

	i = 0;
	commas = 0;
	size = size_arr(str);
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ',')
				commas++;
			j++;
		}
		i++;
	}
	if (commas != 2)
		print_massege_error_id(1, "C or F");
}

static void	func(char *tmp, int *count, int *i)
{
	(*count)++;
	while (tmp)
	{
		if (tmp[1])
			(*count)++;
		tmp = ft_strchr(tmp + 1, ',');
	}
	(*i)++;
}

void	count_nbr(char **str, int i, int count)
{
	int		size;
	char	*tmp;

	size = size_arr(str);
	while (i < size)
	{
		if (str[i][0] == ',' && str[i][1] == 0)
		{
			i++;
			continue ;
		}
		else
		{
			tmp = ft_strchr(str[i], ',');
			if (tmp)
			{
				func(tmp, &count, &i);
				continue ;
			}
			count++;
			i++;
		}
	}
	if (count > 3)
		print_massege_error_id(1, "C or F");
}

void	valid_value(char **str)
{
	count_nbr(str, 0, -1);
	count_commas(str);
}
