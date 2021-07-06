#ifndef PHILOSOPHERS_H
# define	PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include "utils.h"
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
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philos
{
	int						n;
	int						eat;
	long unsigned int		limit;
	t_fork					*l_fork;
	t_fork					*r_fork;
	pthread_t				tid;
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
	pthread_mutex_t				mt_print;
	t_philos					*ph;
}				t_rule;

t_rule	*init_rule(char **argv, int argc);
void	smart_sleep(long unsigned int time);
void	if_one(t_philos *ph);
void	supervision(long unsigned int time, t_philos *ph);
void	dead(t_philos *ph);
void	get_fork(t_philos *ph);
void	eating(t_philos *ph);
void	put_fork(t_philos *ph);
void	sleeping(t_philos *ph);
void	status(pthread_mutex_t *mt, int code, long unsigned int time, int n);
int		break_simulation(t_rule *rule);
int		valid_argv(char **argv);
int		valid_rule(t_rule *rule);
#endif