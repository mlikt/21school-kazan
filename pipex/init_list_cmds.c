#include "pipex.h"

char	***get_cmds(char **argv, int argc)
{
	char	***list_cmds;
	char	**empty;
	int		i;

	i = 0;
	empty = NULL;
	list_cmds = malloc(sizeof(list_cmds) * (argc + 1));
	while (argv[i + 3])
	{
		if (ft_strlen(argv[i + 2]))
			list_cmds[i] = ft_split(argv[i + 2], ' ');
		else
		{
			empty = malloc(sizeof(empty) * 2);
			empty[0] = ft_substr("", 0, 1);
			empty[1] = NULL;
			list_cmds[i] = empty;
		}
		i++;
	}
	list_cmds[argc] = NULL;
	return (list_cmds);
}

int	size_list_cmds(char ***list_cmds)
{
	int	i;

	i = 0;
	while (*list_cmds++)
		i++;
	return (i);
}

char	***init_list_cmds(char **argv, int argc, char **enpv, int *count)
{
	char	**paths;
	char	***list_cmds;
	char	*pwd;

	paths = get_paths(enpv);
	pwd = get_pwd(enpv);
	list_cmds = get_cmds(argv, argc - 3);
	*count = size_list_cmds(list_cmds);
	get_path_cmds(list_cmds, paths, pwd);
	free_split(paths);
	free(pwd);
	return (list_cmds);
}

void	free_list_cmds(char ***list_cmds, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (list_cmds[i])
			free_split(list_cmds[i]);
		i++;
	}
	free(list_cmds);
}
