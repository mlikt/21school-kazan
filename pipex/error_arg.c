#include "pipex.h"

void	error_arg(void)
{
	ft_putstr_fd("Please use at least 4 arguments:\n", 2);
	ft_putstr_fd("./pipex infile cmd1 ... cmdN outfile\n", 2);
	exit(0);
}

int	only_path(char *s)
{
	s = ft_strrchr(s, '/');
	if (s[1] == 0)
		return (1);
	return (0);
}
