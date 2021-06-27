#include "./header/cube.h"

void	get_transform(t_data_sp *sp, t_sprite **sprite, t_crd *crd, int i)
{
	sp->spX = sprite[i]->x - crd->PosX;
	sp->spY = sprite[i]->y - crd->PosY;
	sp->invDet = 1.0 / (crd->planeX * crd->DirY - crd->DirX * crd->planeY);
	sp->trX = (crd->DirY * sp->spX - crd->DirX * sp->spY);
	sp->trX *= sp->invDet;
	sp->trY = (-crd->planeY * sp->spX + crd->planeX * sp->spY);
	sp->trY *= sp->invDet;
}

void	get_spriteHeight(t_win *win, t_data_sp *sp)
{
	sp->spriteScreenX = (int)((win->width / 2) * (1 + sp->trX / sp->trY));
	sp->spriteHeight = abs((int)(win->height / sp->trY));
	sp->drawStartY = -sp->spriteHeight / 2 + win->height / 2 ;
	if (sp->drawStartY < 0)
		sp->drawStartY = 0;
	sp->drawEndY = sp->spriteHeight / 2 + win->height / 2;
	if (sp->drawEndY >= win->height)
		sp->drawEndY = win->height - 1;
}

void	get_spW(t_win *win, t_data_sp *sp)
{
	sp->spW = abs((int)(win->height / sp->trY));
	sp->drawStartX = -sp->spW / 2 + sp->spriteScreenX;
	if (sp->drawStartX < 0)
		sp->drawStartX = 0;
	sp->drawEndX = (sp->spW / 2) + sp->spriteScreenX;
	if (sp->drawEndX >= (int)win->width)
		sp->drawEndX = win->width - 1;
}

void	draw_sprite(t_data_sp *sp, t_img *img, t_win *win)
{
	int		stripe;
	double	tmp;

	stripe = sp->drawStartX;
	tmp = -sp->spW / 2 + sp->spriteScreenX;
	while (stripe < sp->drawEndX && stripe < win->width)
	{
		sp->texX = (int)(256 * ((stripe - tmp) * sp->text->w / sp->spW) / 256);
		if (sp->trY > 0 && stripe > 0 && stripe < win->width
			&& sp->trY < sp->buf[stripe])
			draw_line_sp(img, sp, win, stripe);
		stripe++;
	}
}

void	draw_sprites(double *buf, t_session *mlx, t_img *img)
{
	int			*sprite_order;
	double		*sprite_dis;
	int			count;
	t_data_sp	sp;
	int			i;

	i = -1;
	sp.l = get_matrix(mlx->win->height, mlx->win->width);
	sp.text = &mlx->S;
	count = count_sprite(mlx->info->sprite);
	sprite_order = (int *)get_dynamic_array(0, count);
	sprite_dis = (double *)get_dynamic_array(1, count);
	init_ord_dist(&mlx->coord, sprite_order, sprite_dis, mlx->info->sprite);
	sortSprites(sprite_order, sprite_dis, count);
	sp.buf = buf;
	while (++i < count)
	{
		get_transform(&sp, mlx->info->sprite, &mlx->coord, sprite_order[i]);
		get_spriteHeight(mlx->win, &sp);
		get_spW(mlx->win, &sp);
		draw_sprite(&sp, img, mlx->win);
	}
	free_matrix(sp.l, mlx->win->width);
	free(sprite_order);
	free(sprite_dis);
}
