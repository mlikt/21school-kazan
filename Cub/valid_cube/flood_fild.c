#include "../header/valid_map.h"
#include "../header/cube.h"

void	free_arr(char **arr_c)
{
	int	amount;
	int	i;

	amount = size_arr(arr_c);
	i = 0;
	while (i < amount)
	{
		if (arr_c[i])
			free(arr_c[i]);
		arr_c[i] = NULL;
		i++;
	}
	free(arr_c);
	arr_c = NULL;
}

void	flood_fild(char **map, int *wh, int x, int y)
{
	if (!map[y])
		print_massege_error(1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		print_massege_error(1);
	if (x >= 0 && x < wh[0] && y >= 0 && y < wh[1] && this_replace(map[y][x]))
	{
		map[y][x] = '*';
		if (y == 0)
			print_massege_error(1);
		flood_fild(map, wh, x + 1, y);
		flood_fild(map, wh, x - 1, y);
		flood_fild(map, wh, x, y + 1);
		flood_fild(map, wh, x, y - 1);
	}	
}
