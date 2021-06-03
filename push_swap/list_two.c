#include "push_swap.h"

void	find_min_assign_order(t_list *list, unsigned int i)
{
	t_list	*tmp;
	int		buf;

	buf = list->nbr;
	tmp = list;
	while (tmp)
	{
		if (tmp->nbr < buf)
			buf = tmp->nbr;
		tmp = tmp->next;
	}
	while (list)
	{
		if (list->nbr == buf)
		{
			list->order = i;
			break ;
		}
		list = list->next;
	}
}

void	copy_order(t_list *dst, t_list *src, unsigned int i)
{
	while (src->order != i)
		src = src->next;
	while (dst->nbr != src->nbr)
		dst = dst->next;
	dst->order = src->order;
}

void	get_order(t_list *list)
{
	unsigned int	order;
	unsigned int	amount;
	t_list			*dup;

	order = 0;
	amount = count_elem(list);
	dup = duplicate(list);
	while (order < amount)
	{
		find_min_assign_order(dup, order);
		copy_order(list, dup, order);
		remove_elem(&dup, order);
		order++;
	}
}

unsigned int	find_max(t_list *list)
{
	unsigned int	max_order;

	max_order = list->order;
	while (list)
	{
		if (list->order > max_order)
			max_order = list->order;
		list = list->next;
	}
	return (max_order);
}

unsigned int	find_min(t_list *list)
{
	unsigned int	min_order;

	min_order = list->order;
	while (list)
	{
		if (list->order < min_order)
			min_order = list->order;
		list = list->next;
	}
	return (min_order);
}
