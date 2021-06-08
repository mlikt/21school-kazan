#ifndef PIPEX_H
# define		PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
int		get_size_split(char **arr_c);
void	free_split(char **arr_c);
int		find_in_paths(char **name, char **paths);
int		find_in_pwd(char **name, char *pwd);
int		find_path_cmd(char **name, char **paths, char *pwd);
int		count_str(char **arr_str);
char	**get_paths(char **enpv);
char	*get_pwd(char **enpv);
void	get_path_cmds(char ***list_cmds, char **paths, char *pwd);
int		ft_isspace(char c);
char	*not_isspace(char *s);
void	valid_argv(char ***list_cmds, int count, char **argv);
char	***get_cmds(char **argv, int argc);
int		size_list_cmds(char ***list_cmds);
char	***init_list_cmds(char **argv, int argc, char **enpv, int *count);
void	error_arg(void);
int		only_path(char *s);
void	free_list_cmds(char ***list_cmds, int size);
int		size_list_cmds(char ***list_cmds);
#endif