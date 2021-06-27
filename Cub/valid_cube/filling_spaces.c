#include "../header/valid_map.h"
#include "../header/cube.h"

int	find_max_lenght(char **map)
{
	int	max;
	int	i;

	i = 0;
	max = ft_strlen(map[++i]);
	while (map[i])
	{
		if (max < (int)ft_strlen(map[i]))
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

char	*filling_str_space(char *s, int size)
{
	char	*new_s;
	int		i;

	new_s = ft_calloc(sizeof(char), size + 1);
	ft_memcpy(new_s, s, ft_strlen(s));
	i = ft_strlen(s);
	while (i < size)
	{
		new_s[i] = ' ';
		i++;
	}
	free(s);
	return (new_s);
}

void	filling_map_space(char **map)
{
	int	size;
	int	i;

	i = 0;
	size = find_max_lenght(map);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < size)
			map[i] = filling_str_space(map[i], size);
		i++;
	}
}
