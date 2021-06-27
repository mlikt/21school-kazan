#include "../header/valid_map.h"
#include "../header/cube.h"

void	confirm_check(t_check *check, int i)
{
	if (i == 2)
		check->NO = 1;
	if (i == 3)
		check->SO = 1;
	if (i == 4)
		check->WE = 1;
	if (i == 5)
		check->EA = 1;
	if (i == 6)
		check->S = 1;
	if (i == 7)
		check->F = 1;
	if (i == 8)
		check->C = 1;
}

int	check_id(int i, t_check *check)
{
	if (i == 2 && check->NO == 0)
		return (0);
	if (i == 3 && check->SO == 0)
		return (0);
	if (i == 4 && check->WE == 0)
		return (0);
	if (i == 5 && check->EA == 0)
		return (0);
	if (i == 6 && check->S == 0)
		return (0);
	if (i == 7 && check->F == 0)
		return (0);
	if (i == 8 && check->C == 0)
		return (0);
	return (1);
}

void	find_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_massege_error_id(4, file);
	close(fd);
}

void	check_format(char *file)
{
	char	*out;

	out = file;
	find_file(file);
	file = ft_strrchr(file, '/');
	if (!file)
		file = out;
	file = ft_strrchr(file, '.');
	if (!file)
		print_massege_error_id(3, NULL);
	if ((!ft_strncmp(file, ".png", 5) || !ft_strncmp(file, ".xpm", 5))
		&& ft_strlen(out) > 4)
		return ;
	else
		print_massege_error_id(3, out);
}

char	*get_path_img(t_check *check, char **str)
{
	char	*out;

	if (check_id(recognize_id(str[0]), check))
		print_massege_error_id(2, str[0]);
	confirm_check(check, recognize_id(str[0]));
	if (size_arr(str) == 2)
	{
		check_format(str[1]);
		out = ft_strdup(str[1]);
		free_arr(str);
		return (out);
	}
	else
		print_massege_error_id(1, str[0]);
	return (NULL);
}
