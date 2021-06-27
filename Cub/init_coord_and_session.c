#include "./header/cube.h"

void	init_win_size(t_win *win, int height, int width)
{
	win->height = height;
	win->width = width;
}

void	init_plane(t_crd *coord, double posX, double posY)
{
	if (posX == 0 && posY == 1)
	{
		coord->planeX = 0.66;
		coord->planeY = 0;
	}
	if (posX == 0 && posY == -1)
	{
		coord->planeX = -0.66;
		coord->planeY = 0;
	}
	if (posX == -1 && posY == 0)
	{
		coord->planeX = 0;
		coord->planeY = 0.66;
	}
	if (posX == 1 && posY == 0)
	{
		coord->planeX = 0;
		coord->planeY = -0.66;
	}
}

void	init_coord_position(t_crd *coord, double posX, double posY)
{
	coord->PosX = posX + 0.5;
	coord->PosY = posY + 0.5;
}

void	init_coord_direction(t_crd *coord, double DirX, double DirY)
{
	coord->DirX = DirX;
	coord->DirY = DirY;
	init_plane(coord, DirX, DirY);
}

void	init_session(t_session *mlx, t_win *win, int fd)
{
	mlx->mlx = mlx_init();
	mlx->info = get_information_file(fd, mlx->mlx);
	init_win_size(win, mlx->info->R[1], mlx->info->R[0]);
	init_texture(mlx, &mlx->S, mlx->info->S);
	init_coord_direction(&mlx->coord, mlx->info->cd[2], mlx->info->cd[3]);
	init_coord_position(&mlx->coord, mlx->info->cd[0], mlx->info->cd[1]);
	add_texture(mlx);
	mlx->win = win;
	mlx->win_ptr = mlx_new_window(mlx->mlx, win->width, win->height, "My game");
	close(fd);
}
