#include "./header/cube.h"

void	draw_pix_bmp(int x, int y, t_bmp_file *img, unsigned int color)
{
	char			*tmp;
	unsigned char	color_c[3];

	color_c[2] = (unsigned char)(color >> 16);
	color_c[1] = (unsigned char)(color >> 8);
	color_c[0] = (unsigned char)(color >> 0);
	tmp = (img->data + 54);
	tmp += (img->h - (y + 1)) * img->line_length + x * 3;
	*tmp = *color_c;
	*(tmp + 1) = *(color_c + 1);
	*(tmp + 2) = *(color_c + 2);
}

void	init_bmp_file(t_bmp_file *file, int h, int w)
{
	file->w = w;
	file->h = h;
	file->fd = open("screen.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR);
	file->size = get_size_img_bmp(w, h);
	file->line_length = (file->size - 54) / h;
	file->data = create_bmp(w, h);
}

void	output_file_bmp(t_bmp_file *file)
{
	int	i;
	int	rem;

	i = 0;
	rem = file->size;
	while (i < file->size)
	{	
		if (rem / 512)
		{
			write(file->fd, &file->data[i], 512);
			rem -= 512;
		}
		else
			write(file->fd, &file->data[i], rem % 512);
		i += 512;
	}
}

void	printscreen(t_img *img)
{
	t_bmp_file	file;
	int			x;
	int			y;
	int			color;

	init_bmp_file(&file, img->h, img->w);
	x = 0;
	while (x < file.w)
	{
		y = 0;
		while (y < file.h)
		{
			color = get_color(img, x, y);
			draw_pix_bmp(x, y, &file, color);
			y++;
		}
		x++;
	}
	write(1, "Printscreen!\n", ft_strlen("Printscreen!\n"));
	output_file_bmp(&file);
	free(file.data);
	exit(0);
}
