#include "./header/cube.h"

int	get_color_channel(t_img *img, int x, int y, int i)
{
	char			*dst;
	unsigned char	color;

	dst = img->addr + ((y * img->len) + x * (img->bits / 8));
	color = *(dst + i);
	return (color);
}

int	get_color(t_img *img, int x, int y)
{
	int	T;
	int	R;
	int	G;
	int	B;

	T = get_color_channel(img, x, y, 3);
	R = get_color_channel(img, x, y, 2);
	G = get_color_channel(img, x, y, 1);
	B = get_color_channel(img, x, y, 0);
	return (T << 24 | R << 16 | G << 8 | B);
}

int	exit_win(void)
{
	exit(0);
}
