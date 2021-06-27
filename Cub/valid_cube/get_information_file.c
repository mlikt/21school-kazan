#include "../header/valid_map.h"
#include "../header/cube.h"

void	print_massege_error_id(int nbr_error, char *str)
{	
	ft_putendl_fd("Error", 2);
	if (nbr_error == 1)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": Invalid number of arguments.", 2);
	}
	if (nbr_error == 2)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": Identifier is initialized.", 2);
	}
	if (nbr_error == 3)
	{
		ft_putendl_fd(str, 2);
		ft_putendl_fd("Invalid file format:", 2);
		ft_putendl_fd("Please use .png or .xmp", 2);
	}
	if (nbr_error == 4)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": Not found file.", 2);
	}
	if (nbr_error == 5)
		ft_putendl_fd("Memory not allocated", 2);
	exit (-1);
}

int	read_while(t_check *check)
{
	if (check->R && check->NO && check->SO
		&& check->SO && check->WE && check->EA
		&& check->S && check->F && check->C)
		return (0);
	return (1);
}

void	init_info(char **id, t_info *info, void *mlx, t_check *check)
{
	if (!id[0])
		return ;
	if (recognize_id(id[0]) == 0)
		print_massege_error(6);
	if (recognize_id(id[0]) == 1)
		info->R = get_resolution(check, id, mlx);
	if (recognize_id(id[0]) == 2)
		info->NO = get_path_img(check, id);
	if (recognize_id(id[0]) == 3)
		info->SO = get_path_img(check, id);
	if (recognize_id(id[0]) == 4)
		info->WE = get_path_img(check, id);
	if (recognize_id(id[0]) == 5)
		info->EA = get_path_img(check, id);
	if (recognize_id(id[0]) == 6)
		info->S = get_path_img(check, id);
	if (recognize_id(id[0]) == 7)
		info->F = get_color_from_file(check, id);
	if (recognize_id(id[0]) == 8)
		info->C = get_color_from_file(check, id);
}

t_info	*get_basic_info(int fd, void *mlx)
{
	t_check	check;
	char	*line;
	t_info	*info;
	char	**id;
	int		end;

	info = (t_info *)get_dynamic_array(5, 1);
	id = NULL;
	init_checker(&check);
	while (read_while(&check))
	{
		end = get_next_line(fd, &line);
		id = get_identifer_and_data(line);
		init_info(id, info, mlx, &check);
		if (line)
			free(line);
		if (!end)
		{
			if (read_while(&check))
				print_massege_error(6);
			break ;
		}
	}
	return (info);
}

t_info	*get_information_file(int fd, void *mlx)
{
	t_info	*info;

	info = get_basic_info(fd, mlx);
	info->map = get_map(fd);
	filling_map_space(info->map);
	get_information_map(info, &info->sprite);
	return (info);
}
