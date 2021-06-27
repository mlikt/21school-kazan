#include "../header/valid_map.h"
#include "../header/cube.h"

void	set_direction(char c, double **arr)
{
	if (c == 'N')
	{
		(*arr)[2] = -1;
		(*arr)[3] = 0;
	}
	if (c == 'S')
	{
		(*arr)[2] = 1;
		(*arr)[3] = 0;
	}
	if (c == 'W')
	{
		(*arr)[2] = 0;
		(*arr)[3] = -1;
	}
	if (c == 'E')
	{
		(*arr)[2] = 0;
		(*arr)[3] = 1;
	}
}

double	*find_coord_and_directon(char **map)
{
	int		i;
	int		j;
	double	*arr;
	char	c;

	i = -1;
	arr = (double *)get_dynamic_array(1, 4);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			c = this_NSWE(map[i][j]);
			if (c)
			{
				set_direction(c, &arr);
				arr[0] = i;
				arr[1] = j;
				map[i][j] = '0';
				return (arr);
			}
		}
	}
	free(arr);
	return (NULL);
}

static int	count_sprite_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_sprite	**get_sprite_coord(char **map, int count)
{
	t_sprite	**sprite;
	int			i;
	int			j;

	i = -1;
	sprite = (t_sprite **)get_dynamic_array(3, count + 1);
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
			{
				sprite[count] = (t_sprite *)get_dynamic_array(4, 1);
				sprite[count]->y = j + 0.5;
				sprite[count]->x = i + 0.5;
				map[i][j] = '0';
				count++;
			}
		}
	}
	sprite[count] = NULL;
	return (sprite);
}

void	get_information_map(t_info *info, t_sprite ***sprite)
{
	valid_map(info->map);
	info->cd = find_coord_and_directon(info->map);
	info->map2 = duplicate_map(info->map);
	*sprite = get_sprite_coord(info->map, count_sprite_map(info->map));
}
