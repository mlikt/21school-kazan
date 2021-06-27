#include "../header/valid_map.h"
#include "../header/cube.h"

char	*str_color(char **value)
{
	int		count;
	int		i;
	char	*color;
	char	*tmp;

	i = 0;
	count = size_arr(value);
	if (count == 1)
	{
		color = ft_strdup(value[0]);
		return (color);
	}
	color = ft_strdup("");
	while (i < count)
	{
		tmp = color;
		color = ft_strjoin(color, value[i]);
		if (tmp)
			free(tmp);
		i++;
	}
	return (color);
}
#include <stdio.h>
int	get_chanel_color_cub(char *nbr)
{
	int	chanel;

	chanel = ft_atoi(nbr);
	if (chanel > 255 || chanel == -1)
	{
		ft_putendl_fd("Color value cannot exceed 255", 2);
		exit (-1);
	}
	return (chanel);
}

int	convert(char *value)
{
	char	integer[4];
	char	**nbr;

	nbr = NULL;
	nbr = ft_split(value, ',');
	if (size_arr(nbr) != 3)
		print_massege_error_id(1, "C or F");
	integer[0] = get_chanel_color_cub(nbr[2]);
	integer[1] = get_chanel_color_cub(nbr[1]);
	integer[2] = get_chanel_color_cub(nbr[0]);
	integer[3] = 0;
	free(value);
	free_arr(nbr);
	return (*((int *)integer));
}

int	read_value(char **value)
{
	char	*color;
	int		out;

	color = str_color(&value[1]);
	if (!check_color(color))
		print_massege_error(4);
	out = convert(color);
	free_arr(value);
	return (out);
}

int	get_color_from_file(t_check *check, char **str)
{
	int	color;

	if (check_id(recognize_id(str[0]), check))
		print_massege_error_id(2, str[0]);
	confirm_check(check, recognize_id(str[0]));
	if (size_arr(str) > 1)
	{
		valid_value(&str[1]);
		color = read_value(str);
		return (color);
	}
	else
		print_massege_error_id(1, str[0]);
	return (0);
}
