#include "pipex.h"

int	get_size_split(char **arr_c)
{
	int	i;

	i = 0;
	while (arr_c[i])
		i++;
	return (i);
}

void	free_split(char **arr_c)
{
	int	amount;
	int	i;

	amount = get_size_split(arr_c);
	i = 0;
	while (i < amount)
	{
		free(arr_c[i]);
		arr_c[i] = NULL;
		i++;
	}
	free(arr_c);
	arr_c = NULL;
}

int	find_in_paths(char **name, char **paths)
{
	int		i;
	int		fd;
	char	*path;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, *name);
		free(tmp);
		fd = open(path, O_RDONLY);
		if (fd != -1)
		{
			tmp = *name;
			*name = path;
			free(tmp);
			close(fd);
			return (1);
		}
		free(path);
		i++;
	}
	return (0);
}

int	find_in_pwd(char **name, char *pwd)
{
	int		fd;
	char	*path;
	char	*tmp;

	tmp = ft_strjoin(pwd, "/");
	path = ft_strjoin(tmp, *name);
	free(tmp);
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		tmp = *name;
		*name = path;
		free(tmp);
		close(fd);
		return (1);
	}
	free(path);
	return (0);
}

int	find_path_cmd(char **name, char **paths, char *pwd)
{
	int	check;

	check = 0;
	check = find_in_paths(name, paths);
	if (check)
		return (check);
	check = find_in_pwd(name, pwd);
	return (check);
}
