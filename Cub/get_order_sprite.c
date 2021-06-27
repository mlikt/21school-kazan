#include "./header/cube.h"

void	*get_dynamic_array(unsigned int i, int amount)
{
	void	*array;

	if (i == 0)
		i = sizeof(int);
	if (i == 1)
		i = sizeof(double);
	if (i == 2)
		i = sizeof(char);
	if (i == 3)
		i = sizeof(t_sprite *);
	if (i == 4)
		i = sizeof(t_sprite);
	if (i == 5)
		i = sizeof(t_info);
	array = malloc(i * amount);
	if (!array)
		print_massege_error_id(5, NULL);
	return (array);
}

void	init_ord_dist(t_crd *crd, int *order, double *dis, t_sprite **sp)
{
	int	i;
	int	amount;

	i = 0;
	amount = count_sprite(sp);
	while (i < amount)
	{
		order[i] = i;
		dis[i] = pow((crd->PosX - sp[i]->x), 2);
		dis[i] += pow((crd->PosY - sp[i]->y), 2);
		i++;
	}
}
