#include "push_swap.h"

void	two(t_list **list, int tumb)
{
	if ((*list)->order > (*list)->next->order && tumb)
		sa(list);
	if ((*list)->order < (*list)->next->order && !tumb)
		sb(list);
}

void	three(t_list **A)
{
	unsigned int	order;
	unsigned int	dist;

	order = find_max(*A);
	dist = dist_from_start(*A, order);
	if (dist == 1)
		rra(A);
	else if (dist == 0)
		ra(A);
	two(A, 1);
}

void	four(t_list **A)
{
	unsigned int	order;
	unsigned int	dist;
	t_list			*B;

	B = NULL;
	order = find_min(*A);
	dist = dist_from_start(*A, order);
	if (dist > 1)
	{
		while (order != (*A)->order)
			rra(A);
		pb(A, &B);
	}
	else
	{
		while (order != (*A)->order)
			ra(A);
		pb(A, &B);
	}
	three(A);
	pa(A, &B);
}

void	five(t_list **A)
{
	unsigned int	order;
	unsigned int	dist;
	t_list			*B;

	B = NULL;
	order = find_min(*A);
	dist = dist_from_start(*A, order);
	if (dist > 2)
	{
		while (order != (*A)->order)
			rra(A);
		pb(A, &B);
	}
	else
	{
		while (order != (*A)->order)
			ra(A);
		pb(A, &B);
	}
	four(A);
	pa(A, &B);
}

void	sort_small_list(t_list **A, unsigned int count)
{
	if (count == 3)
		three(A);
	if (count == 5)
		five(A);
	if (count == 2)
		two(A, 1);
	if (count == 4)
		four(A);
}
