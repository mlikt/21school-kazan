#include "pipex.h"

int	ft_isspace(char c)
{
	if ((c >= 10 && c <= 12) || c == 32)
		return (1);
	return (0);
}

char	*not_isspace(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (&s[i]);
}

void	valid_argv(char ***list_cmds, int count, char **argv)
{
	int		i;
	size_t	size;
	char	*name;

	i = 0;
	while (i < count)
	{
		if (!list_cmds[i])
		{
			size = (ft_strchr(argv[i + 2], ' ') - argv[i + 2]);
			name = ft_substr(not_isspace(argv[i + 2]), 0, size + 1);
			ft_putstr_fd("./pipex: command not found: ", 2);
			ft_putstr_fd(name, 2);
			ft_putstr_fd("\n", 2);
			free(name);
		}
		i++;
	}
}
