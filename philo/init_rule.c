#include "philosophers.h"

void	lay_forks(int i, t_philos *ph, t_fork *fork, int count)
{
	if (i < count)
	{
		ph[i - 1].l_fork = &fork[i - 1];
		ph[i - 1].r_fork = &fork[i];
	}
	else
	{
		ph[i - 1].l_fork = &fork[i - 1];
		ph[i - 1].r_fork = &fork[0];
	}
}

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

t_philos	*init_philos(int count, t_rule *rule)
{
	t_fork		*fork;
	t_philos	*ph;
	int			i;

	i = 1;
	ph = malloc(sizeof(t_philos) * count);
	if (!ph)
		return (NULL);
	fork = malloc(sizeof(t_fork) * count);
	if (!fork)
		return (NULL);
	ph[0].timer = init_timer(rule);
	while (i <= count)
	{
		ph[i - 1].n = i;
		ph[i - 1].timer = ph[0].timer;
		ph[i - 1].eat = 0;
		pthread_mutex_init(&fork[i - 1].mutex, NULL);
		ph[i - 1].rule = rule;
		lay_forks(i, ph, fork, count);
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
	pthread_mutex_init(&rule->mt_print, NULL);
	rule->ph = init_philos(rule->number_of_philo, rule);
	return (rule);
}
