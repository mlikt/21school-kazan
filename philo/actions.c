#include "philosophers.h"

void	dead(t_philos *ph)
{
	if (ph->limit < get_time())
	{
		status(&ph->rule->mt_print, DEAD, get_time() - ph->timer->v, ph->n);
		ph->rule->fix_dead = 1;
	}
}

void	get_fork(t_philos *ph)
{
	if (ph->n < ph->rule->number_of_philo)
	{
		pthread_mutex_lock(&ph->l_fork->mutex);
		pthread_mutex_lock(&ph->r_fork->mutex);
	}
	else
	{
		pthread_mutex_lock(&ph->r_fork->mutex);
		pthread_mutex_lock(&ph->l_fork->mutex);
	}
	status(&ph->rule->mt_print, TAKE_FORK, get_time() - ph->timer->v, ph->n);
	status(&ph->rule->mt_print, TAKE_FORK, get_time() - ph->timer->v, ph->n);
}

void	eating(t_philos *ph)
{
	status(&ph->rule->mt_print, EAT, get_time() - ph->timer->v, ph->n);
	ph->eat++;
	if (ph->eat == ph->rule->number_of_eating)
		ph->rule->fix_eat++;
	supervision(ph->rule->time_of_eat, ph);
}

void	put_fork(t_philos *ph)
{
	pthread_mutex_unlock(&ph->l_fork->mutex);
	pthread_mutex_unlock(&ph->r_fork->mutex);
}

void	sleeping(t_philos *ph)
{
	status(&ph->rule->mt_print, SLEEP, get_time() - ph->timer->v, ph->n);
	supervision(ph->rule->time_of_sleep, ph);
}
