#include "./header/cube.h"

t_img	*init_texture(t_session *mlx, t_img *img, char *path)
{
	char	*format;

	format = ft_strrchr(path, '.');
	if (!ft_strncmp(format, ".png", 5))
		img->img = mlx_png_file_to_image(mlx->mlx, path, &img->w, &img->h);
	if (!ft_strncmp(format, ".xpm", 5))
		img->img = mlx_xpm_file_to_image(mlx->mlx, path, &img->w, &img->h);
	if (!img->img)
		print_massege_error(0);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->len, &img->e);
	return (img);
}
