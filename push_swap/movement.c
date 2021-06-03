#include "push_swap.h"

t_list	*last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	swap(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = (*list)->next;
		if ((*list)->next)
		{
			if ((*list)->next->next)
				(*list)->next->next->prev = (*list);
			(*list)->next = tmp->next;
			tmp->prev = (*list)->prev;
			(*list)->prev = tmp;
			tmp->next = (*list);
			*list = tmp;
		}
	}
}

void	rotate_revers(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = last_elem(*list);
		tmp->prev->next = NULL;
		(*list)->prev = tmp;
		tmp->next = (*list);
		tmp->prev = NULL;
		(*list) = tmp;
	}
}

void	rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*last;

	if (*list)
	{
		last = last_elem(*list);
		tmp = (*list)->next;
		(*list)->next->prev = NULL;
		(*list)->next = NULL;
		last->next = (*list);
		(*list)->prev = last;
		*list = tmp;
	}
}

void	push(t_list **rec, t_list **src)
{
	t_list	*buf;

	buf = *src;
	if (*src)
	{
		if ((*src)->next)
		{
			*src = (*src)->next;
			(*src)->prev = NULL;
		}
		else
			*src = NULL;
		buf->next = NULL;
		if (!*rec)
			*rec = buf;
		else
		{
			(*rec)->prev = buf;
			buf->next = *rec;
			*rec = buf;
		}
	}
}
