#include "push_swap.h"

int	check_sort(t_list *list, int direction)
{
	while (list->next)
	{
		if (direction == 1)
		{
			if (list->nbr > list->next->nbr)
				return (0);
		}
		else if (direction == -1)
		{
			if (list->nbr < list->next->nbr)
				return (0);
		}
		else
			return (-1);
		list = list->next;
	}
	return (1);
}

void	sort(t_list **A)
{
	t_list			*B;
	unsigned int	order;
	unsigned int	count;
	unsigned int	j;
	unsigned int	i;

	i = 0;
	B = NULL;
	count = count_elem(*A);
	while (!check_sort(*A, 1) && !B)
	{	
		j = 0;
		while (j < count)
		{
			order = (*A)->order;
			if (((order >> i) & 1))
				ra(A);
			else
				pb(A, &B);
			++j;
		}
		while (B)
			pa(A, &B);
		++i;
	}
}

int	dist_from_start(t_list *list, unsigned int order)
{
	unsigned int	i;

	i = 0;
	while (order != list->order)
	{
		i++;
		list = list->next;
	}
	return (i);
}
