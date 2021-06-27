#include "../header/valid_map.h"
#include "../header/cube.h"

char	**duplicate_map(char **map)
{
	char	**dup_map;
	int		i;

	i = 0;
	dup_map = malloc(sizeof(char *) * (size_arr(map) + 1));
	if (!dup_map)
		print_massege_error_id(5, NULL);
	while (map[i])
	{
		dup_map[i] = NULL;
		dup_map[i] = ft_calloc(ft_strlen(map[i]), sizeof(char) + 1);
		if (dup_map[i] == NULL)
			print_massege_error_id(5, NULL);
		ft_memcpy(dup_map[i], map[i], ft_strlen(map[i]));
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}
