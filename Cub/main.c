#include "./header/cube.h"
#include "./header/valid_map.h"

void	draw_img(t_session *mlx)
{
	t_dataRay	data;
	double		*buf;
	int			x;

	x = 0;
	buf = (double *)get_dynamic_array(1, mlx->win->width);
	while (x < mlx->win->width)
	{
		this_is_rendering(mlx, &data, x, buf);
		draw_walls(mlx, &data, x, &mlx->img);
		draw_roof_and_floor(&data, &mlx->img, x, mlx);
		x++;
	}
	draw_sprites(buf, mlx, &mlx->img);
	free(buf);
}

int	play(t_session *mlx)
{
	if (mlx->key.start)
	{
		change_coord(mlx);
		draw_img(mlx);
		mlx_clear_window(mlx->mlx, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx_do_sync(mlx->mlx);
	}
	return (0);
}

void	valid_file_cub(char **argv, int argc)
{
	char	*format;
	char	*file;

	if (argc != 2 && argc != 3)
		print_massege_error(0);
	file = ft_strchr(argv[1], '/');
	if (!file)
		file = argv[1];
	format = ft_strrchr(file, '.');
	if (!format)
		print_massege_error(0);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		print_massege_error(0);
	if (ft_strncmp(format, ".cub", 5) || ft_strlen(file) < 5)
		print_massege_error(0);
}

void	game(t_session *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 0L, exit_win, 0);
	mlx_hook(mlx->win_ptr, 2, 0L, button_press, mlx);
	mlx_hook(mlx->win_ptr, 3, 0L, button_unpress, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win_ptr, mlx->img.img, 0, 0);
	mlx_loop_hook(mlx->mlx, play, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{	
	t_session	mlx;
	t_win		win;
	int			fd;

	valid_file_cub(argv, argc);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Not found file", 2);
		exit (-1);
	}
	init_session(&mlx, &win, fd);
	init_img(&mlx.img, &mlx);
	draw_img(&mlx);
	if (argc == 2)
		game(&mlx);
	if (argc == 3)
		printscreen(&mlx.img);
	print_massege_error(0);
	return (0);
}
