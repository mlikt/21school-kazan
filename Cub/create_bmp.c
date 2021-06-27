#include "./header/cube.h"

int	get_size_img_bmp(int w, int h)
{
	int	size;

	size = (((w * 3) % 4) * 3 + (3 * w)) * h + 54;
	if (w % 4 == 2)
		size -= ((3 * h) + h);
	if (w % 4 == 1)
		size -= (8 + (h - 1) * 8);
	return (size);
}

void	create_header_bmp(char *buf, int size, int w, int h)
{
	buf[0] = 'B';
	buf[1] = 'M';
	*((int *)(buf + 2)) = size;
	*((int *)(buf + 6)) = 0x00;
	*((int *)(buf + 10)) = 14 + 40;
	*((int *)(buf + 14)) = 40;
	*((unsigned int *)(buf + 18)) = w;
	*((unsigned int *)(buf + 22)) = h;
	*((short unsigned int *)(buf + 26)) = (short)1U;
	*((short unsigned int *)(buf + 28)) = (short)24U;
	*((int *)(buf + 30)) = 0x00;
	*((int *)(buf + 34)) = size - 54;
	*((int *)(buf + 38)) = 0x0B13;
	*((int *)(buf + 42)) = 0x0B13;
	*((int *)(buf + 46)) = 0x00;
	*((int *)(buf + 50)) = 0x00;
}

char	*create_bmp(unsigned int w, unsigned int h)
{
	char	*buf;
	int		size;

	size = get_size_img_bmp(w, h);
	buf = ft_calloc(sizeof(char), size);
	if (!buf)
		print_massege_error(0);
	create_header_bmp(buf, size, w, h);
	return (buf);
}
