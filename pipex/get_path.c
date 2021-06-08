#include "pipex.h"

int	count_str(char **arr_str)
{
	int	count;

	count = 0;
	while (*arr_str++)
		count++;
	return (count);
}

char	**get_paths(char **enpv)
{
	char	*find_path;
	char	**paths;
	int		i;
	int		count;

	i = 0;
	count = count_str(enpv);
	find_path = NULL;
	while (i < count && !find_path)
	{
		find_path = ft_strnstr(enpv[i], "PATH=", ft_strlen(enpv[i]));
		i++;
	}
	find_path = ft_strchr(find_path, '/');
	paths = ft_split(find_path, ':');
	return (paths);
}

char	*get_pwd(char **enpv)
{
	char	*find_pwd;
	char	*pwd;
	int		i;
	int		count;

	i = 0;
	count = count_str(enpv);
	find_pwd = NULL;
	while (i < count && !find_pwd)
	{
		find_pwd = ft_strnstr(enpv[i], "PWD=", ft_strlen(enpv[i]));
		i++;
	}
	find_pwd = ft_strchr(find_pwd, '/');
	pwd = ft_strdup(find_pwd);
	return (pwd);
}

void	get_path_cmds(char ***list_cmds, char **paths, char *pwd)
{
	int	i;

	i = 0;
	while (list_cmds[i])
	{
		if (!find_path_cmd(&list_cmds[i][0], paths, pwd))
		{
			free_split(list_cmds[i]);
			list_cmds[i] = NULL;
		}
		i++;
	}
}
