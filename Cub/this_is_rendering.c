#include "./header/cube.h"

void	get_rayDir_deltaDist(t_crd *c, int x, t_dataRay *d, t_win *w)
{
	d->cameraX = 2 * x / (double)w->width - 1;
	d->rayDirX = c->DirX + c->planeX * d->cameraX;
	d->rayDirY = c->DirY + c->planeY * d->cameraX;
	d->deltaDistX = fabs(1 / d->rayDirX);
	d->deltaDistY = fabs(1 / d->rayDirY);
	d->mapX = (int)(c->PosX);
	d->mapY = (int)(c->PosY);
}

void	get_sideDist(t_crd *coord, t_dataRay *data)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (coord->PosX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - coord->PosX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (coord->PosY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - coord->PosY) * data->deltaDistY;
	}
}

void	DDA_algorithm(t_dataRay *data, char **map)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
			data->color = 0x00FF0000;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
			data->color = 0x007F0000;
		}
		if (map[data->mapX][data->mapY] != '0')
			data->hit = 1;
	}
}

void	get_perpWallDist(t_crd *coord, t_dataRay *data, double *buf, int x)
{
	if (data->side == 0)
	{
		data->perpWallDist = (data->mapX - coord->PosX + (1 - data->stepX) / 2);
		data->perpWallDist /= data->rayDirX;
		data->WallX = coord->PosY + data->perpWallDist * data->rayDirY;
	}
	else
	{
		data->perpWallDist = (data->mapY - coord->PosY + (1 - data->stepY) / 2);
		data->perpWallDist /= data->rayDirY;
		data->WallX = coord->PosX + data->perpWallDist * data->rayDirX;
	}
	data->WallX -= floor(data->WallX);
	buf[x] = data->perpWallDist;
}

void	get_lineHeight(t_win *win, t_dataRay *data)
{
	data->lineHeight = (int)(win->height / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + win->height / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + win->height / 2;
	if (data->drawEnd >= (int)win->height)
		data->drawEnd = win->height - 1;
}
