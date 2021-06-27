#include "./header/cube.h"
#include "./header/libft.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->len) + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}

void	line(t_img *img, int *coord, int color)
{
	while (coord[1] <= coord[2])
	{
		my_mlx_pixel_put(img, coord[0], coord[1], color);
		coord[1]++;
	}
}

void	init_img(t_img *img, t_session *mlx)
{
	img->img = mlx_new_image(mlx->mlx, mlx->win->width, mlx->win->height);
	img->h = mlx->win->height;
	img->w = mlx->win->width;
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->len, &img->e);
}
