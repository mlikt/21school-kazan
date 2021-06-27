#include "./header/cube.h"

void	this_is_rendering(t_session *mlx, t_dataRay *data, int x, double *buf)
{
	get_rayDir_deltaDist(&mlx->coord, x, data, mlx->win);
	get_sideDist(&mlx->coord, data);
	DDA_algorithm(data, mlx->info->map);
	get_perpWallDist(&mlx->coord, data, buf, x);
	get_lineHeight(mlx->win, data);
}

void	draw_walls(t_session *mlx, t_dataRay *data, int x, t_img *img)
{
	NO_and_SO(mlx, data, x, img);
	WE_and_EA(mlx, data, x, img);
}

void	draw_roof_and_floor(t_dataRay *data, t_img *img, int x, t_session *mlx)
{
	int	coord[3];

	coord[2] = data->drawStart;
	coord[1] = 0;
	coord[0] = x;
	line(img, coord, mlx->info->C);
	coord[2] = mlx->win->height - 1;
	coord[1] = data->drawEnd;
	coord[0] = x;
	line(img, coord, mlx->info->F);
}

void	add_texture(t_session *mlx)
{
	init_texture(mlx, &mlx->NO, mlx->info->NO);
	init_texture(mlx, &mlx->SO, mlx->info->SO);
	init_texture(mlx, &mlx->WE, mlx->info->WE);
	init_texture(mlx, &mlx->EA, mlx->info->EA);
}
