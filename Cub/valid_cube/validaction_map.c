#include "../header/valid_map.h"
#include <stdio.h>

void	print_massege_error(int nbr_error)
{
	ft_putstr_fd("Error\n", 2);
	if (nbr_error == 1)
		ft_putendl_fd("Map is not closed!", 2);
	if (nbr_error == 2)
		ft_putendl_fd("Double position!", 2);
	if (nbr_error == 3)
		ft_putendl_fd("Sprite out of field!", 2);
	if (nbr_error == 4)
		ft_putendl_fd("Not vallid simbol!", 2);
	if (nbr_error == 5)
		ft_putendl_fd("No player!", 2);
	if (nbr_error == 6)
	{
		ft_putstr_fd("Unknown identifier", 2);
		ft_putendl_fd("or or not set.", 2);
	}
	exit (-1);
}

int	valid_simbol_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!this_NSWE(map[i][j]) && !this_wall_empty_sprite(map[i][j]))
				print_massege_error(4);
			j++;
		}
		i++;
	}
	return (1);
}

double	*valid_direction_get_coord(char **map)
{
	double	*cd;

	cd = find_coord_and_directon(map);
	if (!cd)
		print_massege_error(5);
	if (!find_coord_and_directon(&map[(int)cd[0]]))
		return (cd);
	free(cd);
	return (NULL);
}

void	find_sprite_outfeild(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				print_massege_error(3);
			j++;
		}
		i++;
	}
}

void	valid_map(char **map)
{
	char	**dup;
	double	*tmp_cord;
	int		wh[2];

	dup = duplicate_map(map);
	wh[0] = ft_strlen(dup[0]);
	wh[1] = size_arr(dup);
	tmp_cord = valid_direction_get_coord(dup);
	if (tmp_cord)
	{
		valid_simbol_map(dup);
		flood_fild(dup, wh, (int)tmp_cord[1], (int)tmp_cord[0]);
		find_sprite_outfeild(dup);
		free_arr(dup);
		free(tmp_cord);
	}
	else
		print_massege_error(2);
}
