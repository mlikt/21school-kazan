#include "../header/valid_map.h"
#include "../header/cube.h"

char	**alloc_map(int i)
{
	char	**tmp;

	tmp = NULL;
	if (i)
	{
		tmp = (char **)malloc(sizeof(char *) * (i + 2));
		if (!tmp)
			return (NULL);
		tmp[i + 1] = NULL;
	}
	else
	{
		tmp = (char **)malloc(sizeof(char *) * 2);
		if (!tmp)
			return (NULL);
		tmp[1] = NULL;
	}
	return (tmp);
}

int	size_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	copy_pointers(char **dest, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char	**add_new_line_map(int i, char **tmp, char **map, char *buf)
{
	char	**tmp_free;

	if (!i)
	{
		tmp[i] = buf;
		map = tmp;
	}
	else
	{
		tmp[i] = buf;
		copy_pointers(tmp, map);
		tmp_free = map;
		map = tmp;
		free(tmp_free);
	}
	return (map);
}

char	**get_map(int fd)
{
	char	*buf;
	int		tumb;
	int		i;
	char	**tmp;
	char	**map;

	i = 0;
	tumb = 1;
	while (tumb)
	{
		tumb = get_next_line(fd, &buf);
		tmp = alloc_map(i);
		map = add_new_line_map(i, tmp, map, buf);
		i++;
	}
	return (map);
}
