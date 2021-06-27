#include "../header/valid_map.h"
#include "../header/cube.h"

void	replace_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}	
}

int	recognize_id(char *id)
{
	int	size;

	size = ft_strlen(id);
	if (!ft_strncmp(id, "R", size))
		return (1);
	if (!ft_strncmp(id, "NO", size))
		return (2);
	if (!ft_strncmp(id, "S", size))
		return (6);
	if (!ft_strncmp(id, "SO", size))
		return (3);
	if (!ft_strncmp(id, "WE", size))
		return (4);
	if (!ft_strncmp(id, "EA", size))
		return (5);
	if (!ft_strncmp(id, "F", size))
		return (7);
	if (!ft_strncmp(id, "C", size))
		return (8);
	return (0);
}

char	**get_identifer_and_data(char *line)
{
	char	**identifer;

	identifer = NULL;
	replace_tab(line);
	identifer = ft_split(line, ' ');
	if (!identifer)
		free(line);
	return (identifer);
}
