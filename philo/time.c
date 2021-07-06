#include "philosophers.h"

long unsigned int	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL));
}

void	smart_sleep(long unsigned int time)
{
	long unsigned int	t;

	t = get_time();
	while (get_time() - t < time)
	{
		usleep(50);
	}
}

void	if_one(t_philos *ph)
{
	long unsigned int	time;

	if (ph->rule->number_of_philo == 1)
	{
		time = get_time() - ph->timer->v;
		status(&ph->rule->mt_print, TAKE_FORK, time, ph->n);
		supervision(ph->rule->time_of_die + 10, ph);
	}
}

void	supervision(long unsigned int time, t_philos *ph)
{
	long unsigned int	i;

	i = 0;
	while (i < time)
	{
		dead(ph);
		smart_sleep(1);
		i++;
	}
}
