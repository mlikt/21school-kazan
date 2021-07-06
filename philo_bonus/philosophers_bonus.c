#include "philosophers_bonus.h"

void	status(sem_t *mt, int code, long unsigned int time, int n)
{
	sem_wait(mt);
	if (code == SLEEP)
		printf("%6lums, %4d) is sleeping\n", time, n);
	if (code == EAT)
		printf("%6lums, %4d) is eating\n", time, n);
	if (code == THINKING)
		printf("%6lums, %4d) is thinking\n", time, n);
	if (code == TAKE_FORK)
		printf("%6lums, %4d) has taken a fork\n", time, n);
	if (code == DEAD)
		printf("\e[31m""%6lums, %4d) dead\n""\e[00m", time, n);
	if (code == SLEEP || code == EAT || code == THINKING
		|| code == TAKE_FORK)
		sem_post(mt);
}

void	actions(t_philos	*ph)
{
	ph->limit = get_time() + ph->rule->time_of_die;
	while (1)
	{
		if (if_one(ph))
			break ;
		get_fork(ph);
		if (dead(ph))
			break ;
		ph->limit = get_time() + ph->rule->time_of_die;
		if (eating(ph))
			break ;
		put_fork(ph);
		if (sleeping(ph))
			break ;
		if (dead(ph))
			break ;
		status(ph->rule->sem_print, THINKING, get_time() - ph->timer->v, ph->n);
	}
}

void	close_child(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->number_of_philo)
	{
		kill(rule->ph[i].pid, SIGKILL);
		i++;
	}
	sem_unlink(FORK);
	sem_unlink(PRINT);
}

int	main(int argc, char **argv)
{
	t_rule	*rule;
	int		i;

	i = -1;
	if (valid_argv(argv))
		return (printf("ERROR!\n"));
	rule = init_rule(argv, argc);
	if (!rule || !rule->ph || !rule->ph->l_fork
		|| !rule->ph[0].timer)
		return (printf("ERROR!\n"));
	if (valid_rule(rule))
		return (printf("ERROR!\n"));
	rule->ph->timer->v = get_time();
	while (++i < rule->number_of_philo)
	{
		rule->ph[i].pid = fork();
		if (!rule->ph[i].pid)
		{
			actions(&rule->ph[i]);
			return (0);
		}
	}
	wait(0);
	close_child(rule);
	return (0);
}
