#include "./header/cube.h"

int	**get_matrix(int h, int w)
{
	int	**l;
	int	i;

	l = ft_calloc(sizeof(int *), w);
	if (!l)
		print_massege_error_id(5, NULL);
	i = 0;
	while (i < w)
	{
		l[i] = ft_calloc(sizeof(int), h);
		if (!l[i])
			print_massege_error_id(5, NULL);
		i++;
	}
	return (l);
}

void	free_matrix(int **l, int w)
{
	int	i;

	i = 0;
	while (i < w)
	{
		free(l[i]);
		i++;
	}
	free(l);
}

void	draw_line_sp(t_img *img, t_data_sp *sp, t_win *win, int stripe)
{
	int	color;
	int	y;
	int	d;

	y = sp->drawStartY;
	while (y < sp->drawEndY)
	{
		if (!sp->l[stripe][y])
		{
			d = y * 256 - win->height * 128 + sp->spriteHeight * 128;
			sp->texY = ((d * sp->text->h) / sp->spriteHeight) / 256;
			color = get_color(sp->text, sp->texX, sp->texY);
			if ((color & 0x00FFFFFF) != 0)
			{
				apply_pixel(img, stripe, y, color);
				sp->l[stripe][y] = 1;
			}
		}
		y++;
	}
}
