#include "philosophers.h"

void	status(pthread_mutex_t *mt, int code, long unsigned int time, int n)
{
	pthread_mutex_lock(mt);
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
		pthread_mutex_unlock(mt);
}

void	*actions(void *philos_ptr)
{
	t_philos	*ph;

	ph = (t_philos *)philos_ptr;
	ph->limit = get_time() + ph->rule->time_of_die;
	if_one(ph);
	while (1)
	{
		get_fork(ph);
		dead(ph);
		ph->limit = get_time() + ph->rule->time_of_die;
		eating(ph);
		put_fork(ph);
		sleeping(ph);
		dead(ph);
		status(&ph->rule->mt_print, THINKING, get_time() - ph->timer->v, ph->n);
	}
	return (NULL);
}

void	go_simulation(t_rule *rule)
{
	int			i;
	t_philos	*ph;

	i = 0;
	ph = rule->ph;
	ph->timer->v = get_time();
	while (i < rule->number_of_philo)
	{
		pthread_create(&ph[i].tid, NULL, actions, &ph[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rule	*rule;
	int		i;

	i = 0;
	if (valid_argv(argv))
		return (printf("ERROR!\n"));
	rule = init_rule(argv, argc);
	if (!rule || !rule->ph || !rule->ph->l_fork
		|| !rule->ph[0].timer)
		return (printf("ERROR!\n"));
	if (valid_rule(rule))
		return (printf("ERROR!\n"));
	go_simulation(rule);
	while (break_simulation(rule))
		usleep(50);
	while (i < rule->number_of_philo)
	{
		pthread_detach(rule->ph[i].tid);
		i++;
	}
	return (0);
}
