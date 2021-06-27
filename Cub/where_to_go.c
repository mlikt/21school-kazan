#include "header/struct.h"

void	go_forward_or_backward(int S, int W, char **map, t_crd *crd)
{
	if (W)
	{
		if (map[(int)(crd->PosX + crd->DirX)][(int)crd->PosY] == '0')
			crd->PosX += 0.2 * crd->DirX;
		if (map[(int)crd->PosX][(int)(crd->PosY + crd->DirY)] == '0')
			crd->PosY += 0.2 * crd->DirY;
	}
	if (S)
	{
		if (map[(int)(crd->PosX - crd->DirX)][(int)crd->PosY] == '0')
			crd->PosX -= 0.2 * crd->DirX;
		if (map[(int)crd->PosX][(int)(crd->PosY - crd->DirY)] == '0')
			crd->PosY -= 0.2 * crd->DirY;
	}
}

void	in_left(int left, t_crd *crd)
{
	double	oldDirX;
	double	oldPlaneX;

	if (left)
	{
		oldDirX = crd->DirX;
		crd->DirX = crd->DirX * cos(0.05) - crd->DirY * sin(0.05);
		crd->DirY = oldDirX * sin(0.05) + crd->DirY * cos(0.05);
		oldPlaneX = crd->planeX;
		crd->planeX = crd->planeX * cos(0.05) - crd->planeY * sin(0.05);
		crd->planeY = oldPlaneX * sin(0.05) + crd->planeY * cos(0.05);
	}
}

void	in_right(int right, t_crd *crd)
{
	double	oldDirX;
	double	oldPlaneX;

	if (right)
	{
		oldDirX = crd->DirX;
		crd->DirX = crd->DirX * cos(-0.05) - crd->DirY * sin(-0.05);
		crd->DirY = oldDirX * sin(-0.05) + crd->DirY * cos(-0.05);
		oldPlaneX = crd->planeX;
		crd->planeX = crd->planeX * cos(-0.05) - crd->planeY * sin(-0.05);
		crd->planeY = oldPlaneX * sin(-0.05) + crd->planeY * cos(-0.05);
	}
}

void	turn_right_or_left(int left, int right, t_crd *crd)
{
	in_left(left, crd);
	in_right(right, crd);
}

void	go_right_or_left(int A, int D, char **map, t_crd *crd)
{
	if (A)
	{
		if (map[(int)(crd->PosX - crd->planeX)][(int)crd->PosY] == '0')
			crd->PosX -= 0.2 * crd->planeX;
		if (map[(int)crd->PosX][(int)(crd->PosY - crd->planeY)] == '0')
			crd->PosY -= 0.2 * crd->planeY;
	}
	if (D)
	{
		if (map[(int)(crd->PosX + crd->planeX)][(int)crd->PosY] == '0')
			crd->PosX += 0.2 * crd->planeX;
		if (map[(int)crd->PosX][(int)(crd->PosY + crd->planeY)] == '0')
			crd->PosY += 0.2 * crd->planeY;
	}
}
