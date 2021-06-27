#include "./header/cube.h"

int	count_sprite(t_sprite **sprite)
{
	int	i;

	i = 0;
	while (sprite[i])
		i++;
	return (i);
}

void	swap_d(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	swap_i(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	comb_sort(t_for_sort *sp, int count)
{
	double	factor;
	int		step;
	int		i;

	factor = 1.2473309;
	step = count - 1;
	while (step >= 1)
	{
		i = 0;
		while ((i + step) < count)
		{
			if (sp[i].dist > sp[i + step].dist)
			{
				swap_d(&sp[i].dist, &sp[i + step].dist);
				swap_i(&sp[i].order, &sp[i + step].order);
			}
			i++;
		}
		step /= factor;
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_for_sort	*sp;
	int			i;

	sp = malloc(sizeof(t_for_sort) * amount);
	if (!sp)
		print_massege_error(0);
	i = 0;
	while (i < amount)
	{
		sp[i].order = order[i];
		sp[i].dist = dist[i];
		i++;
	}
	comb_sort(sp, amount);
	i = 0;
	while (i < amount)
	{
		order[i] = sp[i].order;
		dist[i] = sp[i].dist;
		i++;
	}
	free(sp);
}
