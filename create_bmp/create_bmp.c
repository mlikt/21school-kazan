#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_bmp_file
{
	int		h;
	int		w;
	int		fd;
	int		size;
	int		line_length;
	char	*data;
}				t_bmp_file;

int	get_size_img(int w, int h)
{
	int	size;

	size = (((w * 3) % 4) * 3 + (3 * w)) * h + 54;
	if (w % 4 == 2)
		size -= ((3 * h) + h);
	if (w % 4 == 1)
		size -= (8 + (h - 1) * 8);
	return (size);
}

char	*create_bmp(unsigned int w, unsigned int h)
{
	char	*buf;
	int		size;

	size = get_size_img(w, h);
	buf = calloc(sizeof(char), size);
	if (!buf)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	/* Заполняем BITMAPHEADERFILE */
	buf[0] = 'B';
	buf[1] = 'M';
	*((int *)(buf + 2)) = size;
	*((int *)(buf + 6)) = 0x00;
	*((int *)(buf + 10)) = 14 + 40;
	/* Заполняем BITMAPINFO */
	*((int *)(buf + 14)) = 40;
	*((unsigned int *)(buf + 18)) = w;
	*((unsigned int *)(buf + 22)) = h;
	*((short unsigned int *)(buf + 26)) = (short)1;
	*((short unsigned int *)(buf + 28)) = (short)24;
	*((int *)(buf + 30)) = 0x00;
	*((int *)(buf + 34)) = size - 54;
	*((int *)(buf + 38)) = 0x0B13;
	*((int *)(buf + 42)) = 0x0B13;
	*((int *)(buf + 46)) = 0x00;
	*((int *)(buf + 50)) = 0x00;
	return (buf);
}

void	draw_pix(int x, int y, t_bmp_file *img, unsigned int color)
{
	char			*tmp;
	unsigned char	color_c[3];

	color_c[2] = (unsigned char)(color >> 16);
	color_c[1] = (unsigned char)(color >> 8);
	color_c[0] = (unsigned char)(color >> 0);
	tmp = (img->data + 54) + (img->h - (y + 1)) * img->line_length + x * 3;
	*tmp = *color_c;
	*(tmp + 1) = *(color_c + 1);
	*(tmp + 2) = *(color_c + 2);
}

void	init_bmp_file(t_bmp_file *file, int h, int w)
{
	file->w = w;
	file->h = h;
	file->fd = open("file.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	file->size = get_size_img(w, h);
	file->line_length = (file->size - 54) / h;
	file->data = create_bmp(w, h);
}

void	output_file(t_bmp_file *file)
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

int	main(void)
{
	t_bmp_file	image;
	int			x;
	int			y;

	init_bmp_file(&image, 1000, 1000);
	x = image.w;
	while (x >= 0)
	{
		y = image.h - 1;
		while (y >= 0)
		{
			draw_pix(x, y, &image, 0x00FFFFFF);
			y--;
		}
		x--;
	}
	output_file(&image);
	return (0);
}
