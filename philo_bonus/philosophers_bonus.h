#ifndef PHILOSOPHERS_BONUS_H
# define	PHILOSOPHERS_BONUS_H
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>
# include "utils.h"
# define FORK "/fork"
# define PRINT "/print"
# define SLEEP		0
# define EAT		1
# define DEAD		2
# define THINKING	3
# define TAKE_FORK	4

typedef struct s_timer
{
	long unsigned int	v;
	struct s_rule		*rule;
}				t_timer;

typedef struct s_fork
{
	sem_t	*sem;
}				t_fork;

typedef struct s_philos
{
	int						n;
	int						eat;
	long unsigned int		limit;
	t_fork					*l_fork;
	t_fork					*r_fork;
	pid_t					pid;
	struct s_rule			*rule;
	t_timer					*timer;
}				t_philos;

typedef struct s_rule
{
	int							number_of_philo;
	int							number_of_eating;
	long unsigned int			time_of_eat;
	long unsigned int			time_of_sleep;
	long unsigned int			time_of_die;
	int							fix_eat;
	int							fix_dead;
	sem_t						*sem_print;
	t_philos					*ph;
}				t_rule;

void	status(sem_t *mt, int code, long unsigned int time, int n);
t_rule	*init_rule(char **argv, int argc);
int		sleeping(t_philos *ph);
void	put_fork(t_philos *ph);
int		eating(t_philos *ph);
void	get_fork(t_philos *ph);
int		dead(t_philos *ph);
int		supervision(long unsigned int time, t_philos *ph);
int		if_one(t_philos *ph);
void	smart_sleep(long unsigned int time);
int		ft_atoi(const char *str);
int		valid_argv(char **argv);
int		valid_rule(t_rule *rule);
#endif