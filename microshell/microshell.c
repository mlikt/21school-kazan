#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s
{
	char		*name;
	char		**argv;
	struct s	*next;
}	pipe_block;

typedef struct t
{
	pipe_block 	*cmd;
	struct t 	*next;
}	comand_block;

size_t ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

void exit_error(char *msg, char *arg)
{
	write(2, msg, ft_strlen(msg));
	if (arg)
	{
		write(2, arg, ft_strlen(arg));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void *malloc_x(size_t size)
{
	void *ptr = malloc(size);
	if (!ptr)
		exit_error("error: fatal\n" , NULL);
	return (ptr);
}

pipe_block *create_cmd( void )
{
	pipe_block *cmd = malloc_x(sizeof(pipe_block));
	cmd->name = NULL;
	cmd->argv = malloc_x(sizeof(char *) * 2);
	cmd->argv[0] = NULL;
	cmd->argv[1] = NULL;
	cmd->next = NULL;
	return (cmd);
}

void free_cmd(pipe_block *cmd)
{
	pipe_block *tmp;

	while (cmd)
	{
		tmp = cmd->next;
		free(cmd->argv);
		free(cmd);
		cmd = tmp;
	}
}

void free_block(comand_block *block)
{
	comand_block *tmp;

	while (block)
	{
		tmp = block->next;
		free_cmd(block->cmd);
		free (block);
		block = tmp;
	}
}

comand_block *create_block( void )
{
	comand_block *block = malloc_x(sizeof(comand_block));
	block->cmd = create_cmd();
	block->next = NULL;
	return (block);
}

int size_arr(char **argv)
{
	int i = 0;
	while(argv[i])
		i++;
	return (i);
}

char **realloc_arr(char **argv, char *new)
{
	char **tmp;
	int i = 0;
	tmp = argv;

	argv = malloc_x((sizeof(char *) * size_arr(argv)) + (sizeof(char *) * 2));
	while (tmp[i])
	{
		argv[i] = tmp[i];
		i++;
	}
	argv[i] = new;
	argv[i + 1] = NULL;
	free(tmp);
	return (argv);
}

comand_block *get_cmds(char **argv)
{
	comand_block *block = create_block();
	comand_block *tmp = block;
	pipe_block *first_cmd = NULL;
	int i = 0;

	while (argv[i])
	{
		if (!tmp->cmd->name)
		{
			tmp->cmd->name = argv[i];
			tmp->cmd->argv[0] = argv[i];
			i++;
			continue ;
		}
		if (!strcmp("|", argv[i]))
		{
			if (!first_cmd)
				first_cmd = tmp->cmd; 
			if (argv[i + 1])
			{
				tmp->cmd->next = create_cmd();
				tmp->cmd = tmp->cmd->next;
			}
			i++;
			continue ;
		}
		if (!strcmp(";", argv[i]))
		{
			if (first_cmd)
			{
				tmp->cmd = first_cmd;
				first_cmd = NULL;
			}
			if (argv[i + 1])
			{
				tmp->next = create_block();
				tmp = tmp->next;
			}
			i++;
			continue ;
		}
		tmp->cmd->argv = realloc_arr(tmp->cmd->argv, argv[i]);
		i++;
	}
	if (i == 0)
	{
		free_block(block);
		return (NULL);
	}
	if (first_cmd)
		tmp->cmd = first_cmd;
	return (block);
}

void pipex (pipe_block *cmd, int in, char **envp)
{
	int fd[2];
	pid_t pid;
	
	if (!cmd)
		return ;
	if (cmd->next)
		if(pipe(fd) == -1)
			exit_error("error: fatal\n", NULL);
	pid = fork();
	if (pid == -1)
		exit_error("error: fatal\n", NULL);
	if (!pid)
	{
		if (cmd->next)
			close(fd[0]);
		if (dup2(in, 0) < 0)
				exit_error("error: fatal\n", NULL);
		if (cmd->next)
			if (dup2(fd[1], 1) < 0)
				exit_error("error: fatal\n", NULL);
		execve(cmd->name, cmd->argv, envp);
		exit_error("error: cannot execute ", cmd->name);
	}
	else
	{
		close(fd[1]);
		if (in > 2)
			close(in);
		pipex(cmd->next, fd[0], envp);
	}
}

void cd (pipe_block *cmd, int *out)
{
	if (size_arr(cmd->argv) != 2)
	{
		write(2, "error: cd: bad arguments\n", 26);
		*out = EXIT_FAILURE;
		return ;
	}
	if (chdir(cmd->argv[1]) != 0)
	{
		write(2, "error: cd: cannot change directory to ", 39);
		write(2, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(2, "\n", 1);
		*out = EXIT_FAILURE;
	}
}

int microshell(comand_block *block, char **envp)
{
	pid_t pid;
	int out;
	int status;

	while (block)
	{
			out = EXIT_SUCCESS;
			if(!strcmp(block->cmd->name, "cd"))
				cd(block->cmd, &out);
			else
			{
				pipex(block->cmd, 0, envp);
				pipe_block *tmp = block->cmd;
				while(tmp)
				{
					waitpid(0, &status, 0);
					if (WIFEXITED(status))
						out = WEXITSTATUS(status);
					tmp = tmp->next;
				}
			}
		block = block->next;
	}	
	return (out);
}

int main (int argc, char **argv, char **envp)
{
	(void)argc;
	comand_block *block = get_cmds(argv + 1);
	int out = EXIT_SUCCESS;

	if (block)
	{
		out = microshell(block, envp);
		free_block(block);
	}
	return (out);
}