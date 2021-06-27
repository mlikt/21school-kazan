#include "./header/cube.h"

void	apply_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->len) + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}

void	get_texX(t_dataRay *data, t_win *win, t_img *img)
{
	data->texX = (int)(data->WallX * (double)img->w);
	if (data->side == 1 && data->rayDirY < 0)
		data->texX = img->w - data->texX - 1;
	if (data->side == 0 && data->rayDirX > 0)
		data->texX = img->w - data->texX - 1;
	data->step = 1.0 * img->h / data->lineHeight;
	data->texPos = data->drawStart - win->height / 2 + data->lineHeight / 2;
	data->texPos *= data->step;
}

void	draw_line_tex(t_img *img, t_img *texture, int x, t_dataRay *data)
{
	int	y;
	int	color;

	y = data->drawStart;
	while (y < data->drawEnd)
	{
		data->texY = (int)data->texPos & texture->h - 1;
		data->texPos += data->step;
		color = get_color(texture, data->texX, data->texY);
		apply_pixel(img, x, y, color);
		y++;
	}
}

void	NO_and_SO(t_session *mlx, t_dataRay *data, int x, t_img *img)
{
	if (data->side == 0)
	{
		if (data->stepX == 1)
		{	
			get_texX(data, mlx->win, &mlx->NO);
			draw_line_tex(img, &mlx->SO, x, data);
		}
		else
		{
			get_texX(data, mlx->win, &mlx->SO);
			draw_line_tex(img, &mlx->NO, x, data);
		}
	}
}

void	WE_and_EA(t_session *mlx, t_dataRay *data, int x, t_img *img)
{
	if (data->side == 1)
	{
		if (data->stepY == 1)
		{
			get_texX(data, mlx->win, &mlx->WE);
			draw_line_tex(img, &mlx->EA, x, data);
		}
		else
		{
			get_texX(data, mlx->win, &mlx->EA);
			draw_line_tex(img, &mlx->WE, x, data);
		}
	}
}
