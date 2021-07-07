#include "philosophers_bonus.h"

int	dead(t_philos *ph)
{
	if (ph->limit < get_time())
	{
		status(ph->rule->sem_print, DEAD, get_time() - ph->timer->v, ph->n);
		return (1);
	}
	return (0);
}

void	get_fork(t_philos *ph)
{
	sem_wait(ph->l_fork->sem);
	sem_wait(ph->r_fork->sem);
	status(ph->rule->sem_print, TAKE_FORK, get_time() - ph->timer->v, ph->n);
	status(ph->rule->sem_print, TAKE_FORK, get_time() - ph->timer->v, ph->n);
}

int	eating(t_philos *ph)
{
	int	fix;

	status(ph->rule->sem_print, EAT, get_time() - ph->timer->v, ph->n);
	ph->eat++;
	if (ph->n == ph->rule->number_of_philo && ph->eat == ph->rule->number_of_eating)
		return (1);
	fix = supervision(ph->rule->time_of_eat, ph);
	return (fix);
}

void	put_fork(t_philos *ph)
{
	sem_post(ph->l_fork->sem);
	sem_post(ph->r_fork->sem);
}

int	sleeping(t_philos *ph)
{
	int	fix;

	status(ph->rule->sem_print, SLEEP, get_time() - ph->timer->v, ph->n);
	fix = supervision(ph->rule->time_of_sleep, ph);
	return (fix);
}
