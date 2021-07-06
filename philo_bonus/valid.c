#include "philosophers_bonus.h"

int	valid_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!(*argv))
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_rule(t_rule *rule)
{
	if (rule->time_of_die <= 0 || rule->time_of_eat == 0U
		|| rule->time_of_sleep == 0U || rule->number_of_philo == 0U
		|| rule->number_of_eating == 0U)
		return (1);
	return (0);
}
