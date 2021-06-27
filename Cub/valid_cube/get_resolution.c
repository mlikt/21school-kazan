#include "../header/valid_map.h"
#include "../header/cube.h"

int	check_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	change_value_screen(int *value, char **str, t_check *check)
{
	if (ft_atoi(str[1]) <=0 || ft_atoi(str[2]) <= 0)
		print_massege_error(0);
	if (value[1] > ft_atoi(str[1]))
		value[1] = ft_atoi(str[1]);
	if (value[0] > ft_atoi(str[2]))
		value[0] = ft_atoi(str[2]);
	check->R = 1;
}
int	*get_resolution(t_check *check, char **str, void *mlx)
{	
	int	*value;

	if (!check->R)
	{
		if (size_arr(str) == 3)
		{
			if (!check_digit(str[1]) || !check_digit(str[2]))
				print_massege_error(4);
			value = get_dynamic_array(0, 2);
			mlx_get_screen_size(mlx, &value[0], &value[1]);
			change_value_screen(value, str, check);
			free_arr(str);
			return (value);
		}
		print_massege_error_id(1, str[0]);
	}
	else
		print_massege_error_id(2, str[0]);
	return (NULL);
}
