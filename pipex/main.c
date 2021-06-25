#include "pipex.h"

void	write_outfile_or_pipe(int *fd, int *fd_file, char ***list_cmds, int *i)
{
	if (!list_cmds[i[0] - i[1]])
		return ;
	dup2(fd_file[0], 0);
	if (i[1] > 1)
		dup2(fd[1], 1);
	else if (i[1] == 1)
		dup2(fd_file[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(fd_file[1]);
	if (execve(list_cmds[i[0] - i[1]][0], list_cmds[i[0] - i[1]], list_cmds[i[0]]) == -1)
	{
		if (only_path(list_cmds[i[0] - i[1]][0]))
			perror("./pipex");
		else
			perror(list_cmds[i[0] - i[1]][0]);
	}
}

void	new_fork_list(pid_t pid, int *index, int *fd_file, char ***list_cmds)
{
	int	fd[2];

	if (index[1] > 0)
	{
		if (pipe(fd) == -1)
			perror("pipe ");
		pid = fork();
		if (pid == -1)
			perror("fork ");
	}
	if (pid && index[1] > 0)
	{
		wait(0);
		index[1] = index[1] - 1;
		close(fd[1]);
		fd[1] = fd_file[1];
		close(fd_file[0]);
		new_fork_list(pid, index, fd, list_cmds);
	}
	else if (!pid)
		write_outfile_or_pipe(fd, fd_file, list_cmds, index);
}

void	open_files(int *fd, char *in, char *out)
{
	fd[0] = open(in, O_RDONLY);
	if (fd[0] == -1)
	{	
		ft_putstr_fd("./pipex: ", 2);
		ft_putstr_fd("file not found: ", 2);
		ft_putendl_fd(in, 2);
	}
	fd[1] = open(out, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
}

int	main(int argc, char **argv, char **enpv)
{
	char	***list_cmds;
	int		fd[2];
	int		arr[2];
	pid_t	pid;

	if (argc < 4)
		error_arg();
	pid = 1;
	arr[1] = argc - 3;
	list_cmds = init_list_cmds(argv, argc, enpv, &arr[0]);
	list_cmds[arr[0]] = enpv;
	open_files(fd, argv[1], argv[argc - 1]);
	valid_argv(list_cmds, arr[0], argv);
	new_fork_list(pid, arr, fd, list_cmds);
	if (pid)
		free_list_cmds(list_cmds, arr[0]);
	return (0);
}
