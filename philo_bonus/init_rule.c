#include "philosophers_bonus.h"

t_timer	*init_timer(t_rule *rule)
{
	t_timer		*timer;

	timer = malloc(sizeof(t_timer));
	if (!timer)
		return (NULL);
	timer->v = 0;
	timer->rule = rule;
	return (timer);
}

void	init_sem(t_fork *fork, t_rule *rule)
{
	sem_unlink(FORK);
	sem_unlink(PRINT);
	fork->sem = sem_open(FORK, O_CREAT, 0777, rule->number_of_philo);
	rule->sem_print = sem_open(PRINT, O_CREAT, 0777, 1);
}

t_philos	*init_philos(int count, t_rule *rule)
{
	t_fork		*fork;
	t_philos	*ph;
	int			i;

	i = 0;
	ph = malloc(sizeof(t_philos) * count);
	if (!ph)
		return (NULL);
	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	init_sem(fork, rule);
	ph[0].timer = init_timer(rule);
	while (i < count)
	{
		ph[i].n = i + 1;
		ph[i].timer = ph[0].timer;
		ph[i].eat = 0;
		ph[i].rule = rule;
		ph[i].l_fork = fork;
		ph[i].r_fork = fork;
		i++;
	}	
	return (ph);
}

t_rule	*init_rule(char **argv, int argc)
{
	t_rule	*rule;

	if (argc < 5 || argc > 6)
		return (NULL);
	rule = malloc(sizeof(t_rule));
	if (!rule)
		return (NULL);
	rule->number_of_philo = ft_atoi(argv[1]);
	rule->time_of_die = ft_atoi(argv[2]);
	rule->time_of_eat = ft_atoi(argv[3]);
	rule->time_of_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rule->number_of_eating = ft_atoi(argv[5]);
	else
		rule->number_of_eating = -1;
	rule->fix_dead = 0;
	rule->fix_eat = 0;
	rule->ph = init_philos(rule->number_of_philo, rule);
	return (rule);
}
